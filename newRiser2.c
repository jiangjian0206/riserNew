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


#include "Select4051.h"
char returnOR =1;


int J7Y_signalTestpoint[] = { 25, 26, 28, 29,     33, 34, 36, 37, 39, 40, 42, 43, 45, 46, 48, 49, 51, 52, 54, 55, 57, 59, 60, 62, 63, 65, 66, 68, 69, 71, 72, 74, 75, 77, 78, 80, 81, 84, 86, 88, 89, 91, 92, 94, 95, 97, 98,500};
int J7A_gnd[] ={ 8,  9, 10, 11, 12, 20, 21, 22, 24, 27, 30, 32, 35, 38, 41, 44, 47, 50, 53, 56, 58, 61, 64, 67, 70, 73, 76, 79, 82, 83, 85, 87, 90, 93, 96, 99,500};
int J1A_gnd[] ={ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 27, 30, 32, 35, 38, 41, 44, 47, 53, 56, 58, 61, 64, 67, 70, 73, 76, 79, 82, 85, 87, 90, 93, 96, 99,100,500};
 //int J7YB_signalTestpoint[] = { 24,26,27,31,32,34,35,37,38,40,41,43,44,46,47,49,50,52,53,55,57,58,60,61,63,64,66,67,69,70,72,73,75,76,78,79,84,86,88,89,91,92,94,95,97,98,500};
int J7YB_signalTestpoint[] = {    	 26,27,31,         37,      41,43,44,46,47,49,50,52,53,55,57,58,60,61,63,64,66,67,69,72,73,75,76,78,79,84,86,88,89,91,92,94,97,98,500};
int J7B_gnd[] ={ 7,8,9,10,11,12,15,22,25,28,30,33,36,39,42,45,48,51,54,56,59,62,65,68,71,74,77,80,83,85,87,90,93,96,99,500};
int J1B_gnd[] ={ 14,15,16,17,18,19,20,21,22,23,24,25,28,30,33,36,39,42,45,48,51,54,56,59,62,65,68,71,74,77,80,85,87,90,93,96,99,100,500};

		
int J6YB_signalTestpoint[] = {    	 26,27,31,         37,      41,43,44,46,47,49,50,52,53,55,57,58,60,61,63,64,66,67,69,72,73,75,76,78,79,84,86,88,89,91,92,94,97,98,500};
int J6B_gnd[] ={ 7,8,9,10,11,12,15,22,25,28,30,33,36,39,42,45,48,51,54,56,59,62,65,68,71,74,77,80,83,85,87,90,93,96,99,500};
int U1B_gnd[] ={ 14,15,16,17,18,19,20,21,22,23,24,25,28,30,33,36,39,42,45,48,51,54,56,59,62,65,68,71,74,77,80,85,87,90,93,96,99,100,500};
 
int J6YA_signalTestpoint[] = {   25,26,28,29,33,34,36,37,39,40,42,45,46,48,49,51,52,54,55,57,59,60,62,63,65,66,68,69,71,72,74,75,77,78,80,81,500};
int U1YA_signalTestpoint[] = {   9 ,10,60,61,57,58,54,55,51,52,68,48,49,45,46,42,43,39,40,22,36,37,33,34,30,31,27,28,24,25,18,19,15,16,12,13,500};	
//int J6YA_signalTestpoint[] = {    	 23,25,26,28,29,31,33,34,36,37,39,40,42,43,45,46,48,49,51,52,54,55,57,59,60,62,63,65,66,68,69,71,72,74,75,77,78,80,81,500};
int J6A_gnd[] ={ 8,9,10,11,12,20,21,22,24,27,30,32,35,38,41,44,47,50,53,56,58,61,64,67,70,73,76,79,82,500};
int U1A_gnd[] ={ 14,15,16,17,18,19,20,21,22,23,24,25,28,30,33,36,39,42,45,48,51,54,56,59,62,65,68,71,74,77,80,85,87,90,93,96,99,100,500};

			
int J6BU1BData [][4] ={

   //Yslot,	Xgoal,	RelyY,	RelyX
   23,	23,	27,	27,
   

};



