#ifndef TaskDelayExter_h
#define TaskDelayExter_h
/*���������ϸ���裺
��һ����TypeDelayStr F_DelayStr_Exam2;�����ʱ������
�ڶ����� DelayUpdata(&F_DelayStr_Exam2);����ServeDelayɨ����������档
��������DefStrTask Task2Infor ;�����������ı�����
���Ĳ���Task2Infor.TaskState =1;��ӵ�InitTaskStr�����ʼ�����棬��ʼ��״̬��
���岽��void Task2(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask)�������������
�󹦸�ɡ�

��������㣺��ֲ��ʱ������ʵ��Ҫ�����ⲿ���壬�����˿���ֲ�ԡ����ڸ��ģ����磺#include "stm32f10x_gpio.h"ʹ�ö˿ں����ȵȡ�
������ֲ���裺main��ӣ��жϱ���ʱ�Ӽ�������һ�º�����
InitTaskStr();
ServeDelay();
Task2(&F_DelayStr_Exam2,&Task2Infor);
�༭ʱ�䣺2017��11��10��
*/
#include "Taskpoint.h"
#include <key.h>

extern volatile unsigned int  G_TimerCnt_DelayServe_10MS;
extern	DefStrTask Task1Infor ;
extern	DefStrTask Task2Infor ;
extern	DefStrTask Task3Infor ;
extern	DefStrTask Task4Infor ;
extern	DefStrTask Task5Infor ;
extern	DefStrTask Task6Infor ;
extern	DefStrTask Task7Infor ;
extern	DefStrTask Task8Infor ;
extern	DefStrTask Task9Infor ;
extern	DefStrTask Task10Infor ;

extern	DefStrTask Task11Infor ;
extern	DefStrTask Task12Infor ;
extern	DefStrTask Task13Infor ;
extern	DefStrTask Task14Infor ;
extern	DefStrTask Task15Infor ;

extern DefSystemState G_SystemState;
extern uchar g_sem_self ;

extern void InitTaskStr(void);

extern void Task1(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);

extern void Task2(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task3(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task4(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task5(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task6(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task7(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task8(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task9(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task10(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);







extern void Task11(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask);
extern void res(void );



#endif
