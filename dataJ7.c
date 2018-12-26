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
 int J7Adata[][4] ={
0,0,0,0,
25,25,26,26,
26,26,25,25,
28,28,23,23,
29,29,22,22,
29,29,22,22,
33,33,18,18,
34,34,17,17,
36,36,15,15,
37,37,14,14,
39,39,12,12,
40,40,11,11,
42,42,9,9,
43,43,8,8,
45,45,6,6,
46,46,5,5,
48,48,3,3,
49,49,2,2,
51,51,100,100,
52,52,99,99,
54,54,97,97,
55,55,96,96,
57,57,94,94,
59,59,92,92,
60,60,91,91,
62,62,89,89,
63,63,88,88,
65,65,86,86,
66,66,85,85,
68,68,83,83,
69,69,82,82,
71,71,80,80,
72,72,79,79,
74,74,77,77,
75,75,76,76,
77,77,74,74,
78,78,73,73,
80,80,71,71,
81,81,70,70,
84,84,67,67,
86,86,65,65,
88,88,63,63,
89,89,62,62,
91,91,60,60,
92,92,59,59,
94,94,57,57,
95,95,56,56,
97,97,54,54,
98,98,53,53,

500,500,500,500, 
 };
 
 int J7AGND[][4] ={
0,0,0,0,	 
15,8,36,43 ,
16,9,35,42 ,
17,10,34,41,
18,11,33,40,
19,12,32,39,
20,20,31,31,
21,21,30,30,
22,22,29,29,
23,24,28,27,
24,27,27,24,
27,30,24,21,
30,32,21,19,
32,35,19,16,
35,38,16,13,
38,41,13,10,
41,44,10,7,
44,47,7,4,
47,50,4,1,
50,53,1,98 ,
53,56,98,95,
56,58,95,93,
58,61,93,90,
61,64,90,87,
64,67,87,84,
67,70,84,81,
70,73,81,78,
73,76,78,75,
76,79,75,72,
79,82,72,69,
82,83,69,68,
85,85,66,66,
87,87,64,64,
90,90,61,61,
93,93,58,58,
96,96,55,55,
99,99,52,52,
100,99,51,52,

500,500,500,500,
 };
 int J7Bdata[][4] ={

//Yslot,	Xgoal,	RelyY,	RelyX
	0,0,100,100,
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
69,69,82,82,
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
94,94,57,57,
95,95,56,56,
97,97,54,54,
98,98,53,53,

500,500,500,500
 
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

500,500,500,500
};


int TESTPEER(char *str1,char *str2,int testData[][4],int testGnd[][4])
{
    
	   int setmove =testData[0][2],i =0;
	   int result =0;
	   int gnd_test_times =4;
	   int store_gnd_right =0;
		
	    //2.test gnd line.whether short.
	    gnd_test_times =4;
		for(i=1;testGnd[i][0] !=500;i++)
		{
			result = SetPin(testGnd[i][2] +setmove,testGnd[i][3] +setmove);
			
			if(result >1100)
			{
				store_gnd_right =i;
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testGnd[i][0],str2,testGnd[i][1]);
				printf(Table_2);
				
			}
			else
			{
				gnd_test_times -- ;
				if(gnd_test_times ==0)
				{
				  sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testGnd[i][0],str2,testGnd[i][1]);
				  printf(Table_2);
//				  return 0;
				}
				
			}
		}
		//1.test singal line. whether short.
	   for(i=1;testData[i][0] !=500;i++)
		{
			result = SetPin(testData[i][2] +setmove,testData[i][3] +setmove);
			
			if(result >1100)
			{
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testData[i][1]);
				printf(Table_2);
			}
			else
			{
				sprintf(Table_2, "fail:%s[%3d]%s[%3d]:open\r\n", str1,testData[i][0],str2,testData[i][1]);
				printf(Table_2);
			}
			
			////3.test signal line with the next line .whether open.
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
			}
			
			//4.test signal line with the gnd line .whether open.
			result = SetPin(testData[i][2] +setmove,testGnd[i+1][3] +setmove);
			if(result < 600) //open then right.
			{
				sprintf(Table_2, "pass:%s[%3d]%s[%3d]:ok\r\n", str1,testData[i][0],str2,testData[i+1][1]);
				printf(Table_2);
			}
			else
			{
				sprintf(Table_2, "fail:%s[%3d]%s[%3d]:short\r\n", str1,testData[i][0],str2,testData[i+1][1]);
				printf(Table_2);
			}
		}
		
		
		
       		
		
		
		//selectYCs(800); 
		return result;


}
void runTest(void)
{
	TESTPEER("J7A","J1A",J7Adata,J7AGND);
	TESTPEER("J7B","J1B",J7Bdata,J7BGND);   
					
	TESTPEER("J6A","U1A",J6Adata,J6AGND);
	TESTPEER("J6B","U1B",J6Bdata,J6BGND);

}
