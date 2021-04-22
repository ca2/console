#include "apex/console.h"
//#include "aqua/xml.h"
#include <stdio.h>

#include "pointer_const_pointer.cpp"
#include "tutor.cpp"
#include "asterisk_ampersand_naked_type.cpp"
#include "double_to_int.cpp"
#include "brushing_bit_per_bit.cpp"
#include "loop_get_char.cpp"
#include "printf_format_flags.cpp"


::e_status implement(int argc, platform_char** argv, platform_char** envp)
{

   ::console console(argc, argv, envp);

   pointer_const_pointer();

   pointer_const_pointer0();

   printf_format_flags();

   brushing_bit_per_bit();

   double_to_int();

   loop_get_char();

   cjsteel_0001_ca2_rev();

   millis millis;

   millis.Now();

   sleep(10_ms);

   {

      int iAsteriskAmpersandNakedType = 1;

      printf("iAsteriskAmpersandNakedType (init) %d\n", iAsteriskAmpersandNakedType);

      asterisk(&iAsteriskAmpersandNakedType);

      printf("iAsteriskAmpersandNakedType (after Asterisk) %d\n", iAsteriskAmpersandNakedType);

      ampersand(iAsteriskAmpersandNakedType);

      printf("iAsteriskAmpersandNakedType (after Ampersand) %d\n", iAsteriskAmpersandNakedType);

      naked_type(iAsteriskAmpersandNakedType);

      printf("iAsteriskAmpersandNakedType (after Naked Type) %d\n", iAsteriskAmpersandNakedType);

   }

   auto elapsed = millis.elapsed();

   string strElapsed;

   strElapsed = " Elapsed: " + __str(elapsed.m_i);

   output_debug_string(strElapsed);

   if (console.m_psystem->is_true("debug"))
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
      printf("papplication->m_strAppId == \"%s\"\n", console.m_psystem->m_papexsystem->m_strAppId.c_str());
      printf("\n");

   }

   printf("\n");

   {

      int_array ia;

      ia.add(1);

      ia.add(1);

      ia.add(1);

      ia.add(2);

      ia.add(3);

      ia.add(3);

      ia.add(4);

      ia.add(5);

      ia.add(6);

      ia.add(6);

      ia.add(6);

      ia.add(7);

      ia.add(7);

      ia.add(8);

      string str = _009Explode(ia, ", ", " and ");

      printf("Finding odds at %s\n", str.c_str());

      int_array furyDriveArray;

      ::in_odd_count(furyDriveArray, ia);

      str = _009Explode(furyDriveArray, ", ", " and ");

      printf("The items in_odd_count are %s\n", str.c_str());

   }

   printf("\n");

   
   message_box_for_console("Hello Solar System!!", "hellosolarsystem", e_message_box_ok);

   return ::success;

}



