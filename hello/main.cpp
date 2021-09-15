#include "acme/console.h"


void print(const char * psz);

class automobile
{
public:

   int m_iWheelCount;


};


class runnable
{
public:

   virtual void run() = 0;

};


template < typename PREDICATE >
class runnable_predicate :
   public runnable
{
public:

   PREDICATE m_predicate;


   runnable_predicate(PREDICATE predicate):
      m_predicate(predicate)
   {

      

   }


   virtual void run()
   {

      m_predicate();

   }

};

template < typename PREDICATE >
runnable * __runnable(PREDICATE predicate) { return new runnable_predicate < PREDICATE >(predicate); }


template < typename PREDICATE >
void call_predicate(PREDICATE predicate)
{

   predicate();

}



void call(runnable * prunnable)
{

   prunnable->run();

}

template < typename PREDICATE >
void call_predicate_with_random_int(PREDICATE predicate)
{

   predicate(rand());

}


void implement(class ::system * psystem)
{

   int iLocal = 5;

   auto lambda = [iLocal]() 
   {
      
      printf("\n\nthis is called inside a lambda (a local function/a function declared inline) %d", iLocal); 
   
   };


   call(__runnable(lambda));


   call_predicate(lambda);

   
   auto lambda_with_int_arguemnt = [=](int i) 
   {
      
      printf("\n\nthis is called inside a lambda with int argument with value %d\n\n", i + iLocal); 
   
   };

   
   call_predicate_with_random_int(lambda_with_int_arguemnt);


   print("before hello...\n");

   printf("Hello!!");


   payload payload;

   payload = 1;

   payload = "test";

#ifdef _UWP

   getchar();

   getchar();

#endif

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

   automobile * pautomobile = (automobile *) &i2;

   //const char * p2 = (const char *) &i2;

   pautomobile->m_iWheelCount = 33;

   printf("%s", (const char *)pautomobile);

}
