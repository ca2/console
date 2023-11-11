#include "framework.h"
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
#include "acme/filesystem/filesystem/file_context.h"
#include "apex/platform/system.h"
//#include "aqua/_defer.h"


//#include "xml.cpp"
class console_readlines :
   virtual public ::aqua::application
{
public:


   console_readlines()
   {

      m_bNetworking = false;

      m_bCrypto = false;

      m_bResource = false;

      m_strAppId = "console/readlines";

   }


   void main() override
   {

      ::file::path path;

      if (platform()->m_argc >= 2)
      {

         path = platform()->m_argv[1];

      }

      if (path.is_empty())
      {

         path = "dropbox-app://readlines.txt";

      }

      //do_xml_test(psystem);

      string_array stra;

      //console.system()->get_main_application()->initialize_context();

      //path -= ::file::e_flag_bypass_cache;

      auto papexsystem = system()->m_papexsystem;

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


};


//console_readlines g_consolereadlines;
//
//



::i32 application_main()
{

   auto papplication = __new(console_readlines::application);

   auto iExitCode = papplication->application_main();

   return iExitCode;

}


