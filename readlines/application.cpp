#include "framework.h"
#include "application.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "apex/platform/system.h"


IMPLEMENT_APPLICATION_FACTORY(console_readlines);

enum_dialog_result message_box_for_console(const ::scoped_string & scopedstr, const ::scoped_string & scopedstrTitle, const ::enum_message_box & emessagebox);

namespace console_readlines
{
   
   application::application()
   {

      m_bNetworking = false;

      //m_bCrypto = false;

      m_bResource = false;

      m_strAppId = "console/readlines";

   }


   application::~application()
   {


   }


   void application::main()
   {

      ::file::path path;

      if (platform()->m_argc >= 2)
      {

         path = platform()->m_args[1];

      }

      if (path.is_empty())
      {

         path = "dropbox-app://readlines.txt";

      }

      //do_xml_test(psystem);

      string_array_base stra;

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


} // namespace console_readlines



