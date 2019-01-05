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
#include "Alldata.h"

#define go_back if(whether_return ==0) return 0;

int whether_return =0;
int limitResult =1100;

int V12data[][2]={
	48,148,
	47,147,
	146,146,
	145,145,

};
int V3data[][2]={
34,356,
33,357,
32,358,
135,359,
134,357,
133,356,


};
int V3AUXdata[][2]={
	130,328,
	131,329,
	132,330,
	230,248,
	231,249,
	232,250,

};
int  G_gnd[][2] ={
	43,36,
	42,35,
	41,34,
	40,33,
};


 int J7Adata[][4] ={
0,0,0,0,
	
25,25,26,26,
26,26,25,25,
28,28,23,23,
29,29,22,22,
33,33,18,18,
34,34,17,17,
36,36,15,15,
37,37,14,14,
39,39,12,12,
40,40,11,11,
//&& 42,42,9,9,  //''
43,43,8,8,
45,45,6,6,
46,46,5,5,
//&& 48,48,3,3,   number two.
49,49,2,2,
51,51,100,100,
//&&
52,52,99,99,  //''
//&&
54,54,97,97, //''
55,55,96,96,
57,57,94,94,
59,59,92,92,
//&&
60,60,91,91,
//&& 
62,62,89,89,
//&& 
63,63,88,88,  //''
65,65,86,86,
66,66,85,85,
//&& 
68,68,83,83,  //''
//&& 
69,69,82,82,  //''
//&& 
71,71,80,80,//''
//&& 
72,72,79,79,  //''
74,74,77,77,
75,75,76,76,
77,77,74,74,
78,78,73,73,
80,80,71,71,
81,81,70,70,
//&& 
84,84,67,67,  //''
//&& 86,86,65,65,   number one
88,88,63,63,
89,89,62,62,
91,91,60,60,
92,92,59,59,
94,94,57,57,
95,95,56,56,
97,97,54,54,
98,98,53,53,

500,500,500,500, 
2,2,49,49,
//&& 3,3,48,48,  //''
4,4,47,47,
5,5,46,46,
6,6,45,45,
7,7,44,44,
2,8,49,43,
//&& 3,9,48,42,  //''
4,10,47,41,
5,11,46,40,
6,12,45,39,
7,13,44,38,

501,501,501,501,
600,600,280,280,//¿çÓòÆ«ÒÆ£

18,75,33,75,
//19,76,32,76,  //''
17,77,34,77,
18,78,33,78,
//19,79,32,79,   //''
502,502,502,502,
 };
 
 int J7AGND[][4] ={
0,0,0,0,
8,15,43,36,
9,16,42,35,
10,17,41,34,
11,18,40,33,
12,19,39,32,
20,20,31,31,
//21,21,30,30,  //''
22,22,29,29,
24,23,27,28,
27,24,24,27,
30,27,21,24,
32,30,19,21,
35,32,16,19,
38,35,13,16,
41,38,10,13,
44,41,7,10,
47,44,4,7,
50,47,1,4,
53,50,98,1,
56,53,95,98,
58,56,93,95,
61,58,90,93,
64,61,87,90,
67,64,84,87,
70,67,81,84,
73,70,78,81,
76,73,75,78,
79,76,72,75,
82,79,69,72,
//83,82,68,69,
85,85,66,66,
87,87,64,64,
90,90,61,61,
93,93,58,58,
96,96,55,55,
99,99,52,52,
99,100,52,51,

500,500,500,500,
501,501,501,501,
 };
 int J7Bdata[][4] ={

//Yslot,	Xgoal,	RelyY,	RelyX
	0,0,100,100,
//&& 
	 23,-64,28,164,   //''
26,26,25,25,
27,27,24,24,
31,31,20,20,
32,32,19,19,
34,34,17,17,
35,35,16,16,
37,37,14,14,
38,38,13,13,
40,40,11,11,
41,41,10,10,
43,43,8,8  ,
44,44,7,7  ,
46,46,5,5  ,
47,47,4,4  ,
49,49,2,2  ,
50,50,1,1  ,
52,52,99,99,
53,53,98,98,
55,55,96,96,
57,57,94,94,
58,58,93,93,
60,60,91,91,
61,61,90,90,
63,63,88,88,
64,64,87,87,
66,66,85,85,
67,67,84,84,
//&&
69,69,82,82,  //''
70,70,81,81,
72,72,79,79,
73,73,78,78,
75,75,76,76,
76,76,75,75,
78,78,73,73,
79,79,72,72,
84,84,67,67,
86,86,65,65,
88,88,63,63,
89,89,62,62,
91,91,60,60,
92,92,59,59,
//94,94,57,57,//short
95,95,56,56,
97,97,54,54,
98,98,53,53,

500,500,500,500,
//&& 1,1,50,50,  //
2,2,49,49,
3,3,48,48,
4,4,47,47,
5,5,46,46,
6,6,45,45,
//&& 1,7,50,44, //
2,8,49,43,
//&& 3,9,48,42,
4,10,47,41,
5,11,46,40,
6,12,45,39,
//1,13,50,38,  //
//2,14,49,37,


 501,501,501,501,
 600,600,280,280,//¿çÓòÆ«ÒÆ£

18,75,33,75,
16,76,35,76,
17,77,34,77,
18,78,33,78,
16,79,35,79,
19,1,32,50,
20,2,31,49,
//21,3,30,48  //''
502,502,502,502,
};
int J7BGND[][4]={
0,0,100,100,	
7,14,44,37,
8,15,43,36,
9,16,42,35,
10,17,41,34,
11,18,40,33,
12,19,39,32,
15,20,36,31,
22,21,29,30,
25,22,26,29,
28,23,23,28,
30,24,21,27,
33,25,18,26,
36,28,15,23,
39,30,12,21,
42,33,9,18,
45,36,6,15,
48,39,3,12,
51,42,100,9,
54,45,97,6 ,
56,48,95,3,
59,51,92,100,
62,54,89,97,
65,56,86,95,
68,59,83,92,
71,62,80,89,
74,65,77,86,
77,68,74,83,
80,71,71,80,
83,74,68,77,
83,77,68,74,
85,80,66,71,
85,85,66,66,
87,87,64,64,
87,90,64,61,
90,93,61,58,
93,96,58,55,
96,99,55,52,
99,100,52,51,

500,500,500,500,
501,501,501,501,
};


