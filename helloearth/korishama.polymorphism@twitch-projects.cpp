
#include <iostream>
#include <fstream>

double yes_for_two_and_no_for_three()
{
   auto psystem = ::get_system();

   auto result = message_box_synchronous(psystem, "Yes for two and No for 3", "Hello App!", e_message_box_yes_no | e_message_box_default_button_1, "Hello Multiverse!!");

   if (result == e_dialog_result_yes)
   {

      return 2.0;

   }
   else
   {

      return 3.0;

   }

}

//using namespace std;

class Figure :
   virtual public ::element
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

   Circle(double dRadius = yes_for_two_and_no_for_three())
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

   TriangleRegular(double dSide = yes_for_two_and_no_for_three())
   {

      m_dSide = dSide;

   }


   ::string get_name() override
   {

      return "TriangleRegular";

   }

   virtual double get_perimeter()
   {


      return m_dSide * 3.0;

   }


};

class Square :
   public Figure
{
public:

   double m_dSide;

   Square(double dSide = yes_for_two_and_no_for_three())
   {

      m_dSide = dSide;

   }


   ::string get_name() override
   {

      return "Square";

   }

   virtual double get_perimeter()
   {


      return m_dSide  * 4.0;

   }


};



int korishama_polymorphism_program()
{

   auto ptriangle = __new(TriangleRegular());

   auto pcircle = __new(Circle());

   auto psquare = __new(Square());

   __pointer_array(Figure) figures({ptriangle, pcircle, psquare});


   for (auto pfigure : figures)
   {

      std::cout << "perimeter of " << pfigure->get_name() << " is " << pfigure->get_perimeter() << std::endl;

   }

   return 0;

}