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

   auto pfuture = __sync_future();

   os_message_box(str, "readlines", e_message_box_ok, pfuture);

   pfuture->wait(8_s);

   return console.result();

}




