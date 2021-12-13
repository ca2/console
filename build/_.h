#pragma once


#include "apex/_.h"
#include "app/build/_.h"


#ifdef _CONSOLE_BUILD_LIBRARY
#define CLASS_DECL_CONSOLE_BUILD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_CONSOLE_BUILD  CLASS_DECL_IMPORT
#endif



