/***************************************************************************************
 * 描述    ：W5500的端口0工作在客户端模式,主动与《TCP&UDP测试工具》上创建的服务端连接,
 *			
 * 实验平台：用户STM32开发板 + YIXIN_W5500以太网(TCP/IP)模块
 * 硬件连接：  PC5 -> W5500_RST       
 *             PA4 -> W5500_SCS      
 *             PA5 -> W5500_SCK    
 *             PA6 -> W5500_MISO    
 *             PA7 -> W5500_MOSI    
 * 库版本  ：ST_v3.5

***************************************************************************************/

/*例程网络参数*/
//网关：192.168.1.1
//掩码:	255.255.255.0

//物理地址：0C 29 AB 7C 00 01
//本机MCU 的IP地址:192.168.1.199
//端口0的端口号：5000

//电脑端口0的目的IP地址：192.168.1.190
//端口0的目的端口号：6000

#include "stm32f10x.h"		
#include "W5500.h"			
#include <string.h>
#include <Delaypoint.h>
#include <TaskDelayExter.h>
#include <Key.h>
#include  <led.h>
#include "usart.h"
#include "ADC.h"
#include "Select4051.h"
#include "Alldata.h"
//#include <Timer2.h>

void RCC_Configuration(void);		//设置系统时钟为72MHZ(这个可以根据需要改)
void NVIC_Configuration(void);		//STM32中断向量表配配置
void Timer2_Init_Config(void);		//Timer2初始化配置
void System_Initialization(void);	//STM32系统初始化函数(初始化STM32时钟及外设)
//void Delay(unsigned int d);			//延时函数(ms)
extern void LED_Init(void);
unsigned int Timer2_Counter=0; //Timer2定时器计数变量(ms)
unsigned int W5500_Send_Delay_Counter=0; //W5500发送延时计数变量(ms)
unsigned char BuffSprintf[10]; 
int test_point1=54,test_point2=54;
int test_setPin =1;

/*******************************************************************************
* 函数名  : W5500_Initialization
* 描述    : W5500初始货配置
* 输入    : 无
* 输出    : 无
* 返回值  : 无
* 说明    : 无
*******************************************************************************/
void W5500_Initialization(void)
{
	W5500_Init();		//初始化W5500寄存器函数
	Detect_Gateway();	//检查网关服务器 
	Socket_Init(0);		//指定Socket(0~7)初始化,初始化端口0
}

/*******************************************************************************
* 函数名  : Load_Net_Parameters
* 描述    : 装载网络参数
* 输入    : 无
* 输出    : 无
* 返回值  : 无
* 说明    : 网关、掩码、物理地址、本机IP地址、端口号、目的IP地址、目的端口号、端口工作模式
*******************************************************************************/
void Load_Net_Parameters(void)
{
	Gateway_IP[0] = 192;//加载网关参数
	Gateway_IP[1] = 168;
	Gateway_IP[2] = 1;
	Gateway_IP[3] = 1;

	Sub_Mask[0]=255;//加载子网掩码
	Sub_Mask[1]=255;
	Sub_Mask[2]=255;
	Sub_Mask[3]=0;

	Phy_Addr[0]=0x0c;//加载物理地址
	Phy_Addr[1]=0x29;
	Phy_Addr[2]=0xab;
	Phy_Addr[3]=0x7c;
	Phy_Addr[4]=0x00;
	Phy_Addr[5]=0x01;

	IP_Addr[0]=192;//加载本机IP地址
	IP_Addr[1]=168;
	IP_Addr[2]=1;
	IP_Addr[3]=199;

	S0_Port[0] = 0x13;//加载端口0的端口号5000 
	S0_Port[1] = 0x88;

	S0_DIP[0]=192;//加载端口0的目的IP地址
	S0_DIP[1]=168;
	S0_DIP[2]=1;
	S0_DIP[3]=190;
	
	S0_DPort[0] = 0x17;//加载端口0的目的端口号6000
	S0_DPort[1] = 0x70;

	S0_Mode=TCP_CLIENT;//加载端口0的工作模式,TCP客户端模式
}

