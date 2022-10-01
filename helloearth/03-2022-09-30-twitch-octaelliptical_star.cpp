#include "framework.h"
#include <iostream>


using namespace std;


int twitch::octaelliptical_star_main() 
{
   printf("Star Line Count? (negative for something else...)");
   int n;
   cin >> n;
   if (n < 0)
   {

      return n;

   }
   int extraline = (n % 2) == 0;
   n /=2;
   if (!extraline)
   {
      n++;
   }
   int a = 1;
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

   if (extraline)
   {
      a--;
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