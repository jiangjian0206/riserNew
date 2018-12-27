#include "led.h"
//#include "delay.h"
//#include "sys.h"
#include "stdio.h"
#include "define.h"
//#include "define.h"
#include "usart.h"
#include "ADC.h"

//#include "Time_test.h"
#include "stm32f10x_tim.h"

//#include "wdg.h"
#include "Select4051.h"
u8 flagg=0,keyflag=0;
u8 sflag=0;
u8 k;
volatile unsigned char debug =1;
volatile unsigned char debugPrintfEachTime =0;
float Temper=0;
u16 tmpp=0;

unsigned char mbufID[20];
volatile u32 time=1200; // ms 计时变量
volatile u32 time1s;
volatile u32 time1sflag=0,timeflag=0,timeff=0;
volatile int f_putLong =0;


unsigned short     int Vo[361];//
unsigned char Table_1[20];
char Table_2[50];
//unsigned char tablePutout[150][20];
unsigned int waitTime =20;


#define	BUFsize 26
#define	X1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define	X2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)
#define	X3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2)
#define	X4 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
#define	X5 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define	X6 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define	X7 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)



	
void delay_ms(unsigned int nms)
{	 		  	  
	u32 temp =nms;		   
    int i =720;
    for(;i>0;i--)
	{
		for(temp =nms;temp>0;temp --)
		{
		
		}
	}
} 

 void selectChannal(int channal,char WhatXY)
 {
   if(WhatXY =='X')
   {
		 switch(channal)
		   {
		       case 0:
			   	XChannal_1;
			   	break;
			   case 1:
			   	XChannal_2;
			   	break;
			   case 2:
			   	XChannal_3;
			   	break;
			   case 3:
			   	XChannal_4;
			   	break;	
			   case 4:
			   	XChannal_5;
			   	break;
			   case 5:
			   	XChannal_6;
			   	break;
			   case 6:
			   	XChannal_7;
			   	break;
			   case 7:
			   	XChannal_8;
			   	break;	
			   default:break;
			   	

		   }
   }
  if(WhatXY =='Y')
   {
		 switch(channal)
		   {
		       case 0:
			   	YChannal_1;
			   	break;
			   case 1:
			   	YChannal_2;
			   	break;
			   case 2:
			   	YChannal_3;
			   	break;
			   case 3:
			   	YChannal_4;
			   	break;	
			   case 4:
			   	YChannal_5;
			   	break;
			   case 5:
			   	YChannal_6;
				
			   	break;
			   case 6:
			   	YChannal_7;
			   	break;
			   case 7:
			   	YChannal_8;
			   	break;	
			   default:break;
			   	

		   }
   }
 
 }
 void selectYCs(int channal)
 {
     CSY1 =1;
	 CSY2 =1;
	 CSY3 =1;
	 CSY4 =1;
	 CSY5 =1;
	 CSY6 =1;
	 CSY7 =1;
	 CSY8 =1;
	 CSY9 =1;
	 CSY10 =1;
	 CSY11 =1;
	 CSY12 =1;
	 CSY13 =1;
	 CSY14 =1;
	 CSY15 =1;
	
	 CSY16 =1;
	 CSY17 =1;
	 CSY18 =1;
	 CSY19 =1;
	 CSY20 =1;
	 CSY21 =1;
	 CSY22 =1;
	 CSY23 =1;
	 CSY24 =1;
	 CSY25 =1;
	 CSY26 =1;
	 CSY27 =1;
	 CSY28 =1;
	 CSY29 =1;
	 CSY30 =1;
	 CSY31 =1;
	 CSY32 =1;
	 CSY33 =1;
	 CSY34 =1;
	 CSY35 =1;
	 CSY36 =1;
	 CSY37 =1;
	 CSY38 =1;
	 CSY39 =1;
	 CSY40 =1;
	 CSY41 =1;
	 CSY42 =1;
	 CSY43 =1;
	 CSY44 =1;
	 CSY45 =1;
	 
     switch ( channal )
     {
         case 0 :             CSY1 =0;             break;
         case 1 :             CSY2 =0;             break;
         case 2 :             CSY3 =0;             break;
         case 3 :             CSY4 =0;             break;
         case 4 :             CSY5 =0;             break;
         case 5 :             CSY6 =0;             break;
         case 6 :             CSY7 =0;             break;
         case 7 :             CSY8 =0;             break;
         case 8 :             CSY9 =0;             break;
         case 9 :             CSY10 =0;             break;
         case 10 :            CSY11 =0;            break;
         case 11 :            CSY12 =0;             break;
         case 12 :            CSY13 =0;             break;
         case 13 :            CSY14 =0;             break;
         case 14 :            CSY15 =0;             break;
         case 15 :            CSY16 =0;             break;
         case 16 :            CSY17 =0;             break;
         case 17 :            CSY18 =0;             break;
         case 18 :            CSY19 =0;             break;
         case 19 :            CSY20 =0;             break;
		        
		                       
	     case 20 :	         CSY21 =0;	         break;
	     case 21 :	         CSY22 =0;	         break;
	     case 22 :	         CSY23 =0;	         break;
	     case 23 :	         CSY24 =0;	         break;
	     case 24 :	         CSY25 =0;	         break;
	     case 25 :	         CSY26 =0;	         break;
	     case 26 :	         CSY27 =0;	         break;
	     case 27 :	         CSY28 =0;	         break;	 
		 case 28:	         CSY29 =0;	         break;
	     case 29 :	         CSY30 =0;	         break;
	     case 30 :	         CSY31 =0;	         break;
	     case 31 :	         CSY32 =0;	         break;
	     case 32 :	         CSY33 =0;	         break;
	     case 33 :	         CSY34 =0;	         break;
	     case 34 :	         CSY35 =0;	         break;
	     case 35 :	         CSY36 =0;	         break;
	     case 36 :	         CSY37 =0;	         break;
	     case 37 :	         CSY38 =0;	         break;
	     case 38 :	         CSY39 =0;	         break;
	     case 39 :	         CSY40 =0;	         break;
	     case 40 :	         CSY41 =0;	         break;
	     case 41 :	         CSY42 =0;	         break;
	     case 42 :	         CSY43 =0;	         break;
	     case 43 :	         CSY44 =0;	         break;
	     case 44 :	         CSY45 =0;	         break;
         default:             
             break;
     }
	 	
     
 }
 void selectXCs(int channal)
 {
     CSX1 =1;
	 
	 CSX2 =1;
	 CSX3 =1;
	 CSX4 =1;
	 CSX5 =1;
	 CSX6 =1;
	 CSX7 =1;
	 CSX8 =1;
	 CSX9 =1;
	 CSX10 =1;
	 CSX11 =1;
	 CSX12 =1;
	 CSX13 =1;
	 CSX14 =1;
	 CSX15 =1;
	 CSX16 =1;
	 CSX17 =1;
	 CSX18 =1;
	 CSX19 =1;
	 CSX20 =1;
	 CSX21 =1;
	 CSX22 =1;
	 CSX23 =1;
	 CSX24 =1;
	 CSX25 =1;
	 CSX26 =1;
	 CSX27 =1;
	 CSX28 =1;
	 CSX29 =1;
	 CSX30 =1;
	 CSX31 =1;
	 CSX32 =1;
	 CSX33 =1;
	 CSX34 =1;
	 CSX35 =1;
	 CSX36 =1;
	 CSX37 =1;
	 CSX38 =1;
	 CSX39 =1;
	 CSX40 =1;
	 CSX41 =1;
	 CSX42 =1;
	 CSX43 =1;
	 CSX44 =1;
	 CSX45 =1;
	 
     switch ( channal )
     {
         case 0 :              CSX1 =0;           break;
         case 1 :              CSX2 =0;            break;
         case 2 :              CSX3 =0;            break;
         case 3 :              CSX4 =0;           break;
         case 4 :              CSX5 =0;            break;
         case 5 :              CSX6 =0;            break;
         case 6 :             CSX7 =0;             break;
         case 7 :             CSX8 =0;             break;
         case 8 :             CSX9 =0;             break;
         case 9 :             CSX10 =0;             break;
         case 10 :            CSX11 =0;             break;
         case 11 :            CSX12 =0;             break;
         case 12 :            CSX13 =0;             break;
         case 13 :            CSX14 =0;             break;
         case 14 :            CSX15 =0;             break;
         case 15 :            CSX16 =0;             break;
         case 16 :            CSX17 =0;             break;
         case 17 :            CSX18 =0;             break;
         case 18 :            CSX19 =0;             break;
         case 19 :            CSX20 =0;             break;
		 
	     case 20 :	         CSX21 =0;	         break;
	     case 21 :	         CSX22 =0;	         break;
	     case 22 :	         CSX23 =0;	         break;
	     case 23 :	         CSX24 =0;	         break;
	     case 24 :	         CSX25 =0;	         break;
	     case 25 :	         CSX26 =0;	         break;
	     case 26 :	         CSX27 =0;	         break;
	     case 27 :	         CSX28 =0;	         break;	 
		   case 28:	           CSX29 =0;	         break;
	     case 29 :	         CSX30 =0;	         break;
	     case 30 :	         CSX31 =0;	         break;
	     case 31 :	         CSX32 =0;	         break;
	     case 32 :	         CSX33 =0;	         break;
	     case 33 :	         CSX34 =0;	         break;
	     case 34 :	         CSX35 =0;	         break;
	     case 35 :	         CSX36 =0;	         break;
	     case 36 :	         CSX37 =0;	         break;
	     case 37 :	         CSX38 =0;	         break;
	     case 38 :	         CSX39 =0;	         break;
	     case 39 :	         CSX40 =0;	         break;
	     case 40 :	         CSX41 =0;	         break;
	     case 41 :	         CSX42 =0;	         break;
	     case 42 :	         CSX43 =0;	         break;
	     case 43 :	         CSX44 =0;	         break;
	     case 44 :	         CSX45 =0;	         break;
	     
	        
	     
         default:
             break;
     }
	
	
	 	
     
 }
 int SetPinDelay(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;

	
	 YEightBit =(TestYPin-1)%8;
	 YCsBit =(TestYPin-1)/8;
	 XEightBit =(TestXPin-1)%8;
	 XCsBit =(TestXPin-1)/8;
	
	    selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(3);
		Vo[1]=Get_Adc_Average(0,4);
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
//		if(Vo[1] >=1)
		{
			sprintf(Table_2, "\r\nY[%3d]X[%3d]:%5d\r\n", TestYPin,TestXPin,Vo[1]);
			printf(Table_2);//Up
		}
//		else printf(".");//Up
		
	    //是否open   with next line.
		
		return Vo[1];
//		  delay_ms(2);
//		  voltage_TEST0();voltage_TEST0();
//		  Vo[2]=voltage_TEST0();
//		  sprintf(Table_2, "Y1X2:%d\r\n", Vo[2]);
//		  printf(Table_2);//Up

}
int SetPin(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;


	 
	 YEightBit =(TestYPin-1)%8;
	 YCsBit =(TestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	  selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(10);
		Vo[1]=Get_Adc_Average(0,6);
	  
	  if(Vo[1] >1000)
		{
			selectYCs(YCsBit);
			selectChannal(YEightBit,'Y');
			selectXCs(XCsBit);
			selectChannal(XEightBit,'X');
			delay_ms(20);
			Vo[1]=Get_Adc_Average(0,6);
		
		}
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
//		if(Vo[1] >=f_putLong)
//		{
//			sprintf(Table_2, "      --------   Y[%3d]X[%3d]:%5d;", TestYPin,TestXPin,Vo[1]);
//			printf(Table_2);//Up
//		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		selectYCs(800); 
		return Vo[1];


}
int SetPinPrint(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;


	 
	 YEightBit =(TestYPin-1)%8;
	 YCsBit =(TestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	  selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(20);
		Vo[1]=Get_Adc_Average(0,6);
	  
	  if(Vo[1] >1000)
		{
			selectYCs(YCsBit);
			selectChannal(YEightBit,'Y');
			selectXCs(XCsBit);
			selectChannal(XEightBit,'X');
			delay_ms(20);
			Vo[1]=Get_Adc_Average(0,6);
		
		}
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
//		if(Vo[1] >=f_putLong)
//		{
			sprintf(Table_2, "      --------   Y[%3d]X[%3d]:%5d;", TestYPin,TestXPin,Vo[1]);
			printf(Table_2);//Up
//		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		selectYCs(800); 
		return Vo[1];


}
int SetPinDontClose(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;


	 
	 YEightBit =(TestYPin-1)%8;
	 YCsBit =(TestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	  selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(100);
		Vo[1]=Get_Adc_Average(0,6);
	  
	  if(Vo[1] >1000)
		{
			selectYCs(YCsBit);
			selectChannal(YEightBit,'Y');
			selectXCs(XCsBit);
			selectChannal(XEightBit,'X');
			delay_ms(20);
			Vo[1]=Get_Adc_Average(0,6);
		
		}
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
//		if(Vo[1] >=f_putLong)
//		{
//			sprintf(Table_2, "      --------   Y[%3d]X[%3d]:%5d;", TestYPin,TestXPin,Vo[1]);
//			printf(Table_2);//Up
//		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		//selectYCs(800); 
		return Vo[1];


}
//传进来的是产品的点位。
 int SetPinReverse111(int TestYPin,int TestXPin)
{
    //是否导通   number 1
   return 0;

}
void testGNDPoint(int *Ypoint,int *Xpoint)
{
   int result =0,i=*Xpoint,j=*Ypoint;
   
   for(; *Ypoint !=500; Ypoint ++)
   	{
	   	
	   	    result =SetPin(*Ypoint,i);
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
   	}
    
    for(; *Xpoint !=500; Xpoint ++)
   	{
	   	
	   	    result =SetPin(j,*Xpoint);
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
   	} 
	
   
}
int judeWhinY(int i,int *point)
{

   for(;*point !=500;point ++)
   	{

     if(i == *point ) 
     {
		return 1;
	 }
   }

   return 0;

}
void scanSignalLine()
{
   int i=0,j=0;
   int numTestFrom  =23, numTestTo =100;
   int numTestXFrom =23,numTestXTo =100;
   int result =0;
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data;
	
   for(i= numTestFrom ; i<= numTestTo ; i++)
   	{  
   	  if(judeWhinY(i,J7A_gnd)== 1) continue;
	   	for ( j =  numTestXFrom; j <=  numTestXTo; j++ )
	   	{
			//if(judeWhinY(j,J1X_data)== 1) continue;
			result =SetPin(i,j);
	   	    
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
	   	}
	
   }
    printf("here is out put all of result  \r\n");
   
}
//依据已经知道的信号点Y,扫描出X的signal点。传入Y的信号点。
void scanSignalLineByPoint(int *Ypoint)
	{
  

    printf("here is out put all of result  \r\n");
   
}
 void scanEveryPoint()
{
   int i=0,j=0;
   int numTestFrom  =1, numTestTo =50;
   int numTestXFrom =1,numTestXTo =50;
   int result =0;
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data;
	
   for(i= numTestFrom ; i<= numTestTo ; i++)
   	{  
   	   
	   	for ( j =  numTestXFrom; j <=  numTestXTo; j++ )
	   	{
			
			result =SetPin(i,j);
	   	    
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
	   	}
	
   }
    printf("here is out put all of result  \r\n");
   
}
 void scanEveryPointByReverse111111111111()
{
   int i=0,j=0;
   int numTestFrom  =1, numTestTo =50;
   int numTestXFrom =1,numTestXTo =50;
   int result =0;
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data;
	
   for(i= numTestFrom ; i<= numTestTo ; i++)
   	{  
   	   
	   	for ( j =  numTestXFrom; j <=  numTestXTo; j++ )
	   	{
			
			result =SetPin(i,j);
	   	    
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
	   	}
	
   }
    printf("here is out put all of result  \r\n");
   
}
 void findGND(int fromPoint,int toPoint,int gnd)
{
   int i=0;
   //int numTestFrom  =1, numTestTo =50;
   //int numTestXFrom =1,numTestXTo =50;
   int result =0;
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data;
	
   for(i= fromPoint ; i<= toPoint ; i++)
   	{  
   	   
	   	
			
			result =SetPinReverse(i,gnd);
	   	if(result<1000 ) SetPinReverse(i,gnd);   
			
	
   }
    printf("scan the gnd over  \r\n");
   
}  
 void XfindGND(int fromPoint,int toPoint,int gnd)
{
   int i=0;
   //int numTestFrom  =1, numTestTo =50;
   //int numTestXFrom =1,numTestXTo =50;
  
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data
	
   for(i= fromPoint ; i<= toPoint ; i++)
   	{  
   	   
	 SetPinReverse(gnd,i);
	 //if(result<1000 ) SetPinReverse(i,gnd);   
   }
    printf("scan the gnd over  \r\n");
   
}
void scanEveryPointBySelect(int fromPoint,int toPoint)
{
   int i=0,j=0;
   //int numTestFrom  =1, numTestTo =50;
   //int numTestXFrom =1,numTestXTo =50;
   int result =0;
//   int *Ypoint =J7Y_data;
//   int *Xpoint =J1X_data;
	
   for(i= fromPoint ; i<= toPoint ; i++)
   	{  
   	   
	   	for ( j =  fromPoint; j <=  toPoint; j++ )
	   	{
			
			result =SetPinReverse(i,j);
	   	    
			if ( result >500)
			{
			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
			}
	   	}
	
   }
    printf("here is out put all of result  \r\n");
   
}
void printfSignal(int *pointAlready)
{
	int *temp =pointAlready;
  int i =1;
	for(i=1;i<100;i++)
	{
	   for(pointAlready=temp;*pointAlready !=500;pointAlready++) 
		{
		      if(i==*pointAlready) break;
		      if(*(pointAlready+1) ==500) printf("%3d,",i);
		}
				
	}
}
//void TestSignalOnly_three(int *point)
//{
////   int i=0;
//   int result =0;
//   for(;*point !=500;point ++)
//   {
//      result =SetPin(*point,*point);
//	  if(result <1200) 
//	  {
//	     sprintf(Table_2, "J7A[%3d]J1A[%3d]:open.\r\n",*point,*point);
//		 printf(Table_2);
//		 //break;
//	  }
//	  result =SetPin(*point,*point +1);
//	  if(result >1100)
//	  	{
//	  	    sprintf(Table_2, "J7A[%3d]J1A[%3d]:short.\r\n",*point,*point+1);
//			printf(Table_2);
//			//break;
//	  	}
//	  
//   }
// 
//}
void test4051(int i)
{
  SetPin(i,i);

}
void test4051reverse(int i)
{
  SetPinReverse(i,i);

}
void test4051_closeY(int i,int w)
{
  SetPinDelay(i,w);
//	if(w ==0)	SetPinDelay(i,i);

}
void run(void)
{
//   int i=0,j=0;
//   int numTestFrom  =1, numTestTo =100;
//   int numTestXFrom =1,numTestXTo =100;
//   int result =0;
	
//   for(i= 10 ; i<= 11; i++)
//   	{
//	   	for ( j = numTestFrom ; j <= numTestTo ; j++ )
//	   	{
//	   	   // result =SetPin(i,j);
//			if ( result >500)
//			{
//			    //sprintf(tablePutout[i], " Y[%3d]X[%3d]:%5d\r\n", i,j,Vo[1]);
//			}
//	   	}
//	
//   }
    
   //testGNDPoint(J7Y_data,J1X_data);
   // scanSignalLine();
   //TestSignalOnly_three(J7Y_signalTestpoint);
   // scanSignalLine();
   scanEveryPoint();
   printf("here is out put all of result  \r\n");
   

}


void main1(void)
 {	  
	
	run();
 
}
//测试j7a-j1a
//int testj7a_j1a()
//{
//	int *Ypoint =J7Y_signalTestpoint;
//	int result =0;
//  for(;*Ypoint!=500;Ypoint ++)
//	{
//	   result = SetPinReverse(*Ypoint,*Ypoint);
//		if(result <1000)    //信号线短路测试
//		{
//			sprintf(Table_2, "fail:J7A[%3d]J1A[%3d]:open.\r\n",*Ypoint,*Ypoint);
//			printf(Table_2);
//		  return 0;
//		}
//        if(debug ==1 && result >1000)   //打印出测试的项目。
//		{
//		    sprintf(Table_2, "--J7A[%3d]J1A[%3d]:CLOSE TEST OK--.\r\n",*Ypoint,*Ypoint);
//			printf(Table_2);
//		}
//		 result = SetPinReverse(*Ypoint,*(Ypoint+1));  //相邻的开路测试  
//		 if(result >800) 
//		{
//			sprintf(Table_2, "fail:J7A[%3d]J1A[%3d]:short.\r\n",*Ypoint,*Ypoint+1);
//			printf(Table_2);
//		  return 0;
//		}
//		
//		if(debug ==1 && result <1000)   //打印出测试的项目。
//		{
//		    sprintf(Table_2, "--J7A[%3d]J1A[%3d]:OPEN TEST OK--.\r\n",*Ypoint,*Ypoint+1);
//			printf(Table_2);
//		}
//		//----------------
//		 result = SetPinReverse(*Ypoint,21);  //信号线和 gnd测试 开路
//		 if(result >800) 
//		{
//			sprintf(Table_2, "fail:J7A[%3d]J1A[ 21]:short.\r\n",*Ypoint);
//			printf(Table_2);
//		   return 0;
//		}
//		if(debug ==1 && result <1000)   //打印出测试的项目。
//		{
//		    sprintf(Table_2, "--J7A[%3d]J1A[ 21]:OPEN TEST OK--.\r\n",*Ypoint);
//			printf(Table_2);
//		}
//	}
//	
//	return 1;

//}




