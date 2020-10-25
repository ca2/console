#include "acme/console.h"

CLASS_DECL_ACME string message_box_result_to_string(int iResult);

void process_main()
{

   string strHelloEarth = "Hello Earth!!";

   printf("%s\n", strHelloEarth.c_str());

   string strTest123;

   strTest123 = "Test123";

   printf("Test123=%s\n", strTest123.c_str());

   ::str::begins_eat_ci(strTest123, "test");

   printf("begins_eat_ci(strTest123, \"test\")=%s\n", strTest123.c_str());

   string_array stra;

   stra.add("apple");
   stra.add("orange");
   stra.add("strawberry");

   for (auto& str : stra)
   {

      printf("a fruit: %s\n", str.c_str());

   }

   string_array stra2;

   stra2.add("apP");
   stra2.add("ap1");
   stra2.add("oRa");
   stra2.add("or2");
   stra2.add("Str");
   stra2.add("st3");

   for (auto& str2 : stra2)
   {

      auto iFind = stra.find_first_begins_ci(str2);

      if(iFind < 0)
      {

         printf("find first starts with: %s - %" __priindex "\n", str2.c_str(), iFind);


      }
      else
      {

         printf("find first starts with: %s - %" __priindex " - %s\n", str2.c_str(), iFind, stra[iFind].c_str());

      }

   }

   ::id id;

   id = 1;

   printf("id=%s\n", id.to_string().c_str());

   id = "two";

   printf("id=%s\n", id.to_string().c_str());

   property_set set;

   auto & library = set["user1"];

   library["book1"]["title"] = "First C++ Book";
   library["book1"]["chapter1"] = "First C++ Book - First Chapter";
   library["book1"]["chapter2"] = "First C++ Book - Second Chapter";
   library["book1"]["chapter3"] = "First C++ Book - Last Chapter";
   library["book1"]["page_count"] = 40;
   library["book1"]["first_edition_weight"] = 0.621;
   library["book2"]["title"] = "Second C++ Book";
   library["book2"]["chapter1"] = "First C++ Book - First Chapter";
   library["book2"]["chapter2"] = "First C++ Book - Second Chapter";
   library["book2"]["chapter3"] = "First C++ Book - Third Chapter";
   library["book2"]["chapter4"] = "First C++ Book - Fourth Chapter";
   library["book2"]["chapter5"] = "First C++ Book - Last Chapter";
   library["book2"]["page_count"] = 81;
   library["book2"]["first_edition_weight"] = 0.907;

   auto& library2 = set["user2"];

   library2["book1"]["title"] = "First C Book";
   library2["book1"]["chapter1"] = "First C++ Book - First Chapter";
   library2["book1"]["chapter2"] = "First C++ Book - Last Chapter";
   library2["book1"]["page_count"] = 32;
   library2["book1"]["first_edition_weight"] = 0.517;

   library2["book2"]["title"] = "Second C Book";
   library2["book2"]["chapter1"] = "First C++ Book - First Chapter";
   library2["book2"]["chapter2"] = "First C++ Book - Second Chapter";
   library2["book2"]["chapter3"] = "First C++ Book - Third Chapter";
   library2["book2"]["chapter4"] = "First C++ Book - Last Chapter";
   library2["book2"]["page_count"] = 72;
   library2["book2"]["editions_weight"] = var_array({ 0.907, 0.856, 0.741 });

   string strJson = set.get_json();

   printf("%s\n", strJson.c_str());

repeat_message_box:

   auto pfuture = __sync_future();

   os_message_box("Hello Earth!! Yes, No or Cancel?!?", "helloearth!!", message_box_yes_no_cancel | message_box_icon_information, pfuture);

   //pfuture->m_event.lock(75_min);

   pfuture->wait(7.5_s);

   int iResult = pfuture->m_var.i32();

   printf("helloearth response \"%s\"\n", message_box_result_to_string(iResult).c_str());

   if (iResult != 0 && iResult != IDYES)
   {

      goto repeat_message_box;

   }

   printf("Exiting main...\n");

}



