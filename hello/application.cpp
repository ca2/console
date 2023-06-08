#include "framework.h"
#include "application.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/platform/sequencer.h"
#include "acme/primitive/datetime/datetime.h"
#include "acme/primitive/mathematics/_random.h"
#include "acme/user/user/conversation.h"
#include "acme/user/nano/nano.h"
#include "acme/memory/_new.inl"
#define FACTORY console_hello
#define __APP_ID "console/hello"
//#if defined(WINDOWS_DESKTOP) && defined(CUBE)
//#include "_static_factory.inl"
//#endif
//#include "acme_windows/_acme_windows.h"
//BEGIN_FACTORY(console_hello)
//FACTORY_DEPENDENCY(acme_windows)
//END_FACTORY()
#include "acme/console.h"
int * g_pi = nullptr;

enum enum_test_increment
{

   e_test_increment_none,
   e_test_increment_one,
   e_test_increment_two,
   e_test_increment_three,
   e_test_increment_four,
   e_test_increment_last = e_test_increment_four,
   e_test_increment_count,
   

};




//
//void implement(::acme::context * pcontext)
//{
//
//   //throw ::exception(error_debug_testing);
//
//   printf("\n");
//
//   printf("\n");
//
//   printf("Hello!!");
//
//   printf("\n");
//
//   printf("\n");
//
//   while (true)
//   {
//
//      auto result = message_box_synchronous(pcontext, "Hello!!\nNo: for exception test!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");
//
//      if (result == e_dialog_result_yes)
//      {
//
//         printf("\n");
//
//         printf("Yes!!\n");
//
//         message_box_synchronous(pcontext, "Yes!!", "Yes!!", e_message_box_ok);
//
//         break;
//
//      }
//      else if (result == e_dialog_result_no)
//      {
//
//         pcontext->fork([pcontext]()
//         {
//            
//            task_set_name("Second Thread");
//
//            pcontext->fork([pcontext]()
//                 {
//               
//               task_set_name("Third Thread");
//               
//               
//               try
//               {
//                  
////                  ::exception exception(error_catch_all_exception);
////
////                  auto psequencer = psystem->nano()->exception_message_console(exception, "Dummy inline Catchall Exception at Hello Console App!!\n", "Dummy inline Hello Console App!", e_message_box_ok, "Dummy inline Hello Console App!!");
////
////                  psequencer->do_asynchronously();
//                  
//                  //int * pi = nullptr;
//                  
//                  g_pi[1024] = 1;
//                  
//                  //int i = 23 / (iptr)g_pi;
//
//                  //printf("this is the result %d", i);
//                  
//               }
//               catch(::exception & exception)
//               {
//                  
//                  auto psequencer = pcontext->nano()->exception_message_console(exception, "Exception at Hello Console App!!\n" + exception.get_message(), "Hello Console App!", e_message_box_ok, "Hello Console App!!\n");
//
//                  psequencer->do_asynchronously();
//                  
//               }
//               catch(...)
//               {
//                  
//                  ::exception exception(error_catch_all_exception);
//
//                  auto psequencer = pcontext->nano()->exception_message_console(exception, "Catchall Exception at Hello Console App!!\n", "Hello Console App!", e_message_box_ok, "Hello Console App!!");
//
//                  psequencer->do_asynchronously();
//
//               }
//
//            });
//
//         });
//
//         printf("\n");
//
//         printf("No!\n");
//
//         message_box_synchronous(pcontext, "No!", "No!", e_message_box_ok);
//
//      }
//      else if (result == e_dialog_result_cancel)
//      {
//
//         printf("\n");
//
//         printf("Cancel!!\n");
//
//         message_box_synchronous(pcontext, "Cancel", "Cancel", e_message_box_ok);
//
//      }
//
//   }
//
//#ifdef UNIVERSAL_WINDOWS
//
//   getchar();
//
//   getchar();
//
//#endif
//
//}
//
//
//
//
//class MyPoint
//{
//public:
//
//   int x;
//   int y;
//
//
//   auto operator <=> (const MyPoint&p) const
//   {
//
//      auto yCompare = y - p.y();
//
//      return yCompare ? yCompare : x - p.x();
//      
//   }
//
//};

