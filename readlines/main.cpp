#include "apex/console_slim.h"
#include "apex/_defer.h"


int main(int argc, char * argv[])
{

   ::console console(argc, argv);

   ::file::path path;

   if (System.m_argc >= 2)
   {

      path = System.m_argv[1];

   }

   if (path.is_empty())
   {

      path = "dropbox://readlines.txt";

   }

   string_array stra;

   Application.initialize_context();

   string str = Application.file().as_string(path);

   stra.add_lines(str);

   for (auto& str : stra)
   {

      printf("%s\n", str.c_str());

   }

   sync_future sync;

   os_message_box(str, "readlines", message_box_ok, sync);

   sync.m_event.wait(4_s);

   return console.result();

}




