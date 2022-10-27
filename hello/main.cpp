#include "acme/_start.h"
//#include "acme/_.h"
#include "acme/platform/system.h"
#include "acme/platform/sequencer.h"
#include "acme/user/user/conversation.h"
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
int * g_pi = nullptr;

void implement(::acme::context * pcontext)
{

   //throw ::exception(error_debug_testing);

   printf("\n");

   printf("\n");

   printf("Hello!!");

   printf("\n");

   printf("\n");

   while (true)
   {

      auto result = message_box_synchronous(pcontext, "Hello!!\nNo: for exception test!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");

      if (result == e_dialog_result_yes)
      {

         printf("\n");

         printf("Yes!!\n");

         message_box_synchronous(pcontext, "Yes!!", "Yes!!", e_message_box_ok);

         break;

      }
      else if (result == e_dialog_result_no)
      {

         pcontext->fork([pcontext]()
         {
            
            task_set_name("Second Thread");

            pcontext->fork([pcontext]()
                 {
               
               task_set_name("Third Thread");
               
               
               try
               {
                  
//                  ::exception exception(error_catch_all_exception);
//
//                  auto psequencer = psystem->exception_message_sequencer(exception, "Dummy inline Catchall Exception at Hello Console App!!\n", "Dummy inline Hello Console App!", e_message_box_ok, "Dummy inline Hello Console App!!");
//
//                  psequencer->do_asynchronously();
                  
                  //int * pi = nullptr;
                  
                  g_pi[1024] = 1;
                  
                  //int i = 23 / (iptr)g_pi;

                  //printf("this is the result %d", i);
                  
               }
               catch(::exception & exception)
               {
                  
                  auto psequencer = pcontext->exception_message_sequencer(exception, "Exception at Hello Console App!!\n" + exception.get_message(), "Hello Console App!", e_message_box_ok, "Hello Console App!!\n");

                  psequencer->do_asynchronously();
                  
               }
               catch(...)
               {
                  
                  ::exception exception(error_catch_all_exception);

                  auto psequencer = pcontext->exception_message_sequencer(exception, "Catchall Exception at Hello Console App!!\n", "Hello Console App!", e_message_box_ok, "Hello Console App!!");

                  psequencer->do_asynchronously();

               }

            });

         });

         printf("\n");

         printf("No!\n");

         message_box_synchronous(pcontext, "No!", "No!", e_message_box_ok);

      }
      else if (result == e_dialog_result_cancel)
      {

         printf("\n");

         printf("Cancel!!\n");

         message_box_synchronous(pcontext, "Cancel", "Cancel", e_message_box_ok);

      }

   }

#ifdef _UWP

   getchar();

   getchar();

#endif

}



