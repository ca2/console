#include "framework.h"
//#include "acme/primitive/primitive/payload.h"
#include "acme/primitive/string/str.h"
#define FACTORY console_helloearth
#define __APP_ID "console/helloearth"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
//#include "acme_windows/_acme_windows.h"
//BEGIN_FACTORY(console_helloearth)
//FACTORY_DEPENDENCY(acme_windows)
//END_FACTORY()
#include "acme/console.h"
#include "_.h"
#include <iostream> // mixing with STL

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


#define minimum_ min_test


class console_helloearth :
   virtual public ::acme::application
{
public:


   void main() override
   {

      string strHelloEarth = "Hello Earth!!";

      printf("%s\n", strHelloEarth.c_str());

      string strATestText(" A TestText");

      string strAEIOU("Oh" + strATestText);

      printf("strAEIOU=%s", strAEIOU.c_str());

      string strTest123;

      strTest123 = "Test123";

      printf("Test123=%s\n", strTest123.c_str());

      strTest123.case_insensitive_begins_eat("test");

      printf("case_insensitive_begins_eat(strTest123, \"test\")=%s\n", strTest123.c_str());

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

         if (iFind < 0)
         {

            printf("find first starts with: %s - %" PRIiPTR "\n", str2.c_str(), iFind);


         }
         else
         {

            printf("find first starts with: %s - %" PRIiPTR " - %s\n", str2.c_str(), iFind, stra[iFind].c_str());

         }

      }

      ::atom atom;

      atom = 1;

      printf("atom=%s\n", ::string(atom).c_str());

      atom = "two";

      printf("atom=%s\n", ::string(atom).c_str());

      property_set set;

      auto& library = set["user1"];

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
      library2["book2"]["editions_weight"] = payload_array({ 0.907, 0.856, 0.741 });

      string strNetworkPayload = set.get_network_payload();

      printf("%s\n", strNetworkPayload.c_str());


      unsigned int uAllOne = 0xffffffff;
      int iUAllOne = uAllOne;
      auto min1 = minimum(uAllOne, iUAllOne);
      printf("%d\n", min1);
      auto min2 = minimum(iUAllOne, uAllOne);
      printf("%d\n", min2);
      int iAllOne = -1;
      unsigned int uIAllOne = iAllOne;
      auto min3 = minimum(iAllOne, uIAllOne);
      printf("%u\n", min3);
      auto min4 = minimum(uIAllOne, iAllOne);
      printf("%u\n", min4);


      unsigned int uAlmostAllOne = 0xfffffffe;
      int iUAlmostAllOne = uAlmostAllOne;
      auto min5 = minimum(uAlmostAllOne, iUAlmostAllOne);
      printf("min5: %i\n", min5);
      auto min6 = minimum(iUAlmostAllOne, uAlmostAllOne);
      printf("min6: %i\n", min6);
      int iAlmostAllOne = -2;
      unsigned int uIAlmostAllOne = iAlmostAllOne;
      auto min7 = minimum(iAlmostAllOne, uIAlmostAllOne);
      printf("%i\n", min7);
      auto min8 = minimum(uIAlmostAllOne, iAlmostAllOne);
      printf("%i\n", min8);

      unsigned short u1 = 0xffff;
      int i1 = u1;
      auto min9 = minimum(u1, i1);
      printf("%i\n", min9);
      auto mina = minimum(i1, u1);
      printf("%i\n", mina);
      short s1 = -1;
      unsigned int i2 = s1;
      auto minb = minimum(s1, i2);
      printf("%i\n", minb);
      auto minc = minimum(i2, s1);
      printf("%i\n", minc);

      unsigned int u3 = 0xffffffff;
      short i3 = u3;
      auto mind = minimum(u3, i3);
      printf("%i\n", mind);
      auto mine = minimum(i3, u3);
      printf("%i\n", mine);
      int s3 = -1;
      unsigned short i4 = s3;
      auto minf = minimum(s3, i4);
      printf("%i\n", minf);
      auto ming = minimum(i4, s3);
      printf("%i\n", ming);

      printf("\n");

      printf("\n");

      enum_dialog_result edialogresult = e_dialog_result_none;

      twitch twitch;

      twitch.initialize(this);

      while (edialogresult != e_dialog_result_yes)
      {

         int iMenuItem = twitch.show_main_menu_and_get_menu_item();

         while (iMenuItem > 0)
         {

            int iNextMenuItem = twitch.do_menu_item_and_get_next_menu_item(iMenuItem);

            iMenuItem = iNextMenuItem;

         }

         do
         {

            edialogresult = message_box_for_console("Hello Earth!! Yes, No or Cancel?!?", "helloearth!!", e_message_box_yes_no_cancel | e_message_box_icon_information);

            printf("\n");

            printf("\n");

            printf("helloearth response \"%s\"", message_box_result_to_string(edialogresult).c_str());

            printf("\n");

            printf("\n");

         } while (edialogresult == e_dialog_result_cancel);

      }

      printf("Exiting main...");

      printf("\n");

      printf("\n");

   }

};


console_helloearth g_consoleearth;



