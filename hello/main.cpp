#include "acme/console.h"


void print(const char * psz);


void implement(class ::system * psystem)
{

   print("before hello...\n");

   printf("Hello!!");



}


void print(const char * psz)
{

   //int b = psz[0]; /// hex62 dec98

   //int e = psz[1]; // hex65 dec101

   int * p = (int *)(psz);

   //int i = p[0]; // 98,101,'f','o'

   int i2 = 98 + 101 * 256; // 0x00006562
   //int null_terminator = psz[16];

   printf("%s", (const char *)p);
   printf("%s",(const char *)&i2);

}
