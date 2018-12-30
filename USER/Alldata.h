#ifndef ALLDATA_H
#define ALLDATA_H

 extern  int J7Bdata[][4];
 extern  int J7BGND[][4];
 extern  int J7Adata[][4];
 extern  int J7AGND[][4];
 
 extern  int J6Adata[][4];
 extern  int J6AGND[][4];
 extern  int J6Bdata[][4];
 extern  int J6BGND[][4];
 extern  int TESTPEER(char *str1,char *str2,int testData[][4],int testGnd[][4],char* str3);
 extern  int runCap(void);
 extern  int runTest(void);
 
#endif

