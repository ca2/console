#include "acme/_start.h"
//#include "apex/_.h"
#define FACTORY console_hello
#define __APP_ID "console/hello"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
//#include "acme_windows/_acme_windows.h"
//BEGIN_FACTORY(console_hello)
//FACTORY_DEPENDENCY(acme_windows)
//END_FACTORY()
#include "acme/console.h"


void implement(::platform::context * pcontext)
{

   ::file::path path = "C:/basis/operating_system/tool-windows/headless_monitor/deviceinstaller64.exe";

   pcontext->os_context()->file_open(path, "enableidd 1");

}



