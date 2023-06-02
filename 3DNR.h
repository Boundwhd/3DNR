#ifndef _3DNR_H_
#define _3DNR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;

int* min_noise(int block[16][16]);
int add(int a,int b);
#endif

