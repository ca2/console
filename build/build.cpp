#include "framework.h"
#include "_main.inl"


void implement(class ::system * psystem)
{


#ifdef LINUX

   ::factory::add_factory_item< ::linux::build, ::app_build::build>();

#endif

   auto papp = psystem->m_pappStartup;

   papp->osthread_init();

   papp->init_thread();

   auto pbuild = papp->__create < ::app_build::build>();

   pbuild->m_bStdout = true;

   //auto estatus =
   //
   pbuild->run();

   psystem->m_estatus = pbuild->m_estatus;

}



