/******************************************************************************

                  ��Ȩ���� (C), 2015.9.6,   �������ӹ���ʦ

 
******************************************************************************

*-----------------��ֲ��������˵�� -----------------------------*

 //��ʱ���ж� Ҫ ��1ms��������Ҹ��� ���������ͱ�־λ��

*-------------------�ⲿ����˵��---------------------------*
ȫ�ֱ��� ��
volatile uint  G_TimerCnt_DelayServe_10MS =0;
******************************************************************************/

#include "Delaypoint.h"
//part1
volatile uint  G_TimerCnt_DelayServe_10MS =0;
TypeDelayStr F_DelayStr_Exam1;
TypeDelayStr F_DelayStr_Exam2;
TypeDelayStr F_DelayStr_Exam3;
TypeDelayStr F_DelayStr_Exam4;
TypeDelayStr F_DelayStr_Exam5;
TypeDelayStr F_DelayStr_Exam6;
TypeDelayStr F_DelayStr_Exam7;
TypeDelayStr F_DelayStr_Exam8;
TypeDelayStr F_DelayStr_Exam9;
TypeDelayStr F_DelayStr_Exam10;

TypeDelayStr F_DelayStr_Exam11;
TypeDelayStr F_DelayStr_Exam12;
TypeDelayStr F_DelayStr_Exam13;
TypeDelayStr F_DelayStr_Exam14;
TypeDelayStr F_DelayStr_Exam15;






//�ṹ���ڵ�GI_Cnt   һֱ�ӣ�׷���趨��DelayTimes_MSΪֹF_Delay_10Ms��־λ��һ��
void DelayUpdata(TypeDelayStr *P_TypeDelayStr)
{

		(*P_TypeDelayStr).GI_Cnt ++; 
		if (P_TypeDelayStr->DelayTimes_MS == P_TypeDelayStr->GI_Cnt)
		{
        P_TypeDelayStr->F_Delay_10Ms =1;
				P_TypeDelayStr->GI_Cnt= 0;
		}
}

void ServeDelay(void)
{
   if(G_TimerCnt_DelayServe_10MS >0)
	 {
		  G_TimerCnt_DelayServe_10MS =0;
	
		  DelayUpdata(&F_DelayStr_Exam1);
		  DelayUpdata(&F_DelayStr_Exam2);
		  DelayUpdata(&F_DelayStr_Exam3);
		  DelayUpdata(&F_DelayStr_Exam4);
		  DelayUpdata(&F_DelayStr_Exam5);
		  DelayUpdata(&F_DelayStr_Exam6);
		  DelayUpdata(&F_DelayStr_Exam7);
		  DelayUpdata(&F_DelayStr_Exam8);
		  DelayUpdata(&F_DelayStr_Exam9);
		  DelayUpdata(&F_DelayStr_Exam10);
		  DelayUpdata(&F_DelayStr_Exam11);
		  DelayUpdata(&F_DelayStr_Exam12);
		  DelayUpdata(&F_DelayStr_Exam13);
		  DelayUpdata(&F_DelayStr_Exam14);
		  DelayUpdata(&F_DelayStr_Exam15);
		  
		 
   }
}
//1.�ṹ�壬
//2.��Ҫ����ʱ��
//3.��ʱ��ɺ����һ��״̬
//4.�ܵ���ʱ״̬����ȥ�������һ��״̬ȥ��� ��ʱ�Ƿ񵽡�
//
//
void InitDelay_01(TypeDelayStr *P_TypeDelayStr_intern,unsigned int Delay_ms ,u8 NextState,uchar *P_UseState)
{

   P_TypeDelayStr_intern->F_Delay_10Ms =0;//��־λ����
   P_TypeDelayStr_intern->GI_Cnt =0;//��̬׷������
   P_TypeDelayStr_intern->DelayTimes_MS =Delay_ms;
   P_TypeDelayStr_intern->GC_StateNext  =NextState;
   *P_UseState =101;
}
//1.�ṹ�壬
//2.��Ҫ����ʱ��
//3.��ʱ��ɺ����һ��״̬
//4.�ܵ���ʱ״̬����ȥ�������һ��״̬ȥ��� ��ʱ�Ƿ񵽡�
//
//
void InitDelay(TypeDelayStr *P_TypeDelayStr_intern,unsigned int Delay_ms ,u8 NextState,uchar *P_UseState)
{

   P_TypeDelayStr_intern->F_Delay_10Ms =0;//��־λ����
   P_TypeDelayStr_intern->GI_Cnt =0;//��̬׷������
   P_TypeDelayStr_intern->DelayTimes_MS =Delay_ms;
   P_TypeDelayStr_intern->GC_StateNext  =NextState;
   *P_UseState =100;
}

void WaitingDelay(TypeDelayStr *P_TypeDelayStr_ExamPram,uchar *P_UseState)
{
  if(P_TypeDelayStr_ExamPram->F_Delay_10Ms ==1) *P_UseState =P_TypeDelayStr_ExamPram->GC_StateNext;
}