int TESTPEER(char *str1,char *str2,int testData[][4],int testGnd[][4],char* str3)
{
    
	   int setmove =testData[0][2],i =0;
	   int result =0;
	   int gnd_test_times =4;
		 int vccTimes =3;
	   int store_gnd_right =0;
		 int index_600 =0;
		
	    //2.test gnd line.whether short.
	  gnd_test_times =7;
		for(i=1;testGnd[i][0] !=500;i++)
		{
			result = SetPin(testGnd[i][2] +setmove,testGnd[i][3] +setmove);
			
			if(result >limitResult)
			{
				store_gnd_right =i;
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testGnd[i][0],str2,testGnd[i][1]);
				printf(Table_2);
				
			}
			else
			{
				gnd_test_times-- ;
				if(gnd_test_times ==0)
				{
				  sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testGnd[i][0],str2,testGnd[i][1]);
				  printf(Table_2);
					go_back;
				}
				
			}
		}
		//12V;
		vccTimes =3;
		for(i=1;testData[i][0] !=500;i++);
		for(++i;testData[i][0] !=501;i++)
		{
			result = SetPinPrint(testData[i][2] +setmove,testData[i][3] +setmove);
			
			if(result >limitResult)
			{
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testData[i][1]);
				printf(Table_2);
			}
			else
			{
				vccTimes --;
				if(vccTimes ==0)
				{
					sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testData[i][0],str2,testData[i][1]);
					printf(Table_2);
					go_back;
				}
				
			}
		}
		//j6 -j7 ¿çÓò;
		vccTimes =3;
		for(i=1;testData[i][0] !=501;i++);
		if(testData[i+1][0] ==600)
		{
				i++;
				for(index_600 =i++;testData[i][0] !=502;i++)
				{
					result = SetPinPrint(testData[i][2] +setmove,testData[i][3] +testData[index_600][3]);
					
					if(result >limitResult)
					{
						sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str3,testData[i][1]);
						printf(Table_2);
					}
					else
					{
						vccTimes --;
						if(vccTimes <1)
						{
							sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testData[i][0],str3,testData[i][1]);
							printf(Table_2);
							go_back;
						}
						
					}
				}
		}
	
		//1.test singal line. whether short.
	   for(i=1;testData[i][0] !=500;i++)
		{
			result = SetPin(testData[i][2] +setmove,testData[i][3] +setmove);
			
			if(result >limitResult)
			{
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testData[i][1]);
				printf(Table_2);
			}
			else
			{
				sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testData[i][0],str2,testData[i][1]);
				printf(Table_2);
				go_back;
			}
