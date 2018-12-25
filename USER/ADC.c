//#include "adc.h"  
//  
//__IO uint16_t ADCConvertedValue[100]; 
//#define ADC1_DR_Address    ((uint32_t)0x4001244C)
//  
////函数  
////初始化AD  
//void Adc_Init(void)  
//{  
//    ADC_InitTypeDef ADC_InitStructure;  
//    DMA_InitTypeDef DMA_InitStructure;  
//    GPIO_InitTypeDef GPIO_InitStructure;  
//  
//    //---------------------充电AD初始化--------------------  
//    //启动DMA时钟  
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
//  
//    //启动ADC1时钟  
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);  
//  
//    //采样脚设置  
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;//| GPIO_Pin_1;  
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;  
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  
//    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;  
//    //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING;  
//   // GPIO_Init(GPIOC, &GPIO_InitStructure);  

//	//EXTI_Configuration();
//  
//    //DMA1通道1配置  
//    DMA_DeInit(DMA1_Channel1);  
//    //外设地址  
//    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;  
//    //内存地址  
//    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCConvertedValue;  
//    //dma传输方向单向  
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  
//    //设置DMA在传输时缓冲区的长度  
//    DMA_InitStructure.DMA_BufferSize = 100;  
//    //设置DMA的外设递增模式，一个外设  
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  
//    //设置DMA的内存递增模式  
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  
//    //外设数据字长  
//    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  
//    //内存数据字长  
//    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;  
//    //设置DMA的传输模式：连续不断的循环模式  
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  
//    //设置DMA的优先级别  
//    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  
//    //设置DMA的2个memory中的变量互相访问  
//    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  
//    DMA_Init(DMA1_Channel1, &DMA_InitStructure);  
//      
//    //使能通道1  
//    DMA_Cmd(DMA1_Channel1, ENABLE);  
//  
//    //ADC1配置  
//    //独立工作模式  
//    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  
//    //扫描方式  
//    ADC_InitStructure.ADC_ScanConvMode = ENABLE;  
//    //连续转换  
//    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;  
//    //外部触发禁止  
//    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;  
//	//ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO;
//    //数据右对齐  
//    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  	
//    //用于转换的通道数  
//    ADC_InitStructure.ADC_NbrOfChannel = 1;  
//    ADC_Init(ADC1, &ADC_InitStructure);  
//      
//    //规则模式通道配置  
//    ADC_RegularChannelConfig(ADC1, ADC_Channel_0 , 1, ADC_SampleTime_239Cycles5);  
//    //ADC_RegularChannelConfig(ADC1, ADC_Channel_1 , 2, ADC_SampleTime_239Cycles5);
//	
//	//ADC_ExternalTrigInjectedConvConfig(ADC1, ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4);
//  /* Enable ADC1 injected external trigger conversion */
//  //ADC_ExternalTrigInjectedConvCmd(ADC1, ENABLE);

//  /* Enable JEOC interrupt */
//  //ADC_ITConfig(ADC1, ADC_IT_JEOC, ENABLE);  
//	 Ad_Start();     
//} 


//void Ad_Start(void)
//{
//    ADC_DMACmd(ADC1, ENABLE);  
//       
//    ADC_Cmd(ADC1, ENABLE);  
//        
//    ADC_ResetCalibration(ADC1);  
//	 
//    while(ADC_GetResetCalibrationStatus(ADC1));  
//      
//    
//    ADC_StartCalibration(ADC1);  
//    
//    while(ADC_GetCalibrationStatus(ADC1));  
//       
//     
//    ADC_SoftwareStartConvCmd(ADC1, ENABLE);  
//}
//  
////获得TEST0 
//u16 voltage_TEST0(void)  
//{  
//    uint8_t i = 0;  
//    uint32_t sum = 0;  
//    float v = 0;     
//    for (i = 0;i < 100;i++)  
//    {  
//        sum +=ADCConvertedValue[i ];   
//    }  
//    sum /= 100;  
//	//sum= ADCConvertedValue[48];
//    v = sum*3306/4096;  
//    return v;  
//}  
//  
////获得TEST1 
//u16 voltage_TEST1(void)  
//{  
//    uint8_t i = 0;  
//    uint32_t sum = 0;  
//    float v = 0;    
//    for (i = 0;i < 50;i++)  
//    {  
//        sum += ADCConvertedValue[i * 2 + 1];   
//    }  
//    sum /= 50;  
//   
//    //v = sum*3306/4096;  
//    return sum;  
//} 
   #include "adc.h"
 //#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 

//STM32F103ZE核心板
//ADC 代码	   
							  
////////////////////////////////////////////////////////////////////////////////// 
	   
		   
//初始化ADC
//这里我们仅以规则通道为例
//我们默认将开启通道0~3																	   
void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟
 

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M

	//PA1 作为模拟通道输入引脚                         
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	ADC_DeInit(ADC1);  //复位ADC1 

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   

  
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	
	ADC_ResetCalibration(ADC1);	//使能复位校准  
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	
	ADC_StartCalibration(ADC1);	 //开启AD校准
 
	while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束
 
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能

}				  
//获得ADC值
//ch:通道值 0~3
u16 Get_Adc(u8 ch)   
{
  	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
}

u16 Get_Adc_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
		//delay_ms(5);
		delay_ms(50);
	}
	return temp_val/times;
} 	 



























