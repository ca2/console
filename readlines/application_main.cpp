#include "framework.h"
#include "application.h"
#include "aqua/console.h"


::i32 application_main(::platform::platform * pplatform)
{

   auto papplication = __allocate< console_readlines::application >();

   auto iExitCode = papplication->application_main(pplatform);

   return iExitCode;

}


