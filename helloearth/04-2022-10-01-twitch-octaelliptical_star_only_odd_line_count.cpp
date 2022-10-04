#include "framework.h"
#include <iostream>


using namespace std;


int twitch::octaelliptical_star_main_only_odd_count_main() 
{
   printf("Star Line Count (Odd Line number output only and negative for exiting...)");
   //int n;
   //cin >> n;
   //if (n < 0)
   //{

   //   return n;

   //}
   //n /=2;
   //int a = 1;
   //while (a <= n) {
   //   int k = 1;
   //   while (k <= n - a) {
   //      cout << " ";
   //      k++;
   //   }

   //   int j = 1;
   //   while (j <= 2 * a - 1) {
   //      cout << "*";
   //      j++;
   //   }

   //   cout << endl;
   //   a++;
   //}


   //int i = n - 1;
   //while (i >= 1) {
   //   int p = 1;
   //   while (p <= n - i) {
   //      cout << " ";
   //      p++;
   //   }
   //   int c = 1;
   //   while (c <= 2 * i - 1) {
   //      cout << "*";
   //      c++;
   //   }


   //   cout << endl;
   //   i--;

   //}



   int n;
   cin >> n;
   bool bEven = (n % 2) == 0;
   if (bEven)
   {

      cout << "(No output for even line count)\n";
      return 0;
   }
   bool bOdd = !bEven;
   n /= 2;
   if (bOdd)
   {
      n++;
   }
   int a = 1;
   //if (extraline)
   //{
   //   a--;

   //}
   while (a <= n) {
      int k = 1;
      while (k <= n - a) {
         cout << " ";
         k++;
      }

      int j = 1;
      while (j <= 2 * a - 1) {
         cout << "*";
         j++;
      }

      cout << endl;
      a++;
   }



   int i = n - 1;
   while (i >= 1) {
      int p = 1;
      while (p <= n - i) {
         cout << " ";
         p++;
      }
      int c = 1;
      while (c <= 2 * i - 1) {
         cout << "*";
         c++;
      }


      cout << endl;
      i--;

   }

   return 0;
}