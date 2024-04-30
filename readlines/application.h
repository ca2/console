#pragma once


#define NO_NETWORKING


#include "aqua/_.h"
#include "aqua/platform/application.h"



class console_readlines :
   virtual public ::aqua::application
{
public:


   console_readlines();
   void main() override;


};

