#include "acme/console.h"
//template<typename T>
//inline const auto oddProduct(T n)  noexcept
//-> std::enable_if_t<std::is_unsigned<T>::value, unsigned long long> {
//   return n < T{ 2 }
//      ? n
//      : (n % T{ 2 })
//      ? oddProduct<T>(n - T{ 2 }) * n
//      : oddProduct(--n);
//}
//
//template<typename T>
//inline const auto oddProduct(T n)
//-> std::enable_if_t<std::is_signed<T>::value, unsigned long long> {
//   if (n < 0) throw std::domain_error("Negative value passed");
//   return n < T{ 2 }
//      ? n
//      : (n % T{ 2 })
//      ? oddProduct<std::make_unsigned_t<T>>(n - T{ 2 }) * n
//      : oddProduct<std::make_unsigned_t<T>>(--n);
//}



CLASS_DECL_ACME string message_box_result_to_string(enum_dialog_result edialogresult);
//// if a == b, minimum returns first argument
template < typename A, typename B >
constexpr const auto min_test(const A & a, const B & b)
{

   return a < (A) b ? a : (A)b;

}
template <  >
constexpr const auto min_test(const ::u32 & u, const ::i32 & i)
{

   return i < 0 ? 0 : (u < (::u32)i ? u : (::u32)i);

}
#define minimum min_test

void stage()
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


   unsigned int uAllOne = 0xffffffff;
   int iUAllOne = uAllOne;
   auto min1 = minimum(uAllOne, iUAllOne);
   auto min2 = minimum(iUAllOne, uAllOne);
   int iAllOne = -1;
   unsigned int uIAllOne = iAllOne;
   auto min3 = minimum(iAllOne, uIAllOne);
   auto min4 = minimum(uIAllOne, iAllOne);

   

   unsigned int uAlmostAllOne = 0xfffffffe;
   int iUAlmostAllOne = uAlmostAllOne;
   auto min5 = minimum(uAlmostAllOne, iUAlmostAllOne);
   auto min6 = minimum(iUAlmostAllOne, uAlmostAllOne);
   int iAlmostAllOne = -2;
   unsigned int uIAlmostAllOne = iAlmostAllOne;
   auto min7 = minimum(iAlmostAllOne, uIAlmostAllOne);
   auto min8 = minimum(uIAlmostAllOne, iAlmostAllOne);

   unsigned short u1 = 0xffff;
   int i1 = u1;
   auto min9 = minimum(u1, i1);
   auto mina = minimum(i1, u1);
   short s1 = -1;
   unsigned int i2 = s1;
   auto minb = minimum(s1, i2);
   auto minc = minimum(i2, s1);

   unsigned int u3 = 0xffffffff;
   short i3 = u3;
   auto mind = minimum(u3, i3);
   auto mine = minimum(i3, u3);
   int s3 = -1;
   unsigned short i4 = s3;
   auto minf = minimum(s3, i4);
   auto ming = minimum(i4, s3);

repeat_message_box:

   auto pfuture = __sync_future();

   System.message_box("Hello Earth!! Yes, No or Cancel?!?", "helloearth!!", e_message_box_yes_no_cancel | e_message_box_icon_information, pfuture);

   //pfuture->m_event.lock(75_min);

   //pfuture->wait(75_s);

   pfuture->wait(7.5_s);

   auto edialogresult = pfuture->m_var.e<enum_dialog_result>();

   printf("helloearth response \"%s\"\n", message_box_result_to_string(edialogresult).c_str());

   if (edialogresult != 0 && edialogresult != e_dialog_result_yes)
   {

      goto repeat_message_box;

   }


   printf("Exiting main...\n");

}



