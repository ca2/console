
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include "framework.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include <iostream>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#define INT_STR_SIZE (sizeof(int64_t)*CHAR_BIT + 2)


using namespace std;

::u64 pow2(int iBits)
{
   ::u64 u = 1;
   while (iBits-- > 0) u *= 2;
   return u;
}

int integer_log_base_2(::u64 u)
{
   int iBits = 0;
   while (u >>= 1) ++iBits;
   return iBits;
}
::u64 intpow(int iBase,  int iBits)
{
   ::u64 u = 1;
   while (iBits-- > 0) u *= iBase;
   return u;
}


int logpow2(int iBase, ::u64 u)
{
   int iShift = integer_log_base_2(iBase);
   int l = 0;
   while (u >>= iShift) ++l;
   return l;
}

int ceillogpow2(int iBase, ::u64 u)
{
   int iShift = integer_log_base_2(iBase);
   int l = 0;
   auto uOriginal = u;
   while (u >>= iShift) ++l;
   auto diff = uOriginal - intpow(iBase, l);
   return l + (diff>0? 1: 0);
}

bool is_pow2(::u64 u)
{
   return !(u & (u - 1));
}

::i64 bits_maximum_signed(int iBits)
{
 
   return pow2(iBits - 1) - 1;

}

::u64 bits_maximum_signed_unsigned(int iBits)
{

   return pow2(iBits - 1) + 1;

}


int signed_maximum_number_of_digits(int iBase, int iBits)
{

   if (is_pow2(iBase))
   {
      return ceillogpow2(iBase, pow2(iBits-1) + 1) + 1;
   }
   else
   {

      auto p = (double)bits_maximum_signed_unsigned(iBits);
      auto logmax = log(p);
      auto logbase = log((double)iBase);
      auto digits = logmax / logbase;
      return (int) (ceil(digits) + 1);

   }

}

int unsigned_maximum_number_of_digits(int iBase, int iBits)
{

   return (int) ceil(log(pow(2.0, (double)(iBits))-1.0) / log((double)iBase));

}

static char * my_utoa_base_helper(char * dest, size_t size, uint64_t x, int base) {
   if (size == 0) return NULL;
   int digit = (x % base);
   x /= base;
   if (x) {
      dest = my_utoa_base_helper(dest, size - 1, x, base);
      if (dest == NULL) return NULL;
   }
   *dest = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[digit];
   return dest + 1;
}

char * my_utoa_base(char * dest, size_t size, uint64_t x, int base) {
   if (base < 2 || base > 36 || size < 2) return NULL;
   char * p = dest;
   p = my_utoa_base_helper(p, size - 1, x, base);
   if (p == NULL) return NULL;
   *p = '\0';
   return dest;
}

static char * my_itoa_base_helper(char * dest, size_t size, int64_t x, int base) {
   if (size == 0) return NULL;
   int digit = -(x % base);
   x /= base;
   if (x) {
      dest = my_itoa_base_helper(dest, size - 1, x, base);
      if (dest == NULL) return NULL;
   }
   *dest = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[digit];
   return dest + 1;
}

char * my_itoa_base(char * dest, size_t size, int64_t x, int base) {
   if (base < 2 || base > 36 || size < 2) return NULL;
   char * p = dest;
   if (x < 0) {
      *p++ = '-';
      size--;
   }
   else {
      x = -x;
   }
   p = my_itoa_base_helper(p, size - 1, x, base);
   if (p == NULL) return NULL;
   *p = '\0';
   return dest;
}

// compound literal C99 or later
#define MY_ITOA_BASE(x,base) my_itoa_base((char [INT_STR_SIZE]){""}, INT_STR_SIZE,(x),(base))

