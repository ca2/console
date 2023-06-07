// Created by camilo on 2022-10-13 13:42 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "_internal.h"


#include "acme/primitive/primitive/atom.h"
//#include "acme/primitive/collection/numeric_array.h"
#include "acme/handler/item.h"
#include "_unit_test.h"


#ifdef WITH_UNIT_TEST


#define MODULE basic_types
__MAIN_START()
#include "basic_types.unittest.cpp"
__MAIN_END()


#undef MODULE


#define MODULE printf_format_flags
__MAIN_START()
#include "basic_types.unittest.cpp"
__MAIN_END()



#endif