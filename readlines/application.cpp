#include "framework.h"
#include "application.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "apex/platform/system.h"



console_readlines::console_readlines()
{

   m_bNetworking = false;

   m_bCrypto = false;

   m_bResource = false;

   m_strAppId = "console/readlines";

}


void console_readlines::main() 
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

   auto papexsystem = system();

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


