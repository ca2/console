#include "acme/_start.h"
#include "acme/_.h"
#if defined(WINDOWS_DESKTOP) && defined(CUBE)
#include "_static_factory.inl"
#endif
#include "acme/console.h"


void implement(class ::system * psystem)
{

   printf("\n");

   printf("\n");

   printf("Hello!!");

   printf("\n");

   printf("\n");

   os_message_box(psystem, "Hello!!", "Hello App!", e_message_box_yes_no_cancel);

#ifdef _UWP

   getchar();

   getchar();

#endif

}