/*******************************************************************************
* 函数名  : W5500_Socket_Set
* 描述    : W5500端口初始化配置
* 输入    : 无
* 输出    : 无
* 返回值  : 无
* 说明    : 分别设置4个端口,根据端口工作模式,将端口置于TCP服务器、TCP客户端或UDP模式.
*			从端口状态字节Socket_State可以判断端口的工作情况
*******************************************************************************/
void W5500_Socket_Set(void)
{
	if(S0_State==0)//端口0初始化配置
	{
		if(S0_Mode==TCP_SERVER)//TCP服务器模式 
		{
			if(Socket_Listen(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else if(S0_Mode==TCP_CLIENT)//TCP客户端模式 
		{
			if(Socket_Connect(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else//UDP模式 
		{
			if(Socket_UDP(0)==TRUE)
				S0_State=S_INIT|S_CONN;
			else
				S0_State=0;
		}
	}
}

/*******************************************************************************
* 函数名  : Process_Socket_Data
* 描述    : W5500接收并发送接收到的数据
* 输入    : s:端口号
* 输出    : 无
* 返回值  : 无
* 说明    : 本过程先调用S_rx_process()从W5500的端口接收数据缓冲区读取数据,
*			然后将读取的数据从Rx_Buffer拷贝到Temp_Buffer缓冲区进行处理。
*			处理完毕，将数据从Temp_Buffer拷贝到Tx_Buffer缓冲区。调用S_tx_process()
*			发送数据。
*******************************************************************************/
void Process_Socket_Data(SOCKET s)
{
	unsigned short size;
	size=Read_SOCK_Data_Buffer(s, Rx_Buffer);
	memcpy(Tx_Buffer, Rx_Buffer, size);			
	Write_SOCK_Data_Buffer(s, Tx_Buffer, size);
}
//int strcpmSelf(char *point )
//{

//}
void usart(void)
{
	    
	   int h;	
	  
	    //char buff[5] ={'R','S','T','\0'};
		if(USART_RX_STA&0x8000)
		{					   
			
//			printf("\r\n send:  ");
//			for(t=0;t< reciveNum;t++)
//			{
//				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
//				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
//				
//			}
//			printf("\r\n send:  ");
//			 USART_RX_BUF[reciveNum] ='\r';
//			 USART_RX_BUF[reciveNum+1] ='\n';
//			USART_RX_BUF[reciveNum+2] ='\0';
//			for(t=0;t< reciveNum+4;t++)
//			{
//				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
//				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
//				
//			}
//			sprintf( BuffSprintf,"(%d)", reciveNum );
//			printf(BuffSprintf);
			//if(reciveNum == 3)
			{
			   if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 't'&& USART_RX_BUF[2] == 'a' && USART_RX_BUF[3] == 'r' && USART_RX_BUF[4] == 't'&& USART_RX_BUF[5] == '\r')
				{
					Key1.KeyShortDown_F =1;
					g_sem_put_ok =1;
				}
				if(USART_RX_BUF[0] == 'r' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 's' && USART_RX_BUF[3] == 'e' && USART_RX_BUF[4] == 't'&& USART_RX_BUF[5] == '\r')
				{
					Key2.KeyShortDown_F =1;
				}
				if(USART_RX_BUF[0] == 't' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 's' && USART_RX_BUF[3] == 't' && USART_RX_BUF[4] == '\r'&& USART_RX_BUF[5] == '\n')
				{
				    Key5.KeyShortDown_F =1;
					printf("jj");
				}
				if(USART_RX_BUF[0] == 'A' && USART_RX_BUF[1] == 'N'&& USART_RX_BUF[2] == 'I' )
				{
					
					SetPinDelay(test_point1++,test_point2++);
				}
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'e')
				{

					Key4.KeyShortDown_F =1;
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'f')
				{

					f_putLong =1000;
					printf("set the put long");
					
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'g')
				{
                  test_setPin ++;
                  test4051(test_setPin);
				 
					
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'h')
				{
                  test_setPin --;
                  test4051(test_setPin);
				  
					
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'i')
				{
                  test4051_closeY(test_setPin,h);
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'j')
				{
                  test4051_closeY(test_setPin,h);
					
				} 
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'k')
				{
                   GPIO_ResetBits(GPIOB,GPIO_Pin_5);
				   printf("set gpiob5 to 0");
					
				}
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'c'&& USART_RX_BUF[2] == 'a')
				{
                  scanEveryPointBySelect(1,50);
					
				}
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'c'&& USART_RX_BUF[2] == 'b')
				{
                  scanEveryPointBySelect(51,100);
					
				}
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'c'&& USART_RX_BUF[2] == 'c')
				{
                 scanEveryPointBySelect(101,150);
					
				}
				if(USART_RX_BUF[0] == 's' && USART_RX_BUF[1] == 'c'&& USART_RX_BUF[2] == 'd')
				{
                 scanEveryPointBySelect(151,200);
					
				}
				if(USART_RX_BUF[0] == 'a' && USART_RX_BUF[1] == 'd'&& USART_RX_BUF[2] == 'd'&& USART_RX_BUF[3] == '2'&& USART_RX_BUF[4] == '0' )
				{
				  printf("it was work");
					test_setPin +=20;
				}
				if(strcmp(USART_RX_BUF,"findGnd\r\n")==0)
				{
				 findGND(8,100,23);
				}
				if(strcmp(USART_RX_BUF,"SCANSignal_1\r\n")==0)
				{
					printf("scansignal_1");
				    printfSignal(J7A_gnd);
				} 
				 if(strcmp(USART_RX_BUF,"xfindgnd\r\n")==0)
				{
					
				  XfindGND(8,100,21);
				}
				 if(strcmp(USART_RX_BUF,"xfindSignal\r\n")==0)
				{
					
				  scanSignalLineByPoint(J7Y_signalTestpoint);
				}
				  if(USART_RX_BUF[0] == 'j' && USART_RX_BUF[1] == '7'&& USART_RX_BUF[2] == 'a' )
				{
					
				  testj7a_j1a();
				} 
				if(USART_RX_BUF[0] == 'd' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 'b' && USART_RX_BUF[3] == 'u'&& USART_RX_BUF[4] == 'g')
				{
					
				    debugPrintfEachTime =0;
					printf("set debug 0\r\n");
				}
				if(USART_RX_BUF[0] == 'j' && USART_RX_BUF[1] == '7'&& USART_RX_BUF[2] == 'b' )
				{
					printf("testj7b\r\n");
					TESTPEER("J7A","J1A",J7Adata,J7AGND);
				    TESTPEER("J7B","J1B",J7Bdata,J7BGND);   
					
					TESTPEER("J6A","U1A",J6Adata,J6AGND);
					TESTPEER("J6B","U1B",J6Bdata,J6BGND);
				} 	
				if(USART_RX_BUF[0] == 'r' && USART_RX_BUF[1] == 'e'&& USART_RX_BUF[2] == 't' && USART_RX_BUF[3] == 'u'&& USART_RX_BUF[4] == 'n')
				{
					
					returnOR =0; 
					printf("set returnor =0\r\n");
				} 	
				if(USART_RX_BUF[0] == 'j' && USART_RX_BUF[1] == '6'&& USART_RX_BUF[2] == 'a' )
				{
					printf("testj6a\r\n");
				    testj6A_U1A();   
				} 
				//printf("\r\n");//插入换行
			}
			
			USART_RX_STA=0;
		}

}
 void AnalyzeCommand(void)
 {
//	unsigned short size =0; 
//	unsigned char *command ="hello\0"; 
//    size=Read_SOCK_Data_Buffer(0, Rx_Buffer);
//	memcpy(AnalyzeBuff, Rx_Buffer, size);
//	 AnalyzeBuff[size] ='\0';
//	 if(strcmp(AnalyzeBuff, command)==0)
//	 {
//	   Key3.KeyShortDown_F =1;
//	 }
//	 
 
 }
