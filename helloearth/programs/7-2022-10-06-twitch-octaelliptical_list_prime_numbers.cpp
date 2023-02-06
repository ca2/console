#include "framework.h"
#include <iostream>

using namespace std;

inline int remainder_of_division(int iNumerator, int iDenominator)
{

   return iNumerator % iDenominator;

}

inline bool is_divisible(int iCandidate, int iDivisor)
{

   return remainder_of_division(iCandidate, iDivisor) == 0;

}

inline bool is_prime(int iCandidate)
{

   bool bHasOtherDivisorThenOneAndItSelf = false;

   // Check how many numbers less or equal than iNumberToCheckIfItIsPrime are divisors of iNumberToCheckIfItIsPrime

   for (int iTestingDivisor = 2; !bHasOtherDivisorThenOneAndItSelf && iTestingDivisor < iCandidate; iTestingDivisor++)
   {

      bHasOtherDivisorThenOneAndItSelf = is_divisible(iCandidate, iTestingDivisor);

   }

   return !bHasOtherDivisorThenOneAndItSelf;

}

int twitch::octaelliptical_list_prime_numbers_main()
{

   printf("List prime numbers less or equal the input number (0 or less to exit...) \n");
   
   int iLastNumberToCheckIfItIsPrime;
   
   cin >> iLastNumberToCheckIfItIsPrime;

   if (iLastNumberToCheckIfItIsPrime <= 0)
   {

      return -1;

   }

   for (int iCandidate = 1; iCandidate <= iLastNumberToCheckIfItIsPrime; iCandidate++)
   {
      
      if (is_prime(iCandidate))
      {

         int iPrime = iCandidate;

         cout << endl;

         cout << iPrime;

      }

   }

   return 0;

}




