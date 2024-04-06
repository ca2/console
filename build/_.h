#pragma once


#include "apex/_.h"
#include "app/build/_.h"


#if defined(_console_build_project)
#define CLASS_DECL_CONSOLE_BUILD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_CONSOLE_BUILD  CLASS_DECL_IMPORT
#endif



