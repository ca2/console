// Created by camilo on 2022-10-13 13:42 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/prototype/prototype/particle.h"
// #include "acme/prototype/string/string.h"


namespace unit_test
{

   enum enum_add_set
   {

      e_add_set

   };

   class set;

   class item :
      virtual public particle
   {
   public:


      ::unit_test::set *         m_psetParent;
      string                     m_strName;
      string                     m_strText;
      bool                       m_bTestPassed;


      item(const_char_pointer pszName);
      item(enum_add_set, const_char_pointer pszName);
      ~item() override;


      virtual bool test();

      void run() override;

      virtual string get_plain_text_report(bool bExpanded = true);

      void print(const_char_pointer psz);
      void printf(const_char_pointer psz, ...);
      //void print_unit_test_result(bool bResult, const_char_pointer pszUnitTest);

      bool test_passed() const { return m_bTestPassed; }

   };


};