int twitch::ca2software_int_to_string_bases()
{
   ::string str;
   ::string strTable;
      //str.append_formatf("Hello World");


   for (int i = 'a'; i <= 'z'; i++)
   {

      //str.append_formatf("max character '%c' - base: %d\n", i, i- 'a' + 11 );

   }


   int bases[40];
   strTable.append_formatf("int iaBaseLog[8][] = {\n");
   int iBits;
   int iMaximumDigits1;
   int iMaximumDigits2;
   int iMaximumDigits3;
   int iMaximumDigits4;
   for (int iBase = 2; iBase <= 36; iBase++)
   {
      if (iBase > 2)
      {

         strTable += ",\n";

      }
      bases[iBase] = (int)ceil(log((double)2) * 1000.0 / log((double)iBase));
      str.append_formatf("%2d\n", iBase);
      char sz[1024];
      char sz1[1024];
      char sz2[1024];

      strTable += "{";

      iBits = sizeof(char) *8;
      my_itoa_base(sz1, sizeof(sz1), CHAR_MAX, iBase);
      iMaximumDigits1 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("            char %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(char) / 100), iMaximumDigits1, sz1, (int)strlen(sz1));
      my_utoa_base(sz2, sizeof(sz2), CHAR_MAX, iBase);
      iMaximumDigits2 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(char) / 100), iMaximumDigits2, sz2, (int)strlen(sz2));
      if (strcmp(sz1, sz2) == 0)
      {
         //   str.append_formatf("OK\n");
      }
      else
      {
         str.append_formatf("ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), CHAR_MIN, iBase);
      iMaximumDigits3 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(char) / 100), iMaximumDigits3, sz, (int)strlen(sz));
      if (iMaximumDigits3 == strlen(sz))
      {
         str.append_formatf("OK2\n");
      }
      else
      {
         str.append_formatf("ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM 2ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALAR2M ALARM2 ALARM2 ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), CHAR_MIN, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      my_itoa_base(sz, sizeof(sz), UCHAR_MAX, iBase);
      iMaximumDigits4 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(char) / 100), iMaximumDigits4, sz, (int)strlen(sz));
      strTable.append_formatf("%d, ", strlen(sz));


      iBits = sizeof(short) *8;
      my_itoa_base(sz1, sizeof(sz1), SHRT_MAX, iBase);
      iMaximumDigits1 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("           short %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(short) / 100), iMaximumDigits1, sz1, (int)strlen(sz1));
      my_utoa_base(sz2, sizeof(sz2), SHRT_MAX, iBase);
      iMaximumDigits2 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(short) / 100), iMaximumDigits2, sz2, (int)strlen(sz2));
      if (strcmp(sz1, sz2) == 0)
      {
         //str.append_formatf("OK\n");
      }
      else
      {
         str.append_formatf("ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), SHRT_MIN, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      iMaximumDigits3 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(short) / 100), iMaximumDigits3, sz, (int)strlen(sz));
      if (iMaximumDigits3 == strlen(sz))
      {
         str.append_formatf("OK2\n");
      }
      else
      {
         str.append_formatf("ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM 2ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALAR2M ALARM2 ALARM2 ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), USHRT_MAX, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      iMaximumDigits4 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(short) / 100), iMaximumDigits4, sz, (int)strlen(sz));




      iBits = sizeof(int) * 8;
      my_itoa_base(sz1, sizeof(sz1), INT_MAX, iBase);
      iMaximumDigits1 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("             int %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int) / 100), iMaximumDigits1, sz1, (int)strlen(sz2));
      my_utoa_base(sz2, sizeof(sz2), INT_MAX, iBase);
      iMaximumDigits2 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int) / 100), iMaximumDigits2, sz1, (int)strlen(sz2));
      if (strcmp(sz1, sz2) == 0)
      {
         //str.append_formatf("OK\n");
      }
      else
      {
         str.append_formatf("ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), INT_MIN, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      iMaximumDigits3 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int) / 100), iMaximumDigits3, sz, (int)strlen(sz));
      if (iMaximumDigits3 == strlen(sz))
      {
         str.append_formatf("OK2\n");
      }
      else
      {
         str.append_formatf("ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM 2ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALAR2M ALARM2 ALARM2 ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), UINT_MAX, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      iMaximumDigits4 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int) / 100), iMaximumDigits4, sz, (int)strlen(sz));




      iBits = sizeof(::i64) * 8;
      my_itoa_base(sz1, sizeof(sz1), INT64_MAX, iBase);
      iMaximumDigits1 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("   long long int %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int64_t) / 100), iMaximumDigits1, sz1, (int)strlen(sz2));
      my_utoa_base(sz2, sizeof(sz2), INT64_MAX, iBase);
      iMaximumDigits2 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int64_t) / 100), iMaximumDigits2, sz1, (int)strlen(sz2));
      if (strcmp(sz1, sz2) == 0)
      {
         //str.append_formatf("OK\n");
      }
      else
      {
         str.append_formatf("ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM ALARM\n");
      }
      my_itoa_base(sz, sizeof(sz), INT64_MIN, iBase);
      strTable.append_formatf("%d, ", strlen(sz));
      iMaximumDigits3 = signed_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int64_t) / 100), iMaximumDigits3, sz, (int)strlen(sz));
      if (iMaximumDigits3 == strlen(sz))
      {
         str.append_formatf("OK2\n");
      }
      else
      {
         str.append_formatf("ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALARM 2ALARM2 ALARM2 ALARM2 ALARM2 ALARM2 ALAR2M ALARM2 ALARM2 ALARM ALARM\n");
      }
      my_utoa_base(sz, sizeof(sz), UINT64_MAX, iBase);
      strTable.append_formatf("%d ", strlen(sz));
      iMaximumDigits4 = unsigned_maximum_number_of_digits(iBase, iBits);
      str.append_formatf("                 %2d (%2d) %s len=%2d\n", (int)(bases[iBase] * sizeof(int64_t) / 100), iMaximumDigits4, sz, (int)strlen(sz));
      str.append_formatf("%4d,\n", bases[iBase]);

      strTable += "}";
   }
   strTable.append_formatf("};");

   ::information(str);


   acmefile()->put_contents("C:\\archive\\int_to_string_bases.txt", str);
   acmefile()->put_contents("C:\\main\\source\\app\\acme\\primitive\\mathematics\\int_to_string_bases_table.dynamically_generated", strTable);

   //getchar();

   return 0;
}



