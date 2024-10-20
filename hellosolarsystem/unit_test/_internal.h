#pragma once


#include "_.h"


//#define DO_UNIT_TEST(xxx) \
//print_unit_test_result(unit_test::xxx(), _MAKE_STRING(unit_test::xxx));

#define __begin(xxx) \
class item_ ## xxx : public ::unit_test::item \
{ public: \
item_ ## xxx(): item(MAKE_STRING(xxx)) {} \
 \
bool test() override { 


#define __end(b) \
return (b); \
} \
 \
} TOKEN_CONCATENATE(m_unittest,__LINE__);

//#define DECLARE_UNIT_TEST(xxx) \
//bool unit_test_ ## xxx()
//

//DECLARE_UNIT_TEST(string);
//DECLARE_UNIT_TEST(atom);





//::unit_test::switch_to_parent_before_add_item TOKEN_CONCATENATE(m_switchtoparentbeforeadditem, __LINE__); 


#define __START(xxx) \
class TOKEN_CONCATENATE(set_, xxx) : \
   virtual public ::unit_test::set \
{ \
public: TOKEN_CONCATENATE(set_, xxx)() : set(MAKE_STRING(xxx)),item(e_add_set, MAKE_STRING(xxx)) {}



#define __MAIN_START() \
namespace unit_test {  \
      namespace MODULE { \
__START(MODULE)



#define __END() \
} TOKEN_CONCATENATE(m_unitest, __LINE__); \
::unit_test::end_group TOKEN_CONCATENATE(m_endgroup, __LINE__);



#define __MAIN_END() \
};\
   }  \
}  \
DECLARE_UNIT_TEST_SET(MODULE) \
{ \
\
auto p= ___new ::unit_test::MODULE::TOKEN_CONCATENATE(set_, MODULE)(); \
::unit_test::set::t_bEndGroup = false;\
return p;\
\
}
