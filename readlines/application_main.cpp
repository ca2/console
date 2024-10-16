#include "framework.h"
#include "application.h"
#include "aqua/console.h"


void application_main()
{

   auto papplication = __new console_readlines::application();

   auto iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}


