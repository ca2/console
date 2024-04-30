// Created by camilo on 2022-10-13 13:42 <3ThomasBorregaardSorensen!!
#pragma once


class unit_test_set;


class unit_test :
   public particle
{
public:


   string   m_strName;
   string   m_strText;
   bool     m_bTestPassed;


   unit_test(const char * pszName, unit_test_set * punittestset);

   virtual ~unit_test();

   virtual bool test();

   void run() override;

   string get_report();

   void print(const char * psz);
   //void print_unit_test_result(bool bResult, const char * pszUnitTest);

   bool test_passed() const { return m_bTestPassed; }

};

//static pointer_array < TYPE >static_instantiatior::s_a;


#define DO_UNIT_TEST(xxx) \
print_unit_test_result(unit_test_ ## xxx(), _STRINGFY(unit_test_ ## xxx));

#define __begin(xxx) \
class unit_test_ ## xxx : public unit_test \
{ public:  \
unit_test_ ## xxx(unit_test_set * punittestset): unit_test(STRINGFY(xxx), punittestset) {} \
bool test() override \
{ 


#define __end(b) \
return (b); \
} }  TOKENPASTE2(TOKENPASTE2(g_unittest, MODULE), __LINE__) (::unit_test_set::get());

//#define DECLARE_UNIT_TEST(xxx) \
//bool unit_test_ ## xxx()
//

//DECLARE_UNIT_TEST(string);
//DECLARE_UNIT_TEST(atom);





class unit_test_set :
   public pointer_array < unit_test >
{
public:


   static unit_test_set * get();

   ::raw::count m_cPassed;

   void run_all(bool bVerbose)
   {

      for (auto & p : *this)
      {

         p->set_verbose(bVerbose);

         p->run();

         if (p->test_passed())
         {

            m_cPassed++;

         }

      }


   }

};





