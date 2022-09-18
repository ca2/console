#include "acme/_start.h"
#include "acme/_.h"
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


void implement(::acme::system * psystem)
{

   //throw ::exception(error_debug_testing);

   printf("\n");

   printf("\n");

   printf("Hello!!");

   printf("\n");

   printf("\n");

   while (true)
   {

      auto result = message_box_synchronous(psystem, "Hello!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");

      if (result == e_dialog_result_yes)
      {

         printf("\n");

         printf("Yes!!\n");

         message_box_synchronous(psystem, "Yes!!", "Yes!!", e_message_box_ok);

         break;

      }
      else if (result == e_dialog_result_no)
      {

         printf("\n");

         printf("No!\n");

         message_box_synchronous(psystem, "No!", "No!", e_message_box_ok);

      }
      else if (result == e_dialog_result_cancel)
      {

         printf("\n");

         printf("Cancel!!\n");

         message_box_synchronous(psystem, "Cancel", "Cancel", e_message_box_ok);

      }

   }

#ifdef _UWP

   getchar();

   getchar();

#endif

}



