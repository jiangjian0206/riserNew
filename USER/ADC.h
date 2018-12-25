#ifndef __ADC_H
#define __ADC_H	
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
/////////////////////////////////////
//修改日期:2014/4/10 
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) liaoyonghui 2009-2019
//All rights reserved					   
/////////////////////////////////////

void Adc_Init(void);
void EXTI_Configuration(void);
void Ad_Start(void);
u16 voltage_TEST0(void) ;
u16 voltage_TEST1(void) ;
u16 Get_Adc_Average(u8 ch,u8 times);
 
#endif 
