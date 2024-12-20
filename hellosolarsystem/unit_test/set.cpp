// Created by camilo on 2022-10-13 17:48 <3ThomasBorregaardSorensen!!
#include "framework.h"
#ifdef WITH_UNIT_TEST
#include "item.h"
#include "set.h"




namespace unit_test
{

   thread_local ::unit_test::set * set::t_pset = nullptr;
   thread_local bool set::t_bEndGroup = false;

   void set::run_all()
   {

      m_iMaximumNameLength = 0;

      for (auto & p : *this)
      {

         p->run();

         if (p->test_passed())
         {

            m_cPassed++;

         }

         m_iMaximumNameLength = maximum(m_iMaximumNameLength, p->m_strName.length());

      }

   }

   bool set::test()
   {

      run_all();

      return m_cPassed >= this->size();

   }


   ::string set::get_plain_text_report(bool bExpanded)
   {

      m_iResultDotPadding = maximum(32, m_iMaximumNameLength + 3);

      ::string strReport;

      if (bExpanded)
      {

         for (auto & p : *this)
         {

            strReport += p->get_plain_text_report(application()->m_bVerbose) + "\n";

            if (application()->m_bVerbose && p->m_strText.has_character())
            {

               strReport.append_formatf("\n");

            }

         }

         if (m_cPassed >= this->size())
         {

            strReport.append_formatf("All tests were OK!!", this->size());

         }
         else if (m_cPassed <= 0)
         {

            strReport.append_formatf("All tests failed!!!", this->size());

         }
         else if (m_cPassed == 1)
         {

            strReport.append_formatf("One test failed!");

         }
         else
         {

            strReport.append_formatf("Some tests failed! (%d)", this->size() - m_cPassed);

         }

      }
      else
      {

         strReport = item::get_plain_text_report();

      }

      strReport.append_formatf(" (%d/%d)", m_cPassed, this->size());

      if (bExpanded)
      {

         strReport += "\n";

      }

      return strReport;
      
   }



} // namespace unit_test



#endif