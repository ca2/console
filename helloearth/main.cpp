#define NO_DRAW2D
#define NO_IMAGING
#include "aura/console_slim.h"


int main(int argc, wchar_t * argv[])
{

   //console console(argc, argv);

   string strHelloEarth = "Hello Earth!!";

   printf("%s\n", strHelloEarth.c_str());

   press_any_key_to_exit();

   return 0;

   //return console.result();

}



