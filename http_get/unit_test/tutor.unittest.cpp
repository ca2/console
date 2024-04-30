
// Attendee
// 2020-04-29 CJsteel@Twitch.tv Present
#include "framework.h"


__begin(somecode)



   // done something and it failed
   // ....
   // ....

//   return ::error_failed;


__end(true);


//CLASS_DECL_AQUA void debug_debug_reference();

template < typename RESULT_CONTAINER, typename CONTAINER >
inline void in_odd_count(RESULT_CONTAINER& result_container, const CONTAINER& container)
{

   for (auto& item : container)
   {

      if (container.get_count(item) % 2 == 1)
      {

         result_container.add_unique(item);

      }

   }

}

template < typename CONTAINER >
inline auto in_odd_count(const CONTAINER& container)
{

   CONTAINER containerResult;

   in_odd_count(containerResult, container);

   return containerResult;

}



template < typename CONTAINER >
inline string _009Explode(const CONTAINER& container, string strSeparator, string strLastSeparator)
{

   string str;

   ::raw::index i = container.get_count();

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




//namespace helloworld
//{
//
//
//   __IMPLEMENT_APPLICATION_RELEASE_TIME();


   application::application()
//   {
//
//      m_strAppName = "consolelab";
//      m_strBaseSupportId = "ca2_flag";
//      m_bLicense = false;
//
//   }
//
//
//   application::~application()
//   {
//
//
//   }
//
//
//
//   void application::on_request(::create* pcreate)
//   {
//
//      helloworld();
//
//      set_finish();
//
//   }
//
//
//   void application::helloworld()
//   {
//


void find_maximum_value_in_list()
{

   using LIST_TYPE = double;

   ::list<LIST_TYPE> list;

   auto minimum = ::numeric_info<LIST_TYPE >::minimum();

   list.add_tail(minimum);
   list.add_tail(minimum + 1);
   list.add_tail(minimum);
   list.add_tail(0);
   list.add_tail(9);
   list.add_tail(2);
   list.add_tail(-3);
   list.add_tail(500);
   list.add_tail(1);
   list.add_tail(-111);
   list.add_tail(11);

   if (list.is_empty())
   {

      printf("The list is empty. There is not maximum value to display");

   }
   else
   {



      //int iMax = iIntMin;

      //for (auto& iItem : intlist)
      //{

      //   if (iItem > iMax)
      //   {

      //      iMax = iItem;

      //   }

      //}

      auto maximum = minimum;

      for (auto& item : list)
      {

         if (item > maximum)
         {

            maximum = item;

         }

      }

      printf("maximum = %s\n\n", as_string(maximum).c_str());

   }

}

//try
//{

//   ____throw(todo());

//}
//catch (::exception& e)
//{

//   informationf("::exception &");

//}
//catch const ::exception & e
//{

//   informationf("exception_pointer &");

//}
//catch (::exception* pe)
//{

//   informationf("exception_pointer *");

//}
//catch (todo* p)
//{

//   informationf("todo *");

//}
//catch (...)
//{


//}

//try
//{

//   ____throw(todo());

//}
//catch (::exception& e)
//{

//   informationf("::exception &");

//}
//catch const ::exception & e
//{

//   informationf("exception_pointer &");

//}
//catch (todo* p)
//{

//   informationf("todo *");

//}
//catch (::exception* pe)
//{

//   informationf("exception_pointer *");

//}
//catch (...)
//{


//}
struct vec
{
   double x;
   double y;
   double z;
   double w;

};


void cjsteel_0001_ca2_rev()
{

#define PARTICLE_COUNT 100

   vec vecaParticle[PARTICLE_COUNT];

   auto pmathematics = ::mathematics::mathematics();

   for (int i = 0; i < PARTICLE_COUNT; i++)
   {

      int j = pmathematics->gen_rand() % 100;

      vecaParticle[i].w = j;
      vecaParticle[i].x() = j + 1;

   }

   int numParticles = PARTICLE_COUNT;

   double dMax = 0;

   int iFindMaxWParticle = -1;

   for (int iParticle = 0; iParticle < numParticles; iParticle++)
   {

      //double replace = vecaParticle[iParticle].w;

      if (vecaParticle[iParticle].w > dMax)
      {

         iFindMaxWParticle = iParticle;

         dMax = vecaParticle[iParticle].w;

      }

   }

   auto dEstimatedPosition = vecaParticle[iFindMaxWParticle].x();

   printf("Position: %s\n\n", as_string(dEstimatedPosition).c_str());

}


