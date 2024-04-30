// Created by camilo on 2022-10-13 16:47 <3ThomasBorregaardSorensen!!
#pragma once


#include "item.h"
#include "acme/platform/application.h"
//#include "acme/primitive/collection/pointer_array.h"


namespace unit_test
{


   class set :
      virtual public pointer_array < item >,
      virtual public item
   {
   public:


      static thread_local set *                    t_pset;
      static thread_local bool                     t_bEndGroup;
      ::raw::count                                      m_cPassed;
      strsize                                      m_iMaximumNameLength;
      strsize                                      m_iResultDotPadding;


      set(const char * pszName) : item(e_add_set, pszName) { t_pset = this; }
      ~set() {  }


      void add_item(item * pitem)
      {

         pitem->set_verbose_flag(application()->m_bVerbose);

         add(pitem);

      }

      virtual void run_all();

      bool test() override;

      ::string get_plain_text_report(bool bExpanded = true) override;

   };


   class end_group
   {
   public:

      end_group()
      {

         set::t_bEndGroup = true;


      }

   };


} // namespace unit_test


#define DECLARE_UNIT_TEST_SET(MODULE) ::unit_test::set * TOKEN_CONCATENATE(TOKEN_CONCATENATE(new_, MODULE), _unit_test_set)()



