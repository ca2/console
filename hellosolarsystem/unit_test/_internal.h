#pragma once


#include "_.h"


//#define DO_UNIT_TEST(xxx) \
//print_unit_test_result(unit_test::xxx(), _STRINGFY(unit_test::xxx));

#define __begin(xxx) \
class item_ ## xxx : public ::unit_test::item \
{ public: \
item_ ## xxx(): item(STRINGFY(xxx)) {} \
 \
bool test() override { 


#define __end(b) \
return (b); \
} \
 \
} TOKENPASTE(m_unittest,__LINE__);

//#define DECLARE_UNIT_TEST(xxx) \
//bool unit_test_ ## xxx()
//

//DECLARE_UNIT_TEST(string);
//DECLARE_UNIT_TEST(atom);





//::unit_test::switch_to_parent_before_add_item TOKENPASTE(m_switchtoparentbeforeadditem, __LINE__); 


#define __START(xxx) \
class TOKENPASTE(set_, xxx) : \
   virtual public ::unit_test::set \
{ \
public: TOKENPASTE(set_, xxx)() : set(STRINGFY(xxx)),item(e_add_set, STRINGFY(xxx)) {}



#define __MAIN_START() \
namespace unit_test {  \
      namespace MODULE { \
__START(MODULE)



#define __END() \
} TOKENPASTE(m_unitest, __LINE__); \
::unit_test::end_group TOKENPASTE(m_endgroup, __LINE__);



#define __MAIN_END() \
};\
   }  \
}  \
DECLARE_UNIT_TEST_SET(MODULE) \
{ \
\
auto p= new ::unit_test::MODULE::TOKENPASTE(set_, MODULE)(); \
::unit_test::set::t_bEndGroup = false;\
return p;\
\
}
