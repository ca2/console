#include "acme/console.h"


int main(int argc, wchar_t * argv[])
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

   press_any_key_to_exit();

   return 0;

}