/*******************************************************************************
* 函数名  : main
* 描述    : 主函数，用户程序从main函数开始运行
* 输入    : 无
* 输出    : 无
* 返回值  : int:返回值为一个16位整形数
* 说明    : 无
*******************************************************************************/
int main(void)
{
	System_Initialization();	//STM32系统初始化函数(初始化STM32时钟及外设)
	uart_init(9600);	 //串口初始化为115200
	LED_Init();
	Adc_Init();
	InitKey();
	InitTaskStr();
	//IWDG_Init(4,625);
     
	Key2.KeyShortDown_F =1;
	printf("\r\n start version 3!\r\n");

	while (1)
	{
		ServeDelay();
	
		KeyServe();
		Task3(&F_DelayStr_Exam3,&Task3Infor,&Key3);

		//Task11(&F_DelayStr_Exam11,&Task11Infor);
		usart();
		Task1(&F_DelayStr_Exam1,&Task1Infor,&Key1);
		Task2(&F_DelayStr_Exam2,&Task2Infor,&Key2);
		Task4(&F_DelayStr_Exam4,&Task4Infor,&Key4); //
		Task5(&F_DelayStr_Exam5,&Task5Infor,&Key5); //
		//Task10(&F_DelayStr_Exam10,&Task10Infor,&Key6); //
	}
}

/*******************************************************************************
* 函数名  : RCC_Configuration
* 描述    : 设置系统时钟为72MHZ(这个可以根据需要改)
* 输入    : 无
* 输出    : 无
* 返回值  : 无
* 说明    : STM32F107x和STM32F105x系列MCU与STM32F103x系列MCU时钟配置有所不同
*******************************************************************************/
void RCC_Configuration(void)
{
  ErrorStatus HSEStartUpStatus;               //外部高速时钟(HSE)的工作状态变量
  
  RCC_DeInit();                               //将所有与时钟相关的寄存器设置为默认值
  RCC_HSEConfig(RCC_HSE_ON);                  //启动外部高速时钟HSE 
  HSEStartUpStatus = RCC_WaitForHSEStartUp(); //等待外部高速时钟(HSE)稳定

  if(SUCCESS == HSEStartUpStatus)             //如果外部高速时钟已经稳定
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); //Flash设置
    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
    
  
    RCC_HCLKConfig(RCC_SYSCLK_Div1); //设置AHB时钟等于系统时钟(1分频)/72MHZ
    RCC_PCLK2Config(RCC_HCLK_Div1);  //设置APB2时钟和HCLK时钟相等/72MHz(最大为72MHz)
    RCC_PCLK1Config(RCC_HCLK_Div2);  //设置APB1时钟是HCLK时钟的2分频/36MHz(最大为36MHz)
  