//			
//			////3.test signal line with the gnd line  .whether open.
			result = SetPin(testData[i][2] +setmove,testGnd[store_gnd_right][3] +setmove);
			if(result < 600) //open then right.
			{
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testGnd[store_gnd_right][1]);
				printf(Table_2);
			}
			else
			{
				sprintf(Table_2, "fail:%s[%3d]%s[%3d]:short\r\n", str1,testData[i][0],str2,testGnd[store_gnd_right][1]);
				printf(Table_2);
				go_back;
			}
			
			//4.test signal line with the near line .whether open.
			if(testData[i+1][3] !=500) 
			{
				result = SetPin(testData[i][2] +setmove,testData[i+1][3] +setmove);
				if(result < 600) //open then right.
				{
					sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testData[i+1][1]);
					printf(Table_2);
				}
				else
				{
					sprintf(Table_2, "fail:%s[%3d]%s[%3d]:short\r\n", str1,testData[i][0],str2,testData[i+1][1]);
					printf(Table_2);
					go_back;
				}
			
			}
		
		}		
		
		//selectYCs(800); 
		return 1;


}
//1.if cap short ,the value will keep the high.if no short,value will slow down step by step.
int testCapWhetherShort(int checkY[][2],int checkX[][2],char* str1)
{
	  int result[16]={0},i=0;
		int usableY =0,usableX =0;
		int status =0;
		for(i=0; i< 4;i++)
		{
			if(SetPin(checkY[i][0],checkY[i][1]) >1200)
				usableY =checkY[i][0];
		}
		for(i=0; i< 4;i++)
		{
			if(SetPin(checkX[i][0],checkX[i][1] )>1200)
				usableX =checkX[i][1];
		}
//		sprintf(Table_2, "will check [%3d][%3d]\r\n",usableY,usableX );printf(Table_2);
		if(usableY ==0 || usableX ==0) 
		{
			sprintf(Table_2, "fail:J7A[  7]J1A[ 12]:open\r\n");
			printf(Table_2);
			return 0;
		}
   					
		for(i=0;i<16;i++)
		{
			result[i] = SetPinDontClose(usableY,usableX);	
//			sprintf(Table_2, "will check [%3d][%3d][%3d]\r\n",usableY,usableX,result[i] );printf(Table_2);
			if(result[0] <1000) {status =1;break;}  //break for ,and ok;
			if(i>0)
			{
				if(result[i-1] >= result[i]+10 || result[i] <250)
				{
					if(i ==14) {status =1;break;} 
				}
				else {
					status =2;break;
				}
			}
//			
		}
		
		if(status ==1) {//pass
			  if(!strcmp(str1,"V12")){
				 sprintf(Table_2, "pass:J7A[  4]J7B[  5]:ok\r\n");
			 }
				if(!strcmp(str1,"V3")){
				 sprintf(Table_2, "pass:J7B[ 17]U1A[ 77]:ok\r\n");
			 }
			 if(!strcmp(str1,"V3AUX")){
				 sprintf(Table_2, "pass:J7B[ 20]U1A[  2]:ok\r\n");
			 }
			 printf(Table_2);
			 return 1;
		}
		else if( status ==2)//fail
		{
			 if(!strcmp(str1,"V12")){
				 sprintf(Table_2, "fail:J7A[  4]J7B[  5]:short\r\n");
			 }
			  if(!strcmp(str1,"V3")){
				 sprintf(Table_2, "fail:J7B[ 17]U1A[ 77]:short\r\n");
			 }
				 if(!strcmp(str1,"V3AUX")){
				 sprintf(Table_2, "fail:J7B[ 20]U1A[  2]:short\r\n");
			 }
			 printf(Table_2);
			 return 0;
		}
		
		return 0;
}

int runMiddle(void)
{
	int result =0;
	result  = runCap();
	if(result ==0) return 0;
	result =TESTPEER("J7A","J1A",J7Adata,J7AGND,"U1B");
	if(result ==0) return 0;
	result =TESTPEER("J7B","J1B",J7Bdata,J7BGND,"J7B");   
	if(result ==0) return 0;
	
	result =TESTPEER("J6A","U1A",J6Adata,J6AGND,"J1A");
	if(result ==0) return 0;
	result =TESTPEER("J6B","U1B",J6Bdata,J6BGND,"J1A");
	if(result ==0) return 0;

	return 1;

}
int runTest(void)
{
	int result =-1;
	result =runMiddle();
	if(result ==0)printf("allfail\r\n");
//	result =runMiddle();
	if(result ==1)printf("allpass\r\n");
}
int runCap(void)
{
	int error =0;
	
  error = testCapWhetherShort(V12data,G_gnd,"V12");
	if(error ==0) return 0;
	error = testCapWhetherShort(V3data,G_gnd,"V3");
	if(error ==0) return 0;
	error = testCapWhetherShort(V3AUXdata,G_gnd,"V3AUX");
	if(error ==0) return 0;
	
}





