#include "framework.h"
#include <iostream>


using namespace std;



//Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
//F(n) = F(n - 1) + F(n - 2),
//Where, F(1) = 1,
//F(2) = 1


::i64 IterativeFibonacci(int iFibonacci);


int twitch::octaelliptical_iterative_fibonacci_main() 
{

   printf("Iterative Fibonacci of? (0 or negative to exit)");

   int n;

   cin >> n;

   if (n <= 0)
   {

      cout << "exiting iterative fibonacci...";

      return -1;

   }

   auto iFibonacci = IterativeFibonacci(n);

   cout << "Fibonacci of " << n << " is " << iFibonacci << endl;

   return 0;

}



::i64 IterativeFibonacci(int n)
{

   ::i64 iFibonacci;

   if (n == 1)
   {

      iFibonacci = 1; // Fibonacci(1) = 1;

   }
   else if (n == 2)
   {

      iFibonacci = 1; // Fibonacci(2) = 1;

   }
   else
   {

      int iFibonacci_of_n_minus_1 = 1;

      int iFibonacci_of_n_minus_2 = 1;

      int nCurrent = 3;

      while (true)
      {

         iFibonacci = iFibonacci_of_n_minus_1 + iFibonacci_of_n_minus_2;

         if (nCurrent >= n)
         {

            break;

         }

         iFibonacci_of_n_minus_2 = iFibonacci_of_n_minus_1;

         iFibonacci_of_n_minus_1 = iFibonacci;

         nCurrent++;

      }

   }

   return iFibonacci;

}