string checking_string_move_001()
{

   string str("checking_string_move_001");


   return str;

}


string checking_string_move_002()
{

   string str;

   auto p = new char[123];

   strcpy(p, "checking_string_move_002");

   str = p;

   delete [] p;

   return str;

}


#include <algorithm>


void trim_left_001()
{


   string str("001Test");

   str.trim_left("01");

   printf("trim_left_001:\"%s\"\n\n", str.c_str());


}

void trim_right_001()
{


   string str("Test001");

   str.trim_right("01");

   printf("trim_right_001:\"%s\"\n\n", str.c_str());


}



void test_001()
{

   i32_array a{ 1,1,2,3,5,8,13,21,34 };


   auto print_elem = [](auto const e) {::output_debug_string(::as_string(e) + "\n"); };

   for(auto & item : a) print_elem(item);

   //::std::ranges::for_each(a, print_elem);

}


void test_002()
{



   auto pstart = __FILE__;
   auto pend = pstart + strlen(pstart);

   //const char * pSearch = __FILE__;
   //const char * pSearchEnd = pstart + strlen(pstart);

   string str(pstart, pend);


   //auto size = str.size();

   auto find = str.find("application.cpp");

   ASSERT(!stricmp(find, "application.cpp"));

}


//#error "error_compiled back function"

namespace console_hello
{
 
   application::application()
   {
   }

   application::~application()
   {

   }


   ::string generatecontatenation(char ch)
   {

      ::string str;

      int iCount = random(20, 200);

      for (int i = 0; i < iCount; i++)
      {

         char ch1 = (ch + (char)random(0, 4));

         str.append(&ch1, 1);

      }

      return str;

   }

