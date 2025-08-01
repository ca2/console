//#include <ctype.h>
//#include <stdio.h>
//#include <stdlib.h>


void double_to_int()
{

   int iLine = 123;

   const_char_pointer psz = "1e8abc,1a";

   char* pStoppedHere = nullptr;

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

   double d = strtod(scopedstr, &pStoppedHere);

   if (pStoppedHere != nullptr)
   {

      printf("there is a error in line %d", iLine );

   }

   printf("This is the double value %f", d);

}
