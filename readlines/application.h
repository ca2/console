#pragma once


#define NO_NETWORKING


#include "aqua/_.h"
#include "aqua/platform/application.h"

namespace console_readlines
{


   class application :
      virtual public ::aqua::application
   {
   public:


      application();
      ~application() override;


      void main() override;


   };


} // namespace console_readlines



