// Created by camilo from application.cpp on 2023-06-07 02:18 <3ThomasBorregaardSorensen
#pragma once


#include "acme/platform/application.h"


namespace console_hello
{


   class application :
      virtual public ::acme::application
   {

   public:


      application();
      ~application() override;


      void test_datetime_format(char ch);
      void test_contatenation(char ch);

      void remove_utf8_bom_phase1();
      void remove_utf8_bom_phase2();

      void main() override;


   };


} // namespace console_hello



