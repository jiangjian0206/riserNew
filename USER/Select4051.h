#ifndef _select4051_h
#define _select4051_h


extern volatile int f_putLong;
#define YChannal_1   A1=1;B1=0;C1=1;  //5
#define YChannal_2   A1=1;B1=1;C1=0; // 3
#define YChannal_3   A1=1;B1=1;C1=1; //7
#define YChannal_4   A1=0;B1=0;C1=0; //. 0
#define YChannal_5   A1=0;B1=1;C1=1;   //6
#define YChannal_6   A1=1;B1=0;C1=0; //  1
#define YChannal_7   A1=0;B1=0;C1=1;  //4
#define YChannal_8   A1=0;B1=1;C1=0; //   2
                     
#define XChannal_1   A2=1;B2=0;C2=1;
#define XChannal_2   A2=1;B2=1;C2=0;
#define XChannal_3   A2=1;B2=1;C2=1;
#define XChannal_4   A2=0;B2=0;C2=0;
#define XChannal_5   A2=0;B2=1;C2=1;
#define XChannal_6   A2=1;B2=0;C2=0;
#define XChannal_7   A2=0;B2=0;C2=1;
#define XChannal_8   A2=0;B2=1;C2=0;

extern char returnOR;
extern unsigned short int Vo[361];//
extern int J7A_gnd[];
extern volatile unsigned char debug;
extern volatile unsigned char debugPrintfEachTime;
extern int J7Y_signalTestpoint[];
extern char Table_2[50];

extern  int SetPinDelay(int TestYPin,int TestXPin);
extern int SetPin(int TestYPin,int TestXPin);
extern void testGNDPoint(int *Ypoint,int *Xpoint);
extern int judeWhinY(int i,int *point);
extern  void scanSignalLine(void);                    
extern void TestSignalOnly_three(int *point);
extern void run(void);
extern void main1(void);
extern void test4051(int i);
extern int test4051_closeY(int i,int);
extern void delay_ms(unsigned int nms);
extern void scanEveryPointBySelect(int fromPoint,int toPoint);
extern void scanEveryPointBySelect(int fromPoint,int toPoint);
extern void findGND(int fromPoint,int toPoint,int gnd);
extern void printfSignal(int *pointAlready);
extern void XfindGND(int fromPoint,int toPoint,int gnd);   
extern void scanSignalLineByPoint(int *Ypoint);
extern int testj7a_j1a(void);
extern  int SetPinReverse(int TestYPin,int TestXPin);
//
 extern void selectChannal(int channal,char WhatXY);
 extern  void selectYCs(int channal);
 extern  void selectXCs(int channal);
 extern  int SetPinDelay(int TestYPin,int TestXPin);
 extern  int SetPinDontClose(int TestYPin,int TestXPin);
 extern  int SetPinPrint(int TestYPin,int TestXPin);
 extern int J7Y_signalTestpoint[] ;
 extern int J7A_gnd[]; 
 extern int J1A_gnd[];
 extern int testj7B_j1B(void);
 extern int testj6A_U1A(void);
 
 extern int controlCylinder(int index);
 #endif
 


