#include "aqua/console.h"
#include "aqua/_defer.h"
#include "aqua/xml.h"


#include "xml.cpp"


::e_status implement(int argc, platform_char ** argv, platform_char** envp)
{

   ::console console(argc, argv, envp);

   ::file::path path;

   if (console.m_psystem->m_argc >= 2)
   {

      path = console.m_psystem->m_argv[1];

   }

   if (path.is_empty())
   {

      path = "dropbox://readlines.txt";

   }

   do_xml_test(console);

   string_array stra;

   //console.m_psystem->get_main_application()->initialize_context();

   //path -= ::file::e_flag_bypass_cache;

   string str = console.m_psystem->file().as_string(path);

   stra.add_lines(str);

   for (auto& str : stra)
   {

      printf("%s\n", str.c_str());

   }

   message_box_for_console(str, "readlines", e_message_box_ok);

   return console.result();

}




