//#include "adc.h"  
//  
//__IO uint16_t ADCConvertedValue[100]; 
//#define ADC1_DR_Address    ((uint32_t)0x4001244C)
//  
////����  
////��ʼ��AD  
//void Adc_Init(void)  
//{  
//    ADC_InitTypeDef ADC_InitStructure;  
//    DMA_InitTypeDef DMA_InitStructure;  
//    GPIO_InitTypeDef GPIO_InitStructure;  
//  
//    //---------------------���AD��ʼ��--------------------  
//    //����DMAʱ��  
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);  
//  
//    //����ADC1ʱ��  
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);  
//  
//    //����������  
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
//    //DMA1ͨ��1����  
//    DMA_DeInit(DMA1_Channel1);  
//    //�����ַ  
//    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;  
//    //�ڴ��ַ  
//    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCConvertedValue;  
//    //dma���䷽����  
//    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  
//    //����DMA�ڴ���ʱ�������ĳ���  
//    DMA_InitStructure.DMA_BufferSize = 100;  
//    //����DMA���������ģʽ��һ������  
//    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  
//    //����DMA���ڴ����ģʽ  
//    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  
//    //���������ֳ�  
//    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  
//    //�ڴ������ֳ�  
//    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;  
//    //����DMA�Ĵ���ģʽ���������ϵ�ѭ��ģʽ  
//    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;  
//    //����DMA�����ȼ���  
//    DMA_InitStructure.DMA_Priority = DMA_Priority_High;  
//    //����DMA��2��memory�еı����������  
//    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  
//    DMA_Init(DMA1_Channel1, &DMA_InitStructure);  
//      
//    //ʹ��ͨ��1  
//    DMA_Cmd(DMA1_Channel1, ENABLE);  
//  
//    //ADC1����  
//    //��������ģʽ  
//    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  
//    //ɨ�跽ʽ  
//    ADC_InitStructure.ADC_ScanConvMode = ENABLE;  
//    //����ת��  
//    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;  
//    //�ⲿ������ֹ  
//    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;  
//	//ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO;
//    //�����Ҷ���  
//    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  	
//    //����ת����ͨ����  
//    ADC_InitStructure.ADC_NbrOfChannel = 1;  
//    ADC_Init(ADC1, &ADC_InitStructure);  
//      
//    //����ģʽͨ������  
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
////���TEST0 
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
////���TEST1 
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

//STM32F103ZE���İ�
//ADC ����	   
							  
////////////////////////////////////////////////////////////////////////////////// 
	   
		   
//��ʼ��ADC
//�������ǽ��Թ���ͨ��Ϊ��
//����Ĭ�Ͻ�����ͨ��0~3																	   
void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //ʹ��ADC1ͨ��ʱ��
 

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

	//PA1 ��Ϊģ��ͨ����������                         
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//ģ����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	ADC_DeInit(ADC1);  //��λADC1 

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//ģ��ת�������ڵ�ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//˳����й���ת����ADCͨ������Ŀ
	ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   

  
	ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
	
	ADC_ResetCalibration(ADC1);	//ʹ�ܸ�λУ׼  
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//�ȴ���λУ׼����
	
	ADC_StartCalibration(ADC1);	 //����ADУ׼
 
	while(ADC_GetCalibrationStatus(ADC1));	 //�ȴ�У׼����
 
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������

}				  
//���ADCֵ
//ch:ͨ��ֵ 0~3
u16 Get_Adc(u8 ch)   
{
  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������

	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����
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



























