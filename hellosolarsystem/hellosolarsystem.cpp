#include "aqua/console.h"
#include "aqua/xml.h"
#include <stdio.h>

#include "pointer_const_pointer.cpp"
#include "tutor.cpp"
#include "asterisk_ampersand_naked_type.cpp"
#include "double_to_int.cpp"
#include "brushing_bit_per_bit.cpp"
#include "loop_get_char.cpp"
#include "printf_format_flags.cpp"


int main(int argc, platform_char ** argv)
{

   ::console console(argc, argv);

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

   if (Application.is_true("debug"))
   {

      printf("\n");
      printf("%s", "\"debug\" command line parameter set\n");
      printf("%s", "running debug routine(s)\n");
      printf("\n");
      printf("\n");

      debug_debug_reference();

   }

   {

      string strTitle = "Hello Solar System!!";

      printf("%s\n", strTitle.c_str());

   }

   {

      printf("\n");
      printf("Application.type_name() == \"%s\"\n", Application.type_name());
      printf("\n");

   }

   {

      string strXml;

      {

         auto pdocument = __new(xml::document);

         pdocument->set_name("xml");

         auto proot = pdocument->root();

         proot->add_child("node1", { "attribute1", "value1", "attribute2", "value2" }, "node1 value");

         strXml = pdocument->get_xml();

      }

      printf("xml=\"%s\"\n", strXml.c_str());

   }

   printf("\n");

   {

      string strXml;

      {

         auto pdocument = __new(xml::document);

         pdocument->set_name("xml");

         auto proot = pdocument->root();

         {

            string strAttr3Value("value3");

            string strNode2Value("node2_ _value");

            strNode2Value.replace("_", "");

            proot->add_child("node2", { "attribute3", strAttr3Value }, strNode2Value);

         }

         {

            string strAttr4Value("value4");

            string strNode3Value("node3 v_a_l_u_e");

            strNode3Value.replace("_", "");

            proot->add_child("node3", { "attribute4", strAttr4Value }, strNode3Value);

         }

         {

            proot->add_child("separator");

         }

         {

            string strAttr5Value("value5");

            string strNode4Value("n_o_d_e_4 value");

            strNode4Value.replace("_", "");

            proot->add_child("node4", { "attribute5", strAttr5Value }, strNode4Value);

         }

         string str1("value1");

         if (pdocument->rfind("node1", { "attribute", str1 }) == nullptr)
         {

            string strAttr6Value("value6");

            string strNode5Value("_n_o_d_e_5_ _v_a_l_u_e_");

            strNode5Value.replace("_", "");

            proot->add_child("node5", { "attribute6", strAttr6Value }, strNode5Value);

         }

         string str2("Attr1Value123456789");

         if (pdocument->rfind("test", { "attr1", str2 }) == nullptr)
         {

            string strAttr7Value("value7");

            string strNode6Value("node6 value");

            strNode6Value.replace("_", "");

            auto pnode6 = proot->add_child("node6", { "attribute7", strAttr7Value }, strNode6Value);

            pnode6->add_child("node6.1", { "attribute7.1", "value7.1" }, "node6.1");
            pnode6->add_child("node6.3", { "attribute7.3", "value7.3" }, "node6.3");
            auto pnode66 = pnode6->add_child("node6.6", { "attribute7.6", "value7.6" }, "node6.6");
            pnode66->add_child("node6.6.1", { "attribute8.1", "value8.1" }, "node6.6.1");
            pnode66->add_child("node6.6.3", { "attribute8.3", "value8.3" }, "node6.6.3");
            pnode66->add_child("node6.6.6", { "attribute8.6", "value8.6" }, "node6.6.6");
            pnode66->add_child("node6.6.9", "node6.6.9");

         }

         strXml = pdocument->get_xml();

      }

      printf("xml=\"%s\"\n", strXml.c_str());

   }

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

   auto pfuture = __sync_future();

   System.message_box("Hello Solar System!!", "hellosolarsystem", e_message_box_ok, pfuture);

   //pfuture->wait(2.5_s);

   pfuture->wait(125_s);

}