//传进来的是产品的点位。
 int SetPinReverse(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;  //这是实际切换的ic点位，比如产品1点，对应ic脚50.  
	int realTestYPin =TestXPin;
//	int TestPinYAfter,TestXPinAfter;

	 if ( TestXPin >0 && TestXPin <= 50 )
	 {
	     if(TestXPin >25)
	     {
			realTestXPin =TestXPin -(TestXPin -25)*2 +1;
		 }
		 if ( TestXPin <= 25 )
		 {
		    realTestXPin = TestXPin +(25 -TestXPin)*2+1;
		 }
	 }
	 if ( TestXPin >50 && TestXPin <= 100 )
	 {
	     if(TestXPin >75)
	     {
			realTestXPin =TestXPin -(TestXPin -75)*2 +1;
		 }
		 if ( TestXPin <= 75 )
		 {
		    realTestXPin = TestXPin +(75 -TestXPin)*2+1;
		 }
	 }
	 if ( TestYPin >0 && TestYPin <= 50 )
	 {
	     if(TestYPin >25)
	     {
			realTestYPin =TestYPin -(TestYPin -25)*2 +1;
		 }
		 if ( TestYPin <= 25 )
		 {
		    realTestYPin = TestYPin +(25 -TestYPin)*2+1;
		 }
	 }
	  if ( TestYPin >50 && TestYPin <= 100 )
	 {
	     if(TestYPin >75)
	     {
			realTestYPin =TestYPin -(TestYPin -75)*2 +1;
		 }
		 if ( TestYPin <= 75 )
		 {
		    realTestYPin = TestYPin +(75 -TestYPin)*2+1;
		 }
	 }
	 
	 YEightBit =(realTestYPin-1)%8;
	 YCsBit =(realTestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	    selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(5);
		Vo[1]=Get_Adc_Average(0,6);
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
		if(Vo[1] >=f_putLong && debugPrintfEachTime ==1)
		{
			sprintf(Table_2, "\r\nY[%3d]X[%3d]:%5d;---realIC place Y[%3d]X[%3d]", TestYPin,TestXPin,Vo[1],realTestYPin,realTestXPin);
			printf(Table_2);//Up
		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		selectYCs(800); 
		return Vo[1];
//		  delay_ms(2);
//		  voltage_TEST0();voltage_TEST0();
//		  Vo[2]=voltage_TEST0();
//		  sprintf(Table_2, "Y1X2:%d\r\n", Vo[2]);
//		  printf(Table_2);//Up

}
//jj传进来的是产品的点位 中的实际ic点，调用着已经是 转换过来后的点。 J7B :100-200 POINT
 int SetPinReverseJ7B(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;  //这是实际切换的ic点位，比如产品1点，对应ic脚50.  
	int realTestYPin =TestXPin;
//	int TestPinYAfter,TestXPinAfter;

	 if ( TestXPin >100 && TestXPin <= 150 )
	 {
	     if(TestXPin >125)
	     {
			realTestXPin =TestXPin -(TestXPin -125)*2 +1;
		 }
		 if ( TestXPin <= 125 )
		 {
		    realTestXPin = TestXPin +(125 -TestXPin)*2+1;
		 }
	 }
	 if ( TestXPin >150 && TestXPin <= 200 )
	 {
	     if(TestXPin >175)
	     {
			realTestXPin =TestXPin -(TestXPin -175)*2 +1;
		 }
		 if ( TestXPin <= 175 )
		 {
		    realTestXPin = TestXPin +(175 -TestXPin)*2+1;
		 }
	 }
	 if ( TestYPin >100 && TestYPin <= 150 )
	 {
	     if(TestYPin >125)
	     {
			realTestYPin =TestYPin -(TestYPin -125)*2 +1;
		 }
		 if ( TestYPin <= 125 )
		 {
		    realTestYPin = TestYPin +(125 -TestYPin)*2+1;
		 }
	 }
	  if ( TestYPin >150 && TestYPin <= 200 )
	 {
	     if(TestYPin >175)
	     {
			realTestYPin =TestYPin -(TestYPin -175)*2 +1;
		 }
		 if ( TestYPin <= 175 )
		 {
		    realTestYPin = TestYPin +(175 -TestYPin)*2+1;
		 }
	 }
	 
	 YEightBit =(realTestYPin-1)%8;
	 YCsBit =(realTestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	    selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(5);
		Vo[1]=Get_Adc_Average(0,10);
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
		if(Vo[1] >=f_putLong && debugPrintfEachTime ==1)
		{
			sprintf(Table_2, "\r\nY[%3d]X[%3d]:%5d;---realIC place Y[%3d]X[%3d]", TestYPin,TestXPin,Vo[1],realTestYPin,realTestXPin);
			printf(Table_2);//Up
		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		selectYCs(800); 
		return Vo[1];
//		  delay_ms(2);
//		  voltage_TEST0();voltage_TEST0();
//		  Vo[2]=voltage_TEST0();
//		  sprintf(Table_2, "Y1X2:%d\r\n", Vo[2]);
//		  printf(Table_2);//Up

}






 //jj传进来的是产品的点位 中的实际ic点，调用着已经是 转换过来后的点。 J7B :200-280 POINT ，其中251-280不用反转
 int SetPinReverseJ6A(int TestYPin,int TestXPin)
{
    //是否导通   number 1
    int YEightBit,YCsBit,XEightBit,XCsBit;
	int realTestXPin =TestXPin;  //这是实际切换的ic点位，比如产品1点，对应ic脚50.  
	int realTestYPin =TestXPin;
//	int TestPinYAfter,TestXPinAfter;

	 if ( TestXPin >200 && TestXPin <= 250 )
	 {
	     if(TestXPin >225)
	     {
			realTestXPin =TestXPin -(TestXPin -225)*2 +1;
		 }
		 if ( TestXPin <= 225 )
		 {
		    realTestXPin = TestXPin +(225 -TestXPin)*2+1;
		 }
	 }
	
	 if ( TestYPin >200 && TestYPin <= 250 )
	 {
	     if(TestYPin >225)
	     {
			realTestYPin =TestYPin -(TestYPin -225)*2 +1;
		 }
		 if ( TestYPin <= 225 )
		 {
		    realTestYPin = TestYPin +(225 -TestYPin)*2+1;
		 }
	 }
	
	 
	 YEightBit =(realTestYPin-1)%8;
	 YCsBit =(realTestYPin-1)/8;
	 XEightBit =(realTestXPin-1)%8;
	 XCsBit =(realTestXPin-1)/8;
	
	    selectYCs(YCsBit);
		selectChannal(YEightBit,'Y');
		selectXCs(XCsBit);
		selectChannal(XEightBit,'X');
		delay_ms(5);
		Vo[1]=Get_Adc_Average(0,10);
		//CSX1=1;
		//ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
		if(Vo[1] >=f_putLong && debugPrintfEachTime ==1)
		{
			sprintf(Table_2, "\r\nY[%3d]X[%3d]:%5d;---realIC place Y[%3d]X[%3d]", TestYPin,TestXPin,Vo[1],realTestYPin,realTestXPin);
			printf(Table_2);//Up
		}
		//else printf(".");//Up
		
	    //是否open   with next line.
		//selectYCs(800); 
		return Vo[1];
//		  delay_ms(2);
//		  voltage_TEST0();voltage_TEST0();
//		  Vo[2]=voltage_TEST0();
//		  sprintf(Table_2, "Y1X2:%d\r\n", Vo[2]);
//		  printf(Table_2);//Up

}
 
 
 
 
 
 
  //jj传进来的是产品的点位 中的实际ic点，调用着已经是 转换过来后的点。 J7B :200-280 POINT ，其中251-280不用反转
  int SetPinReverseJ6B(int TestYPin,int TestXPin)
 {
	 //是否导通   number 1
	 int YEightBit,YCsBit,XEightBit,XCsBit;
	 int realTestXPin =TestXPin;  //这是实际切换的ic点位，比如产品1点，对应ic脚50.	
	 int realTestYPin =TestXPin;
 //  int TestPinYAfter,TestXPinAfter;
 
	  if ( TestXPin >200 && TestXPin <= 250 )
	  {
		  if(TestXPin >225)
		  {
			 realTestXPin =TestXPin -(TestXPin -225)*2 +1;
		  }
		  if ( TestXPin <= 225 )
		  {
			 realTestXPin = TestXPin +(225 -TestXPin)*2+1;
		  }
	  }
	 
	  if ( TestYPin >200 && TestYPin <= 250 )
	  {
		  if(TestYPin >225)
		  {
			 realTestYPin =TestYPin -(TestYPin -225)*2 +1;
		  }
		  if ( TestYPin <= 225 )
		  {
			 realTestYPin = TestYPin +(225 -TestYPin)*2+1;
		  }
	  }
	 
	  
	  YEightBit =(realTestYPin-1)%8;
	  YCsBit =(realTestYPin-1)/8;
	  XEightBit =(realTestXPin-1)%8;
	  XCsBit =(realTestXPin-1)/8;
	 
		 selectYCs(YCsBit);
		 selectChannal(YEightBit,'Y');
		 selectXCs(XCsBit);
		 selectChannal(XEightBit,'X');
		 delay_ms(5);
		 Vo[1]=Get_Adc_Average(0,10);
		 //CSX1=1;
		 //ADVIN=(float)voltage_TEST0()*3300/4096;//24894  *3306/4096;//*
		 if(Vo[1] >=f_putLong && debugPrintfEachTime ==1)
		 {
			 sprintf(Table_2, "\r\nY[%3d]X[%3d]:%5d;---realIC place Y[%3d]X[%3d]", TestYPin,TestXPin,Vo[1],realTestYPin,realTestXPin);
			 printf(Table_2);//Up
		 }
		 //else printf(".");//Up
		 
		 //是否open   with next line.
		 //selectYCs(800); 
		 return Vo[1];
 // 	   delay_ms(2);
 // 	   voltage_TEST0();voltage_TEST0();
 // 	   Vo[2]=voltage_TEST0();
 // 	   sprintf(Table_2, "Y1X2:%d\r\n", Vo[2]);
 // 	   printf(Table_2);//Up
 
 }



//测试j7a-j1a
int testj7a_j1a()
{
	int *Ypoint =J7Y_signalTestpoint;
	int result =0;
    for(;*Ypoint!=500;Ypoint ++)
	{
	   result = SetPinReverse(*Ypoint,*Ypoint);
		if(result <1000)    //信号线短路测试
		{
			sprintf(Table_2, "fail:J7A[%3d]J1A[%3d]:open.\r\n",*Ypoint,*Ypoint);
			printf(Table_2);
		    if(returnOR ==1) return 0;
		}
		
        if(debug ==1 && result >1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7A[%3d]J1A[%3d]:CLOSE TEST OK.\r\n",*Ypoint,*Ypoint);
			printf(Table_2);
		}
		 result = SetPinReverse(*Ypoint,*(Ypoint+1));  //相邻的开路测试  
		 if(result >800) 
		{
			sprintf(Table_2, "fail:J7A[%3d]J1A[%3d]:short.\r\n",*Ypoint,*Ypoint+1);
			printf(Table_2);
		  if(returnOR ==1) return 0;
		}
		
		if(debug ==1 && result <1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7A[%3d]J1A[%3d]:OPEN TEST OK.\r\n",*Ypoint,*Ypoint+1);
			printf(Table_2);
		}
		//----------------
		 result = SetPinReverse(*Ypoint,21);  //信号线和 gnd测试 开路
		 if(result >800) 
		{
			sprintf(Table_2, "fail:J7A[%3d]J1A[ 21]:short.\r\n",*Ypoint);
			printf(Table_2);
		  if(returnOR ==1) return 0;
		}
		if(debug ==1 && result <1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7A[%3d]J1A[ 21]:OPEN TEST OK.\r\n",*Ypoint);
			printf(Table_2);
		}
	}
	
	return 1;

}


 //测试j7a-j1a，点位是产品的实际点位。通过move 移位，再传给 被调函数。
int testj7B_j1B()
{
	int *Ypoint =J7YB_signalTestpoint;
	int Agnd =0;
	int Bgnd =0;
	int result =0;
	int move =100;
    for(;*Ypoint!=500;Ypoint ++)
	{
	   result = SetPinReverseJ7B(*Ypoint+move,*Ypoint+move);
		if(result <1000)    //信号线短路测试
		{
			sprintf(Table_2, "fail:J7B[%3d]J1B[%3d]:open.\r\n",*Ypoint,*Ypoint);
			printf(Table_2);
		  //if(returnOR ==1) return 0;
		}
        if(debug ==1 && result >1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7B[%3d]J1B[%3d]:CLOSE TEST OK.\r\n",*Ypoint,*Ypoint);
			printf(Table_2);
		}
		 result = SetPinReverseJ7B(*Ypoint+move,*(Ypoint+1)+move);  //相邻的开路测试  
		 if(result >800) 
		{
			sprintf(Table_2, "fail:J7B[%3d]J1B[%3d]:short.\r\n",*Ypoint,*Ypoint+1);
			printf(Table_2);
		   //if(returnOR ==1) return 0;
		}
		
		if(debug ==1 && result <1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7B[%3d]J1B[%3d]:OPEN TEST OK.\r\n",*Ypoint,*Ypoint+1);
			printf(Table_2);
		}
		//----------------
		 result = SetPinReverseJ7B(*Ypoint+move,21+move);  //信号线和 gnd测试 开路
		 if(result >800) 
		{
			sprintf(Table_2, "fail:J7B[%3d]J1B[ 21]:short.\r\n",*Ypoint);
			printf(Table_2);
		    //if(returnOR ==1) return 0;
		}
		if(debug ==1 && result <1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J7B[%3d]J1B[ 21]:OPEN TEST OK.\r\n",*Ypoint);
			printf(Table_2);
		}
	}
	
	return 1;

}
//jj 测试j6A_U1A，点位是产品的实际点位。通过move 移位，再传给 被调函数。201-280
int testj6A_U1A()
{
	int *Ypoint =J6YA_signalTestpoint;
	int *Xpoint =U1YA_signalTestpoint;
	int Agnd =0;
	int Bgnd =0;
	int result =0;
	int move =200;
    for(;*Ypoint!=500;(Ypoint ++) ==(Xpoint++))
	{
	    result = SetPinReverseJ6A(*Ypoint+move,*Xpoint+move);
		if(result <1000)    //信号线短路测试
		{
			sprintf(Table_2, "fail:J6A[%3d]U1A[%3d]:open.\r\n",*Ypoint,*Xpoint);
			printf(Table_2);
		  //if(returnOR ==1) return 0;
		}
        if(debug ==1 && result >1000)   //打印出测试的项目。
		{
		    sprintf(Table_2, "J6A[%3d]U1A[%3d]:CLOSE TEST OK.\r\n",*Ypoint,*Xpoint);
			printf(Table_2);
		}
		
//		while(1)
//		{
//			if((USART_RX_BUF[0] == 'v' && USART_RX_BUF[1] == 'v'&& USART_RX_BUF[2] == 'v'))  break;   
//		}
		
//		 result = SetPinReverseJ7B(*Ypoint+move,*(Xpoint+1)+move);  //相邻的开路测试  
//		 if(result >800) 
//		{
//			sprintf(Table_2, "fail:J6A[%3d]U1A[%3d]:short.\r\n",*Ypoint,*Xpoint+1);
//			printf(Table_2);
//		   //if(returnOR ==1) return 0;
//		}
//		
//		if(debug ==1 && result <1000)   //打印出测试的项目。
//		{
//		    sprintf(Table_2, "--J6A[%3d]U1A[%3d]:OPEN TEST OK--.\r\n",*Ypoint,*Xpoint+1);
//			printf(Table_2);
//		}
//		//----------------
//		 result = SetPinReverseJ7B(*Ypoint+move,21+move);  //信号线和 gnd测试 开路
//		 if(result >800) 
//		{
//			sprintf(Table_2, "fail:J6A[%3d]U1A[ 21]:short.\r\n",*Ypoint);
//			printf(Table_2);
//		    //if(returnOR ==1) return 0;
//		}
//		if(debug ==1 && result <1000)   //打印出测试的项目。
//		{
//		    sprintf(Table_2, "--J6A[%3d]U1A[21]:OPEN TEST OK--.\r\n",*Ypoint);
//			printf(Table_2);
//		}
	}
	
	return 1;

}


