#include "framework.h"
#include "application.h"
#include "aqua/console.h"


void application_main()
{

   console_readlines::application application;

   auto iExitCode = application.application_main();

   return iExitCode;

}


