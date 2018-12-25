//#include <intrins.h>
//#include "sys.h"
#include  <string.h>
//u8 mbuf99[33];//="AE020B19162C01A801F1FA5E341988";
//char *Str;
//u8 mbufID[3000];

//-----------------------------------------------------------------------------------------------------
//别名区    ADDRESS=0x4200 0000 + (0x0001 100C*0x20) + (bitx*4) ;bitx:第x位
// 把“位段地址＋位序号”转换别名地址宏
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
//把该地址转换成一个指针
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)  MEM_ADDR( BITBAND(addr, bitnum)  )
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x4001180C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x4001180C
#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011808
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011808
//-----------------------------------------------------
#define PA0  BIT_ADDR(GPIOA_ODR_Addr, 0)  //输出
#define A1  BIT_ADDR(GPIOA_ODR_Addr, 1)  //输出
#define B1  BIT_ADDR(GPIOA_ODR_Addr, 2)  //输出
#define C1  BIT_ADDR(GPIOA_ODR_Addr, 3)  //输出
#define A2  BIT_ADDR(GPIOA_ODR_Addr, 4)  //输出
#define B2  BIT_ADDR(GPIOA_ODR_Addr, 5)  //输出
#define C2  BIT_ADDR(GPIOA_ODR_Addr, 6)  //输出
#define PA7  BIT_ADDR(GPIOA_ODR_Addr, 7)  //输出
#define PA8  BIT_ADDR(GPIOA_ODR_Addr, 8)  //输出
#define PA9  BIT_ADDR(GPIOA_ODR_Addr, 9)  //输出
#define PA10  BIT_ADDR(GPIOA_ODR_Addr, 10) //输出
#define PA11  BIT_ADDR(GPIOA_ODR_Addr, 11) //输出
#define PA12  BIT_ADDR(GPIOA_ODR_Addr, 12) //输出
#define PA13  BIT_ADDR(GPIOA_ODR_Addr, 13) //输出
#define PA14  BIT_ADDR(GPIOA_ODR_Addr, 14) //输出
#define PA15  BIT_ADDR(GPIOA_ODR_Addr, 15) //输出

//---------------define x output --------------------------
#define CSX1  BIT_ADDR(GPIOB_ODR_Addr, 0)  //输出
#define CSX2  BIT_ADDR(GPIOB_ODR_Addr, 1)  //输出
#define CSX3  BIT_ADDR(GPIOB_ODR_Addr, 2)  //输出
#define CSX4  BIT_ADDR(GPIOB_ODR_Addr, 3)  //输出
#define CSX5  BIT_ADDR(GPIOB_ODR_Addr, 4)  //输出
#define CSX6  BIT_ADDR(GPIOC_ODR_Addr, 10)  //输出
#define CSX7  BIT_ADDR(GPIOC_ODR_Addr, 11)  //输出
#define CSX8  BIT_ADDR(GPIOC_ODR_Addr, 12)  //输出
#define CSX9  BIT_ADDR(GPIOB_ODR_Addr, 8)  //输出
#define CSX10  BIT_ADDR(GPIOB_ODR_Addr, 9)  //输出
#define CSX11  BIT_ADDR(GPIOB_ODR_Addr, 10) //输出
#define CSX12  BIT_ADDR(GPIOB_ODR_Addr, 11) //输出
#define CSX13  BIT_ADDR(GPIOB_ODR_Addr, 12) //输出
#define CSX14  BIT_ADDR(GPIOB_ODR_Addr, 13) //输出
#define CSX15  BIT_ADDR(GPIOB_ODR_Addr, 14) //输出
#define CSX16  BIT_ADDR(GPIOB_ODR_Addr, 15) //输出
//----------------------------------------------------
#define CSX17  BIT_ADDR(GPIOD_ODR_Addr, 0)  //输出
#define CSX18  BIT_ADDR(GPIOD_ODR_Addr, 1)  //输出
#define CSX19  BIT_ADDR(GPIOD_ODR_Addr, 2)  //输出
#define CSX20  BIT_ADDR(GPIOD_ODR_Addr, 3)  //输出
#define CSX21  BIT_ADDR(GPIOD_ODR_Addr, 4)  //输出
#define CSX22  BIT_ADDR(GPIOD_ODR_Addr, 5)  //输出
#define CSX23  BIT_ADDR(GPIOD_ODR_Addr, 6)  //输出
#define CSX24  BIT_ADDR(GPIOD_ODR_Addr, 7)  //输出
#define CSX25  BIT_ADDR(GPIOD_ODR_Addr, 8)  //输出
#define CSX26  BIT_ADDR(GPIOD_ODR_Addr, 9)  //输出
#define CSX27  BIT_ADDR(GPIOD_ODR_Addr, 10) //输出
#define CSX28  BIT_ADDR(GPIOD_ODR_Addr, 11) //输出
#define CSX29  BIT_ADDR(GPIOD_ODR_Addr, 12) //输出
#define CSX30  BIT_ADDR(GPIOD_ODR_Addr, 13) //输出
#define CSX31  BIT_ADDR(GPIOD_ODR_Addr, 14) //输出
#define CSX32  BIT_ADDR(GPIOD_ODR_Addr, 15) //输出
//----------------------------------------------------
#define CSX33  BIT_ADDR(GPIOF_ODR_Addr, 0)  //输出
#define CSX34  BIT_ADDR(GPIOF_ODR_Addr, 1)  //输出
#define CSX35  BIT_ADDR(GPIOF_ODR_Addr, 2)  //输出
#define CSX36  BIT_ADDR(GPIOF_ODR_Addr, 3)  //输出
#define CSX37  BIT_ADDR(GPIOF_ODR_Addr, 4)  //输出
#define CSX38  BIT_ADDR(GPIOF_ODR_Addr, 5)  //输出
#define CSX39  BIT_ADDR(GPIOF_ODR_Addr, 6)  //输出
#define CSX40  BIT_ADDR(GPIOF_ODR_Addr, 7)  //输出
#define CSX41  BIT_ADDR(GPIOF_ODR_Addr, 8)  //输出
#define CSX42  BIT_ADDR(GPIOF_ODR_Addr, 9)  //输出
#define CSX43  BIT_ADDR(GPIOF_ODR_Addr, 10) //输出
#define CSX44  BIT_ADDR(GPIOF_ODR_Addr, 11) //输出
#define CSX45  BIT_ADDR(GPIOF_ODR_Addr, 12) //输出


