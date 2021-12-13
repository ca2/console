#include "framework.h"
#include "_main.inl"


void implement(class ::system * psystem)
{


#ifdef LINUX

   ::factory::add_factory_item< ::linux::build, ::app_build::build>();

#endif

   auto papplication = psystem->m_papplicationStartup;

   papplication->osthread_init();

   papplication->init_thread();

   auto pbuild = papplication->__create < ::app_build::build>();

   pbuild->m_bStdout = true;

   auto estatus = pbuild->run();

   psystem->m_estatus = estatus;

}



