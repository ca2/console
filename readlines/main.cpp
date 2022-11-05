#include "acme/_start.h"
//#include "aqua/_.h"
//#define FACTORY console_readlines
#define NO_NETWORKING
#define APP_ID "console/readlines"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
//#include "apex_windows/_apex_windows.h"
//BEGIN_FACTORY(console_readlines)
//FACTORY_DEPENDENCY(apex_windows)
//END_FACTORY()
#include "aqua/console.h"
#include "apex/filesystem/filesystem/file_context.h"
#include "apex/platform/system.h"
//#include "aqua/_defer.h"


//#include "xml.cpp"


void implement(::acme::context * pcontext)
{

   ::file::path path;

   if (pcontext->acmesystem()->m_psubsystem->m_argc >= 2)
   {

      path = pcontext->acmesystem()->m_psubsystem->m_argv[1];

   }

   if (path.is_empty())
   {

      path = "dropbox-app://readlines.txt";

   }

   //do_xml_test(psystem);

   string_array stra;

   //console.acmesystem()->get_main_application()->initialize_context();

   //path -= ::file::e_flag_bypass_cache;
   
   auto papexsystem = pcontext->acmesystem()->m_papexsystem;
   
   auto pfile = papexsystem->file();

   string str = pfile->as_string(path);

   //stra.add_lines(str);

   //for (auto& str : stra)
   //{

   //   printf("%s\n", str.c_str());

   //}

   message_box_for_console(str, "readlines", e_message_box_ok);

   //return console.result();

}




