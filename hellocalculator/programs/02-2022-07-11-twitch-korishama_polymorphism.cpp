#include "framework.h"
#include "acme/platform/system.h"
#include "acme/exception/exit.h"
#include "acme/exception/interface_only.h"
#include <iostream>
#include <fstream>


double yes_for_two__no_for_three_and_cancel_for_exit_exception()
{

   auto psystem = acmesystem();

   auto result = message_box_synchronous(psystem, "Yes for two and No for 3\n\n(and cancel for exit...)", "Hello App!", e_message_box_yes_no_cancel | e_message_box_default_button_3, "Hello Multiverse!!");

   if (result == e_dialog_result_yes)
   {

      return 2.0;

   }
   else if (result == e_dialog_result_no)
   {

      return 3.0;

   }
   else
   {

      throw exit_exception();

   }

}

//using namespace std;

class Figure :
   virtual public ::particle
{
public:


   virtual ::string get_name()
   {

      return "(Figure)";

   }

   ~Figure() override
   {

   }


   virtual double get_perimeter()
   {

      throw interface_only();

      return -1.0;

   }


};


class Circle :
   public Figure
{
public:

   double m_dRadius;

   Circle(double dRadius = yes_for_two__no_for_three_and_cancel_for_exit_exception())
   {

      m_dRadius = dRadius;

   }

   ::string get_name() override
   {

      return "Circle";

   }

   double get_perimeter() override
   {

      
      return m_dRadius * 2.0 * 3.1415;

   }


};

class TriangleRegular :
   public Figure
{
public:

   double m_dSide;

   TriangleRegular(double dSide = yes_for_two__no_for_three_and_cancel_for_exit_exception())
   {

      m_dSide = dSide;

   }


   ::string get_name() override
   {

      return "TriangleRegular";

   }

   double get_perimeter() override
   {


      return m_dSide * 3.0;

   }


};

class Square :
   public Figure
{
public:

   double m_dSide;

   Square(double dSide = yes_for_two__no_for_three_and_cancel_for_exit_exception())
   {

      m_dSide = dSide;

   }


   ::string get_name() override
   {

      return "Square";

   }

   double get_perimeter() override
   {


      return m_dSide  * 4.0;

   }


};



int twitch::korishama_polymorphism_main()
{

   auto ptriangle = __new(TriangleRegular());

   auto pcircle = __new(Circle());

   auto psquare = __new(Square());

   pointer_array < Figure > figures({ptriangle, pcircle, psquare});


   for (auto pfigure : figures)
   {

      std::cout << "perimeter of " << pfigure->get_name() << " is " << pfigure->get_perimeter() << std::endl;

   }

   return 0;

}
