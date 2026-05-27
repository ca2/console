//#include <ctype.h>
//#include <stdio.h>
//#include <stdlib.h>


void f64_to_int()
{

   int iLine = 123;

   const_char_pointer psz = "1e8abc,1a";

   ::i8* pStoppedHere = nullptr;

   const_char_pointer pParse = psz;

   while (*pParse != ',')
   {

      if (!isdigit(*pParse) || *pParse == '.')
      {

         printf("there is a error in line %d", iLine);

         break;

      }

      pParse++;
   }

   ::f64 d = strtod(scopedstr, &pStoppedHere);

   if (pStoppedHere != nullptr)
   {

      printf("there is a error in line %d", iLine );

   }

   printf("This is the ::f64 value %f", d);

}
