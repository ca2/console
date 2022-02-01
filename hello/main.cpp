#include "acme/_start.h"
#include "acme/_.h"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
#include "acme/console.h"


void implement(class ::system * psystem)
{

   printf("\n");

   printf("\n");

   printf("Hello!!");

   printf("\n");

   printf("\n");

   auto result = os_message_box(psystem, "Hello!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3);

   if (result == e_dialog_result_yes)
   {

      os_message_box(psystem, "Yes!!", "Yes!!", e_message_box_ok);

   }
   else if (result == e_dialog_result_no)
   {

      os_message_box(psystem, "No!", "No!", e_message_box_ok);

   }
   else if (result == e_dialog_result_cancel)
   {

      os_message_box(psystem, "Cancel", "Cancel", e_message_box_ok);

   }

#ifdef _UWP

   getchar();

   getchar();

#endif

}



