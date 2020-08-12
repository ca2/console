
// Attendee
// 2020-04-29 CJsteel@Twitch.tv Present


void find_maximum_value_in_list()
{

   using LIST_TYPE = double;
   ::list<LIST_TYPE> list;

   auto min = ::numeric_info<LIST_TYPE >::get_minimum_value();

   list.add_tail(min);
   list.add_tail(min + 1);
   list.add_tail(min);
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

      auto max = min;

      for (auto& item : list)
      {

         if (item > max)
         {

            max = item;

         }

      }

      printf("maximum = %s\n\n", __str(max).c_str());

   }

}

//try
//{

//   ____throw(todo());

//}
//catch (::exception::exception& e)
//{

//   output_debug_string("exception::exception &");

//}
//catch (::exception_pointer e)
//{

//   output_debug_string("exception_pointer &");

//}
//catch (::exception::exception* pe)
//{

//   output_debug_string("exception_pointer *");

//}
//catch (todo* p)
//{

//   output_debug_string("todo *");

//}
//catch (...)
//{


//}

//try
//{

//   ____throw(todo());

//}
//catch (::exception::exception& e)
//{

//   output_debug_string("exception::exception &");

//}
//catch (::exception_pointer e)
//{

//   output_debug_string("exception_pointer &");

//}
//catch (todo* p)
//{

//   output_debug_string("todo *");

//}
//catch (::exception::exception* pe)
//{

//   output_debug_string("exception_pointer *");

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

   for (int i = 0; i < PARTICLE_COUNT; i++)
   {

      int j = System.math().gen_rand() % 100;

      vecaParticle[i].w = j;
      vecaParticle[i].x = j + 1;

   }

   int numParticles = PARTICLE_COUNT;

   double dMax = 0;

   int iFindMaxWParticle = -1;

   for (int iParticle = 0; iParticle < numParticles; iParticle++)
   {

      double replace = vecaParticle[iParticle].w;

      if (vecaParticle[iParticle].w > dMax)
      {

         iFindMaxWParticle = iParticle;

         dMax = vecaParticle[iParticle].w;

      }

   }

   auto dEstimatedPosition = vecaParticle[iFindMaxWParticle].x;

   printf("Position: %s\n\n", __str(dEstimatedPosition).c_str());

}


