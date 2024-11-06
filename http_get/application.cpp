#include "framework.h"
#include "acme/console.h"
#include <stdio.h>
#include "acme/platform/system.h"
#include "acme/prototype/prototype/url.h"
#include "apex/networking/http/context.h"


namespace console
{


   namespace http_get
   {

      class application :
         virtual public ::apex::application
      {
      public:


         application()
         {

            m_bNetworking = true;

            m_bCrypto = false;

            m_bResource = false;

            m_strAppId = "console/http_get";

         }


         void main() override
         {

            auto psystem = system();

            auto psubsystem = psystem->m_psubsystem;

            if (psubsystem->get_argument_count1() < 1)
            {

               fprintf(stderr, "No URL supplied.");

               return;

            }

            bool bTrim = false;

            string strCaseInsensitveEndsEat;

            string_array straUrl;

            for (int i = 0; i < psubsystem->get_argument_count1(); i++)
            {

               string strArgument = psubsystem->get_argument1(i);

               if (strArgument.case_insensitive_equals("-trim"))
               {

                  bTrim = true;

               }
               else if (strArgument.case_insensitive_equals("-case_insensitive_ends_eat"))
               {

                  strCaseInsensitveEndsEat = psubsystem->get_argument1(++i);

               }
               else if (!strArgument.begins("-"))
               {

                  straUrl.add(strArgument);

               }

            }

            ::property_set set;

            system()->url()->defer_raw_http(set);

            set["disable_common_name_cert_check"] = true;

            string strHttpGetTotal;

            for (auto & strUrl : straUrl)
            {

               auto strHttpGet = http()->get(strUrl, set);

               strHttpGetTotal += strHttpGet;

            }

            if (bTrim)
            {

               strHttpGetTotal.trim();

            }

            if (strCaseInsensitveEndsEat.has_character())
            {

               strHttpGetTotal.case_insensitive_ends_eat(strCaseInsensitveEndsEat);

            }

            printf("%s", strHttpGetTotal.c_str());


         }



      };


   } // namespace http_get


} // namespace console


::console::http_get::application g_console_http_get_application;