//---------------------define Y output -----------------------
#define CSY1  BIT_ADDR(GPIOC_ODR_Addr, 0)  //输出
#define CSY2  BIT_ADDR(GPIOC_ODR_Addr, 1)  //输出
#define CSY3  BIT_ADDR(GPIOC_ODR_Addr, 2)  //输出
#define CSY4  BIT_ADDR(GPIOC_ODR_Addr, 3)  //输出
#define CSY5  BIT_ADDR(GPIOC_ODR_Addr, 4)  //输出
#define CSY6  BIT_ADDR(GPIOC_ODR_Addr, 5)  //输出
#define CSY7  BIT_ADDR(GPIOC_ODR_Addr, 6)  //输出
#define CSY8  BIT_ADDR(GPIOC_ODR_Addr, 7)  //输出
#define CSY9  BIT_ADDR(GPIOC_ODR_Addr, 8)  //输出
#define CSY10  BIT_ADDR(GPIOC_ODR_Addr, 9)  //输出
#define CSY11  BIT_ADDR(GPIOB_ODR_Addr, 5) //输出
#define CSY12  BIT_ADDR(GPIOB_ODR_Addr, 6) //输出
#define CSY13  BIT_ADDR(GPIOB_ODR_Addr, 7) //输出
#define CSY14  BIT_ADDR(GPIOC_ODR_Addr, 13) //输出
#define CSY15  BIT_ADDR(GPIOC_ODR_Addr, 14) //输出
#define CSY16  BIT_ADDR(GPIOC_ODR_Addr, 15) //输出

//----------------------------------------------------
#define CSY17  BIT_ADDR(GPIOE_ODR_Addr, 0)  //输出
#define CSY18  BIT_ADDR(GPIOE_ODR_Addr, 1)  //输出
#define CSY19  BIT_ADDR(GPIOE_ODR_Addr, 2)  //输出
#define CSY20  BIT_ADDR(GPIOE_ODR_Addr, 3)  //输出
#define CSY21  BIT_ADDR(GPIOE_ODR_Addr, 4)  //输出
#define CSY22  BIT_ADDR(GPIOE_ODR_Addr, 5)  //输出
#define CSY23  BIT_ADDR(GPIOE_ODR_Addr, 6)  //输出
#define CSY24  BIT_ADDR(GPIOE_ODR_Addr, 7)  //输出
#define CSY25  BIT_ADDR(GPIOE_ODR_Addr, 8)  //输出
#define CSY26  BIT_ADDR(GPIOE_ODR_Addr, 9)  //输出
#define CSY27  BIT_ADDR(GPIOE_ODR_Addr, 10) //输出
#define CSY28  BIT_ADDR(GPIOE_ODR_Addr, 11) //输出
#define CSY29  BIT_ADDR(GPIOE_ODR_Addr, 12) //输出
#define CSY30  BIT_ADDR(GPIOE_ODR_Addr, 13) //输出
#define CSY31  BIT_ADDR(GPIOE_ODR_Addr, 14) //输出
#define CSY32  BIT_ADDR(GPIOE_ODR_Addr, 15) //输出


//----------------------------------------------------
#define CSY33  BIT_ADDR(GPIOG_ODR_Addr, 0)  //输出
#define CSY34  BIT_ADDR(GPIOG_ODR_Addr, 1)  //输出
#define CSY35  BIT_ADDR(GPIOG_ODR_Addr, 2)  //输出
#define CSY36  BIT_ADDR(GPIOG_ODR_Addr, 3)  //输出
#define CSY37  BIT_ADDR(GPIOG_ODR_Addr, 4)  //输出
#define CSY38  BIT_ADDR(GPIOG_ODR_Addr, 5)  //输出
#define CSY39  BIT_ADDR(GPIOG_ODR_Addr, 6)  //输出
#define CSY40  BIT_ADDR(GPIOG_ODR_Addr, 7)  //输出
#define CSY41  BIT_ADDR(GPIOG_ODR_Addr, 8)  //输出
#define CSY42  BIT_ADDR(GPIOG_ODR_Addr, 9)  //输出
#define CSY43  BIT_ADDR(GPIOF_ODR_Addr, 13) //输出
#define CSY44  BIT_ADDR(GPIOF_ODR_Addr, 14) //输出
#define CSY45  BIT_ADDR(GPIOF_ODR_Addr, 15) //输出