#ifndef STM32F10X_CL                 //如果使用的不是STM32F107x或STM32F105x系列MCU,PLL以下配置  
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); //PLLCLK = 8MHz * 9 = 72 MHz 
#else                                //如果使用的是STM32F107x或STM32F105x系列MCU,PLL以下配置
    /***** 配置PLLx *****/
    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    RCC_PREDIV2Config(RCC_PREDIV2_Div5);
    RCC_PLL2Config(RCC_PLL2Mul_8);

    RCC_PLL2Cmd(ENABLE); //使能PLL2 
    while (RCC_GetFlagStatus(RCC_FLAG_PLL2RDY) == RESET);//等待PLL2稳定

    /* PLL configuration: PLLCLK = (PLL2 / 5) * 9 = 72 MHz */ 
    RCC_PREDIV1Config(RCC_PREDIV1_Source_PLL2, RCC_PREDIV1_Div5);
    RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);
#endif

    RCC_PLLCmd(ENABLE); //使能PLL
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //等待PLL稳定

    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);          //设置系统时钟的时钟源为PLL

    while(RCC_GetSYSCLKSource() != 0x08);               //检查系统的时钟源是否是PLL
    RCC_ClockSecuritySystemCmd(ENABLE);                 //使能系统安全时钟 

	/* Enable peripheral clocks --------------------------------------------------*/
  	/* Enable I2C1 and I2C1 clock */
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  	/* Enable GPIOA GPIOB SPI1 and USART1 clocks */
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB
					| RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD
					| RCC_APB2Periph_AFIO, ENABLE);    
  }
}

/*******************************************************************************
* 函数名  : NVIC_Configuration
* 描述    : STM32中断向量表配配置
* 输入    : 无
* 输出    : 无
* 返回值  : 无
* 说明    : 设置KEY1(PC11)的中断优先组
*******************************************************************************/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;						//定义NVIC初始化结构体

  	/* Set the Vector Table base location at 0x08000000 */
  	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//设置中断优先级组为1，优先组(可设0～4位)
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//设置中断向量号
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//设置抢先优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//设置响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能NVIC
	NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* 函数名  : Timer2_Init_Config
* 描述    : Timer2初始化配置
* 输入    : 无
* 输出    : 无
* 返回    : 无 
* 说明    : 无
*******************************************************************************/
void Timer2_Init_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);		//使能Timer2时钟
	
	TIM_TimeBaseStructure.TIM_Period = 9;						//设置在下一个更新事件装入活动的自动重装载寄存器周期的值(计数到10为1ms)
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;					//设置用来作为TIMx时钟频率除数的预分频值(10KHz的计数频率)
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//设置时钟分割:TDTS = TIM_CKD_DIV1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);				//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	 
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE ); 				//使能TIM2指定的中断
	
	TIM_Cmd(TIM2, ENABLE);  									//使能TIMx外设
}

/*******************************************************************************
* 函数名  : TIM2_IRQHandler
* 描述    : 定时器2中断断服务函数
* 输入    : 无
* 输出    : 无
* 返回    : 无 
* 说明    : 无
*******************************************************************************/
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		Timer2_Counter++;
		//W5500_Send_Delay_Counter++;
		G_TimerCnt_DelayServe_10MS++;
		G_TimerCnt_KeyServe_10MS ++;
	}
}

/*******************************************************************************
* 函数名  : System_Initialization
* 描述    : STM32系统初始化函数(初始化STM32时钟及外设)
* 输入    : 无
* 输出    : 无
* 返回    : 无 
* 说明    : 无
*******************************************************************************/
void System_Initialization(void)
{
	RCC_Configuration();		//设置系统时钟为72MHZ(这个可以根据需要改)
  	NVIC_Configuration();		//STM32中断向量表配配置
	SPI_Configuration();		//W5500 SPI初始化配置(STM32 SPI1)
	Timer2_Init_Config();		//Timer2初始化配置
	W5500_GPIO_Configuration();	//W5500 GPIO初始化配置	
}

/*******************************************************************************
* 函数名  : Delay
* 描述    : 延时函数(ms)
* 输入    : d:延时系数，单位为毫秒
* 输出    : 无
* 返回    : 无 
* 说明    : 延时是利用Timer2定时器产生的1毫秒的计数来实现的
*******************************************************************************/
void Delay(unsigned int d)
{
	Timer2_Counter=0; 
	while(Timer2_Counter < d);
}
