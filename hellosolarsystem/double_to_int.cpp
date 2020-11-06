

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


void double_to_int()
{

   int iLine = 123;

   const char * psz = "1e8abc,1a";

   char* pStoppedHere = nullptr;

   const char* pParse = psz;

   while (*pParse != ',')
   {

      if (!isdigit(*pParse) || *pParse == '.')
      {

         printf("there is a error in line %d", iLine);

         break;

      }

      pParse++;
   }

   double d = strtod(psz, &pStoppedHere);

   if (pStoppedHere != nullptr)
   {

      printf("there is a error in line %d", iLine );

   }


}
