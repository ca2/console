// Created by camilo on 2022-10-13 13:42 <3ThomasBorregaardSorensen!!
#include "framework.h"
#ifdef WITH_UNIT_TEST
#include "item.h"
#include "set.h"


namespace unit_test
{


   item::item(const char * pszName) :
      m_strName(pszName)
   {

      if (::unit_test::set::t_bEndGroup)
      {

         ::unit_test::set::t_bEndGroup = false;

         ::unit_test::set::t_pset = ::unit_test::set::t_pset->m_psetParent;

      }

      m_psetParent = ::unit_test::set::t_pset;

      if (m_psetParent)
      {

         m_psetParent->add_item(this);

      }

      //if (::unit_test::set::t_bEndGroup)
      //{

      //   ::unit_test::set::t_bEndGroup = false;

      //   ::unit_test::set::t_pset = ::unit_test::set::t_pset->m_psetParent;

      //}

   }

   item::item(enum_add_set, const  char * pszName) :
      m_strName(pszName)
   {

      if (::unit_test::set::t_bEndGroup)
      {

         ::unit_test::set::t_bEndGroup = false;

         ::unit_test::set::t_pset = ::unit_test::set::t_pset->m_psetParent;

      }

      m_psetParent = ::unit_test::set::t_pset;

      if (m_psetParent)
      {

         m_psetParent->add_item(this);

      }

      //::unit_test::set::t_bEndGroup = false;

      //if (::unit_test::set::t_bSwitchToParentAfterAddItem)
      //{

      //   ::unit_test::set::t_bSwitchToParentAfterAddItem = false;

      //   ::unit_test::set::t_pset = ::unit_test::set::t_pset->m_psetParent;

      //}

   }

   item::~item()
   {


   }


   void item::print(const char * psz)
   {

      m_strText.append_format("%s", psz);

   }


   void item::printf(const char * psz, ...)
   {

      va_list argList;

      va_start(argList, psz);

      m_strText.append_format_arguments(psz, argList);

      va_end(argList);

   }



   void item::run()
   {

      m_bTestPassed = test();

      //string strReport = get_report();

      //printf("%s", strReport.c_str_for_printf());


   }


   string item::get_plain_text_report(bool bExpanded)
   {

      string strReport;

      strReport.append_format("%s", m_strName.c_str_for_printf());

      if (is_verbose() && m_strText.has_char())
      {

         strReport += "\n";

         strReport.append_format("%s", m_strText.c_str_for_printf());

         strReport.append_format("%s", string('.', m_psetParent->m_iResultDotPadding));

      }
      else
      {

         strReport.append_format("%s", string('.', m_psetParent->m_iResultDotPadding - m_strName.length()));

      }

      if (m_bTestPassed)
      {

         strReport.append_format("...OK!");

      }
      else
      {

         strReport.append_format("... failed!!");

      }

      return strReport;

   }


   bool item::test()
   {

      return false;

   }


} // namespace unit_test




#endif