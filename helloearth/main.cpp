#include "acme/console_slim.h"


int main(int argc, wchar_t * argv[])
{

   string strHelloEarth = "Hello Earth!!";

   printf("%s\n", strHelloEarth.c_str());

   string strTest123;

   strTest123 = "Test123";

   printf("Test123=%s\n", strTest123.c_str());

   ::str::begins_eat_ci(strTest123, "test");

   printf("begins_eat_ci(strTest123, \"test\")=%s\n", strTest123.c_str());

   string_array stra;

   stra.add("apple");
   stra.add("orange");
   stra.add("strawberry");

   for (auto& str : stra)
   {

      printf("a fruit: %s\n", str.c_str());

   }



   press_any_key_to_exit();

   return 0;

}



