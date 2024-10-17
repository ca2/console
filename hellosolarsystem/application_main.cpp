#include "framework.h"
//#define FACTORY console_hellosolarsystem
#define NO_NETWORKING
#define APP_ID "console/hellosolarsystem"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
//#include "apex_windows/_apex_windows.h"
//BEGIN_FACTORY(console_hellosolarsystem)
//FACTORY_DEPENDENCY(apex_windows)
//END_FACTORY()
#include "acme/console.h"
#include "acme/platform/system.h"
//#include "aqua/xml.h"
#include <stdio.h>
#include "acme/prototype/mathematics/mathematics.h"
#include "acme/prototype/time/_string.h"
#include "unit_test/set.h"


#ifdef WITH_UNIT_TEST
DECLARE_UNIT_TEST_SET(basic_types);
#endif


template < typename CONTAINER >
inline string _009Explode(const CONTAINER& container, string strSeparator, string strLastSeparator)
{

   string str;

   ::collection::index i = container.get_count();

   for (auto& item : container)
   {

      str += as_string(item);

      if (i > 2)
      {

         str += strSeparator;

      }
      else if (i == 2)
      {

         str += strLastSeparator;

      }

      i--;

   }

   return str;

}





//#include "pointer_const_pointer.cpp"
//#include "tutor.cpp"
//#include "asterisk_ampersand_naked_type.cpp"
//#include "double_to_int.cpp"
//#include "brushing_bit_per_bit.cpp"
//#include "loop_get_char.cpp"
//#include "printf_format_flags.cpp"



class console_hellosolarsystem :
   virtual public ::apex::application
{
public:


   console_hellosolarsystem()
   {

      m_bNetworking = false;

      m_bCrypto = false;

      m_bResource = false;

      m_strAppId = "console/hellosolarsystem";

   }


   void main() override
   {

      //::console console(argc, argv, envp);

   //   pointer_const_pointer();
   //
   //   pointer_const_pointer0();
   //
   //   printf_format_flags();
   //
   //   brushing_bit_per_bit();
   //
   //   double_to_int();
   //
   //   loop_get_char();
   //
   //   cjsteel_0001_ca2_rev();

      class ::time time;

      time.Now();

      preempt(10_ms);

      //   {
      //
      //      int iAsteriskAmpersandNakedType = 1;
      //
      //      printf("iAsteriskAmpersandNakedType (init) %d\n", iAsteriskAmpersandNakedType);
      //
      //      asterisk(&iAsteriskAmpersandNakedType);
      //
      //      printf("iAsteriskAmpersandNakedType (after Asterisk) %d\n", iAsteriskAmpersandNakedType);
      //
      //      ampersand(iAsteriskAmpersandNakedType);
      //
      //      printf("iAsteriskAmpersandNakedType (after Ampersand) %d\n", iAsteriskAmpersandNakedType);
      //
      //      naked_type(iAsteriskAmpersandNakedType);
      //
      //      printf("iAsteriskAmpersandNakedType (after Naked Type) %d\n", iAsteriskAmpersandNakedType);

      //   }

      auto elapsed = time.elapsed();

      string strElapsed;

      strElapsed = " Elapsed: " + ::as_string(elapsed.integral_millisecond()) + "ms";

      information(strElapsed);

      if (system()->is_true("debug"))
      {

         printf("\n");
         printf("%s", "\"debug\" command line parameter set\n");
         printf("%s", "running debug routine(s)\n");
         printf("\n");
         printf("\n");

         //debug_debug_reference();

      }

      {

         string strTitle = "Hello Solar System!!";

         printf("%s\n", strTitle.c_str());

      }

      {

         printf("\n");
         printf("papp->m_strAppId == \"%s\"\n", m_strAppId.c_str());
         printf("\n");

      }

      printf("\n");

      //   {
      //
      //      ::i32_array ia;
      //
      //      ia.add(1);
      //
      //      ia.add(1);
      //
      //      ia.add(1);
      //
      //      ia.add(2);
      //
      //      ia.add(3);
      //
      //      ia.add(3);
      //
      //      ia.add(4);
      //
      //      ia.add(5);
      //
      //      ia.add(6);
      //
      //      ia.add(6);
      //
      //      ia.add(6);
      //
      //      ia.add(7);
      //
      //      ia.add(7);
      //
      //      ia.add(8);
      //
      //      string str = _009Explode(ia, ", ", " and ");
      //
      //      printf("Finding odds at %s\n", str.c_str());
      //
      //      ::i32_array furyDriveArray;
      //
      //      ::in_odd_count(furyDriveArray, ia);
      //
      //      str = _009Explode(furyDriveArray, ", ", " and ");
      //
      //      printf("The items in_odd_count are %s\n", str.c_str());
      //
      //   }

      printf("\n");

#ifdef WITH_UNIT_TEST

      bool bUnitTest001 = false;

      if (bUnitTest001)
      {

         unit_test_001();

      }

#endif //  WITH_UNIT_TEST

      message_box_for_console("Hello Solar System!!", "hellosolarsystem", e_message_box_ok);

      // return ::success;

   }


   #ifdef WITH_UNIT_TEST

   void unit_test_001()
   {

      printf("Running unit tests version 0.01 ...\n\n");

      auto punittestset = new_basic_types_unit_test_set();

      punittestset->set_verbose_flag(true);

      punittestset->test();

      auto strReport = punittestset->get_plain_text_report();

      printf("%s", strReport.c_str());

   }

#endif //  WITH_UNIT_TEST

};


//
//console_hellosolarsystem g_consolesolarsystem;
//


void application_main()
{

   auto papplication = __new console_hellosolarsystem::application();

   auto iExitCode = papplication->application_main();

   return iExitCode;

}



