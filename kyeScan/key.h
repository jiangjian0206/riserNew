/******************************************************************************

                  ��Ȩ���� (C), 2015.9.6,   �������ӹ���ʦ

 ******************************************************************************
  �� �� ��   :	 key.h
  �� �� ��   :	 ����
  ��    ��       :	 jiangjian
  ��������   : 2016��12��22�� ������
  ����޸�   :
  ��������   : key.c ��ͷ�ļ�
  ����˵�����ĵ�  :
//��.
//��.
//��.
//

******************************************************************************

*-----------------��ֲ��������˵�� -----------------------------*

1.���ӱ��� StrKeyClass Key1������������
2.�� KeyServe  �������� ���    if(IO_Key1 ==0) Key1.TimeCnt_Key_Down ++;
																		else Key1.TimeCnt_Key_Down =0;
																if(IO_Key1 ==1) Key1.TimeCnt_Key_Up++;
																		else Key1.TimeCnt_Key_Up =0;
3.KeyUpdata(&Key2);																		

*-------------------�ⲿ����˵��---------------------------*
1.#include "stm32f10x_gpio.h"

 *-------------------����ӿ�---------------------------*


******************************************************************************/
#ifndef __KEY_H__
#define __KEY_H__



#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
	

	
typedef struct KeyClass
{
     unsigned int  TimeCnt_Key_Down;
	 unsigned int  TimeCnt_Key_Up;
	 unsigned int  TimeCnt_KeyLoosen_Up;
	 unsigned int  TimeCnt_Key_TwoUp;
	 unsigned char  KeyStateLock; 
	 unsigned char  KeyState ;
	 
	 unsigned char  KeyShortDown_F ;
	 unsigned char  KeyUp_F;
	 unsigned char  KeyKeepUp_F;
	 unsigned char  KeyLongDown_F;
	 unsigned int   KeyLockBit;
	 unsigned char  KeyLoosen_F;//should be closeed .
}StrKeyClass;

extern StrKeyClass Key1, Key2,Key3,Key4,Key5,Key6, Key7,Key8,Key9,Key10,Key11, Key12,Key13,Key14,Key15;
extern volatile unsigned int  G_TimerCnt_KeyServe_10MS;
extern StrKeyClass LeftSensor_Push,LeftSensor_Pull,RightSensor_Push,RightSensor_Pull,BehindSensor_Push,BehindSensor_Pull;
extern StrKeyClass Riser1Sensor_Push,Riser1Sensor_Pull,Riser2Sensor_Push,Riser2Sensor_Pull;
extern StrKeyClass x3Sernsor_underaught_top,x5Sensor_underaught_bottom,x4Sensor_up_bottom,x6Sensor_Left_bottom,x7Sensor_right_bottom;


extern void KeyUpdata(StrKeyClass *P_KeyClass);
extern void KeyUpdataSpeed(StrKeyClass *P_KeyClass);
extern void KeySenser(StrKeyClass *P_KeyClass);
extern void KeyServe(void);
extern void KeySelf(StrKeyClass *P_KeyClass);
extern void InitKey(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __KEY_H__ */