   void application::test_contatenation(char ch)
   {

      
      fork([this, ch]()
   {

      string strLastA;
      string strLastB;
      ::file::path pathLast;
      ::file::path pathLast2;

   for (int i = 0; i < 100'000; i++)
   {
      string strA = generatecontatenation(ch);

      wstring wstrB = strA;

      string strC(wstrB);

      string str = strA + strC;

      string str1;

      string strD = generatecontatenation(ch);
      
      string strMillis;

      ::file::path path = strA / strLastB / "dynamic_source" / pathLast2.name() + ".exp";

      auto path1 = path.sibling(pathLast.name());

      strMillis = ::as_string(::integral_millisecond() % 1000);

      str1.format("this is a contatenation%s and format test%s ", str.c_str(), strD.c_str());

      if (str.size() < 20)
      {
         
         ::output_debug_string("What!!");

      }
      if (str1.size() < 20)
      {

         ::output_debug_string("What(1)!!");

      }

      if (i % 1'000 == 0)
      {

         printf("%c", ch);

      }

      strLastA = strA;
      pathLast = path;
      pathLast2 = pathLast;
   }

      printf("\nCompleted concatenation \"%c\"!!", ch);

      });


   }

   void application::test_datetime_format(char ch)
   {


      fork([this, ch]()
         {

            auto pdatetime = acmesystem()->datetime();
            ::earth::time timeNow;


      for (int i = 0; i < 1'000'000; i++)
      {

         timeNow.Now();

         string strCompileLogUnique = pdatetime->format(INTERNATIONAL_DATE_TIME_FORMAT_FOR_FILE, timeNow);

         if (strCompileLogUnique.size() < 5)
         {
            ::output_debug_string("What!!");

         }
         if (i % 10'000 == 0)
         {

            printf("%c", ch);

         }
      }

      printf("\nCompleted datetime_format\"%c\"!!", ch);

            });


   }

   
   void application::main()
   {

      if (m_pacmesystem->m_psubsystem->m_argc == 2)
      {


         if (!wcscmp(m_pacmesystem->m_psubsystem->m_wargv[1],L"remove_utf8_bom_phase1"))
         {

            remove_utf8_bom_phase1();

         }
         else if (!wcscmp(m_pacmesystem->m_psubsystem->m_wargv[1], L"remove_utf8_bom_phase2"))
         {

            remove_utf8_bom_phase2();

         }


         return;


      }

      auto etestincrement = e_test_increment_none;

      for (; etestincrement <= e_test_increment_last; etestincrement = (enum_test_increment)((int)etestincrement+ 1))
      {

         switch (etestincrement)
         {
         case e_test_increment_none:
            printf("e_test_increment_none\n");
            break;
         case e_test_increment_one:
            printf("e_test_increment_one\n");
            break;
         case e_test_increment_two:
            printf("e_test_increment_two\n");
            break;
         case e_test_increment_three:
            printf("e_test_increment_three\n");
            break;
         case e_test_increment_four:
            printf("e_test_increment_four\n");
            break;


         };

      }

      //test_datetime_format('w');
      //test_datetime_format('x');
      //test_datetime_format('y');
      //test_datetime_format('z');
      //test_contatenation('a');
      //test_contatenation('f');
      //test_contatenation('l');
      //test_contatenation('s');

      //preempt(5_min);

      trim_left_001();

      trim_right_001();

      test_001();

      test_002();

      {

         string str = checking_string_move_001();

         output_debug_string(str);

      }

      {

         string str = checking_string_move_002();

         output_debug_string(str);

      }

      string_array stra{ "StringNumber1", "StringNumber2", "StringNumber5" };

      string str4("StringNumber4");

      stra.insert_at(2, str4);

      //MyPoint p1{ 1,1 };
      //MyPoint p2{ 1,4 };


      //auto compare = p1 <=> p2;

      //if (compare < 0)
      //{

      //   printf("p1 < p2");

      //}
      //else if (compare > 0)
      //{

      //   printf("p1 > p2");

      //}
      //else
      //{

      //   printf("p1  p2");

      //}

      {

         string str("HiHelloYou!!");

         auto psz1 = (const char *)str;

         printf("printf(\"%%s\", str) : %s\n", (const char*)str);
         printf("printf(\"%%s\", psz = (const char *)str; ) : %s\n", psz1);

      }





      printf("\n");

      printf("\n");

      printf("Hello!!");

      printf("\n");

      printf("\n");

      while (true)
      {

         auto psequencer = message_box(u8"Hello!!\nNo: for exception test(\u2717)!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");

         auto result = psequencer->do_synchronously();

         if (result == e_dialog_result_yes)
         {

            printf("\n");

            printf("Yes!!\n");

            psequencer = message_box("Yes!!", "Yes!!", e_message_box_ok);

            psequencer->do_synchronously();

            break;

         }
         else if (result == e_dialog_result_no)
         {

            fork([this]()
               {

                  task_set_name("Second Thread");

            fork([this]()
               {

                  task_set_name("Third Thread");


            try
            {

               //                  ::exception exception(error_catch_all_exception);
               //
               //                  auto psequencer = psystem->nano()->exception_message_console(exception, "Dummy inline Catchall Exception at Hello Console App!!\n", "Dummy inline Hello Console App!", e_message_box_ok, "Dummy inline Hello Console App!!");
               //
               //                  psequencer->do_asynchronously();

                                 //int * pi = nullptr;

               g_pi[1024] = 1;

               //int i = 23 / (iptr)g_pi;

               //printf("this is the result %d", i);

            }
            catch (::exception& exception)
            {

               auto psequencer = exception_message_box(exception, "Exception at Hello Console App!!\n" + exception.get_message(), "Hello Console App!", e_message_box_ok, "Hello Console App!!\n");

               psequencer->do_asynchronously();

            }
            catch (...)
            {

               ::exception exception(error_catch_all_exception);

               auto psequencer = exception_message_box(exception, "Catchall Exception at Hello Console App!!\n", "Hello Console App!", e_message_box_ok, "Hello Console App!!");

               psequencer->do_asynchronously();

            }

               });

               });

            printf("\n");

            printf("No!\n");

            psequencer = message_box("No!", "No!", e_message_box_ok);

            psequencer->do_synchronously();

         }
         else if (result == e_dialog_result_cancel)
         {

            printf("\n");

            printf("Cancel!!\n");

            psequencer = message_box("Cancel", "Cancel", e_message_box_ok);

            psequencer->do_synchronously();

         }

      }

#ifdef UNIVERSAL_WINDOWS

      getchar();

      getchar();

#endif


   }


};


////#ifdef WINDOWS
////int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
////#else
////int main(int argc, platform_char** argv, platform_char** envp)
////#endif
////{
////
////   class main main(argc, argv, envp);
////   //::acme::acme acme(argc, wargv, wenvp);
////
////   //sub_system subsystem(&acme);
////
////   //acme.m_psubsystem = &subsystem;
////
////   //subsystem.m_pacme = &acme;
//////   subsystem.m_argc = argc;
//////#if defined(WINDOWS)  && defined(UNICODE)
//////   subsystem.m_wargv = argv;
//////   subsystem.m_wenvp = envp;
//////#else
//////   subsystem.m_argv = argv;
//////   subsystem.m_envp = envp;
//////#endif
////
////   //main_hold mainhold;
////
////   //set_argc_argv_envp(argc, argv, envp);
////
////   ::acme::application application;
////
////   application.m_applicationflags.m_bConsole = true;
////
////
////   application.initialize_application(&main);
////
////
////   //::pointer<APPLICATION_CLASS>papp(__new(APPLICATION_CLASS));
//////
//////#ifdef NO_NETWORKING
//////
//////   papp->m_bNetworking = false;
//////
//////#endif
////
////   //#ifdef WINDOWS
////   //
////   //   papp->get_arguments_from_command_line();
////   //
////   //#else
////   //
////   //   papp->set_args(argc, argv, envp);
////   //
////   //#endif
////
////
////   //   {
////   //      //__FACTORY(FACTORY)(factory());
////   //
////   //      class ::main main;
////   //
////   //      //Sleep(30'000);
////   //
////   //      main.m_argc = argc;
////   //
////   //#ifdef WINDOWS
////   //
////   //      main.m_wargv = argv;
////   //      main.m_wenvp = envp;
////   //
////   //#else
////   //
////   //      main.m_argv = argv;
////   //      main.m_envp = envp;
////   //
////   //#endif
////
//////#ifdef APP_ID
//////
//////   papp->m_strAppId = APP_ID;
//////
//////#endif
////
////
////   //papp->m_pfnImplement = &::implement;
////
////   //try
////   //{
////
////      //__main(papp);
////
////   //}
////   //catch (const ::exception& exception)
////   //{
////
////   //   string strReport;
////
////   //   strReport += "Exception has occurred:\n";
////   //   strReport += exception.m_strMessage + ";\n";
////   //   //strReport += "Command Line:\n";
////   //   //strReport += acmenode()->get_command_line() + ";\n";
////   //   strReport += exception.m_strDetails;
////   //   strReport += "Callstack:\n";
////   //   strReport += exception.m_strCallstack;
////
////   //   fprintf(stderr, "%s", strReport.c_str());
////
////   //}
////   //catch (...)
////   //{
////
////   //   fprintf(stderr, "Unknown exception has occurred\n");
////
////   //}
////
////   //      papp->m_bConsole = true;
////   //
////   //      papp->m_strAppId = __APP_ID;
////   //
////   //      try
////   //      {
////   //
////   //         int iExitCode = papp->main_loop();
////   //
////   //         return iExitCode;
////   //
////   //      }
////   //      catch (const ::exception & exception)
////   //      {
////   //
////   //         fprintf(stderr, "Exception has occurred \"%s\"(\"%s\")", exception.m_strMessage.c_str(), exception.m_strDetails.c_str());
////   //
////   //      }
////   //      catch (...)
////   //      {
////   //
////   //         fprintf(stderr, "Unknown Exception has occurred");
////   //
////   //      }
////
////
////   //   process_set_args(argc, argv);
////   //
////   //   auto psystem = acme_system_init();
////   //
////   //   {
////   //
////   //#ifdef WINDOWS
////   //
////   //      wcsdup_array wcsdupa;
////   //
////   //      auto envp = psystem->node()->_get_envp(wcsdupa);
////   //
////   //#endif
////
////   //   ::e_status estatus = ::success;
////   //
////   //   //process_set_args(argc, argv);
////   //
////   //   auto psystem = acme_system_init();
////   //
////   //   if (!psystem)
////   //   {
////   //
////   //      return -1;
////   //
////   //   }
////   //
////   //   //psystem->m_bConsole = false;
////   //
////   //   //application_common(psystem);
////   //
////   //   //string strCommandLine(pCmdLine);
////   //
////   //   {
////   ////#ifdef WINDOWS
////   ////
////   ////      //wcsdup_array wcsdupa;
////   ////
////   ////      //auto envp = psystem->node()->_get_envp(wcsdupa);
////   ////
////   ////      platform_char** envp = nullptr;
////   ////
////   ////#endif
////   //
////   //      psystem->system_construct(argc, argv, envp);
////   //
////   //   //psystem->set_current_handles();
////   //
////   //   estatus = psystem->init_system();
////   //
////   //   if (!estatus)
////   //   {
////   //
////   //      return estatus.error_status();
////   //
////   //   }
////   //
////   //
////   //      implement(psystem);
////   //
////   //   }
////   //
////   //   acme_system_term();
////   //
////   //   return process_get_status();
////
////   //   }
////
////     // ::acme::finalize();
////
////   
////   //throw ::exception(error_debug_testing);
//
//   printf("\n");
//
//   printf("\n");
//
//   printf("Hello!!");
//
//   printf("\n");
//
//   printf("\n");
//
//   while (true)
//   {
//
//      auto psequencer = application.message_box("Hello!!\nNo: for exception test!!", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");
//
//      auto result = psequencer->do_synchronously();
//
//      if (result == e_dialog_result_yes)
//      {
//
//         printf("\n");
//
//         printf("Yes!!\n");
//
//         psequencer = application.message_box("Yes!!", "Yes!!", e_message_box_ok);
//
//         psequencer->do_synchronously();
//
//         break;
//
//      }
//      else if (result == e_dialog_result_no)
//      {
//
//         auto pcontext = application.m_pcontext;
//
//         pcontext->fork([pcontext]()
//         {
//            
//            task_set_name("Second Thread");
//
//            pcontext->fork([pcontext]()
//                 {
//               
//               task_set_name("Third Thread");
//               
//               
//               try
//               {
//                  
////                  ::exception exception(error_catch_all_exception);
////
////                  auto psequencer = psystem->nano()->exception_message_console(exception, "Dummy inline Catchall Exception at Hello Console App!!\n", "Dummy inline Hello Console App!", e_message_box_ok, "Dummy inline Hello Console App!!");
////
////                  psequencer->do_asynchronously();
//                  
//                  //int * pi = nullptr;
//                  
//                  g_pi[1024] = 1;
//                  
//                  //int i = 23 / (iptr)g_pi;
//
//                  //printf("this is the result %d", i);
//                  
//               }
//               catch(::exception & exception)
//               {
//                  
//                  auto psequencer = pcontext->exception_message_box(exception, "Exception at Hello Console App!!\n" + exception.get_message(), "Hello Console App!", e_message_box_ok, "Hello Console App!!\n");
//
//                  psequencer->do_asynchronously();
//                  
//               }
//               catch(...)
//               {
//                  
//                  ::exception exception(error_catch_all_exception);
//
//                  auto psequencer = pcontext->exception_message_box(exception, "Catchall Exception at Hello Console App!!\n", "Hello Console App!", e_message_box_ok, "Hello Console App!!");
//
//                  psequencer->do_asynchronously();
//
//               }
//
//            });
//
//         });
//
//         printf("\n");
//
//         printf("No!\n");
//
//         psequencer = application.message_box("No!", "No!", e_message_box_ok);
//
//         psequencer->do_synchronously();
//
//      }
//      else if (result == e_dialog_result_cancel)
//      {
//
//         printf("\n");
//
//         printf("Cancel!!\n");
//
//         psequencer = application.message_box("Cancel", "Cancel", e_message_box_ok);
//
//         psequencer->do_synchronously();
//
//      }
//
//   }
//
//#ifdef UNIVERSAL_WINDOWS
//
//   getchar();
//
//   getchar();
//
//#endif
//
//}


console_hello::application g_consolehelloapplication;
