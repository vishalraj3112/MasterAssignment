#ifndef __typedef_h__
#define __typedef_h__

typedef unsigned char u1;	//1 byte									// typedef bool u1 (for Borland, needs c++), hence used char here
typedef signed char s1;		//1 byte
typedef unsigned char u8;  //1 byte
typedef unsigned short int u16; // 2 bytes
typedef short int s16;			//2 bytes
typedef long signed int s32;	//4 bytes
typedef long unsigned int u32;	//4 bytes
typedef long signed int s64;			// long long not supported in Borland, hence used long
typedef long unsigned int u64;		// long long not supported in Borland, hence used long
typedef float f32;				//4 bytes
typedef double f64;				//8 bytes

/* BIT Definations */
#define BIT(n)  (1<<n)

#define BIT0      (1<<0)
#define BIT1      (1<<1)
#define BIT2      (1<<2)
#define BIT3      (1<<3)
#define BIT4      (1<<4)
#define BIT5      (1<<5)
#define BIT6      (1<<6)
#define BIT7      (1<<7)
#define BIT8      (1<<8)
#define BIT9      (1<<9)
#define BIT10     (1<<10)
#define BIT11     (1<<11)
#define BIT12     (1<<12)
#define BIT13     (1<<13)
#define BIT14     (1<<14)
#define BIT15     (1<<15)
#define BIT16     (1<<16)
#define BIT17     (1<<17)
#define BIT18     (1<<18)
#define BIT19     (1<<19)
#define BIT20     (1<<20)
#define BIT21     (1<<21)
#define BIT22     (1<<22)
#define BIT23     (1<<23)
#define BIT24     (1<<24)
#define BIT25     (1<<25)
#define BIT26     (1<<26)
#define BIT27     (1<<27)
#define BIT28     (1<<28)
#define BIT29     (1<<29)
#define BIT30     (1<<30)
#define BIT31     (1<<31)

#endif
//
