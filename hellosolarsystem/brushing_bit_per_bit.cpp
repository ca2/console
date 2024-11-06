#pragma once
// 2020-10-20 Oliver Pohl (but he was distracted)

#pragma pack(push, pair1, 1)

struct pair1
{

   unsigned char b1;
   int i1;


};

#pragma pack(pop, pair1)


struct pair2
{
   unsigned char b1;
   int i2;



};

void brushing_bit_per_bit()
{

   int iSize1 = sizeof(pair1);
   int iSize2 = sizeof(pair2);
 
   printf("size1=%d size2=%d", iSize1, iSize2);
}
