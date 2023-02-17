// From application_build_helper to implement.cpp by camilo on 2021-12-17 21:04 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#define FACTORY console_application_build_helper
#define __APP_ID "console/application_build_helper"
//#ifdef CUBE
//#include "_static_factory_.inl"
//#endif
#include "application_build_helper/application_build_helper.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/platform/system.h"
#define NO_NETWORKING
#include "acme/console.h"
//#include "acme/console.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application.h"


void package_windows(::acme::system* psystem, const ::file::path& pathFolder);


namespace application_build_helper
{

   //#define EXTRA_DEBUG

   application g_application_build_helper;

   //void application_build_helper::on_request(::request* prequest)
   //{
   //
   //   on_application_build_helper_request(prequest);
   //
   //   exit_application();
   //
   //}



   application::application()
   {

      m_strAppId = "console/application_build_helper";
      //m_bTranslateDependency = false;
      m_bNetworking = false;
      //   m_eexclusiveinstance = e_exclusive_instance_none;

   }


   application::~application()
   {

   }




   void application::main()
   {

      application_build_helper_main();

      //exit_application();

   }


   //void application_build_helper::on_application_build_helper_request(::request * prequest)
   void application::application_build_helper_main()
   {

#ifdef EXTRA_DEBUG

      auto pwszCommandLine = ::GetCommandLineW();

      ::Sleep(30'000);

#endif



      //initialize(pcontext);

      auto psystem = acmesystem();

      auto psubsystem = psystem->m_psubsystem;

      if (psubsystem->get_argument_count1() == 1)
      {

         string strArgument1 = psubsystem->get_argument1(0);

         if (strArgument1.case_insensitive_order("-generate_documentation") == 0)
         {

            try
            {

               generate_documentation();

            }
            catch (const exception & exception)
            {

               printf("Exception has occurred: %s\n", exception.m_strMessage.c_str());
               printf("Exception details:\n%s\n", exception.m_strDetails.c_str());

            }
            catch (...)
            {

               printf("catch all exception has occurred generating documentation");
            }

         }

         return;

      }

      if (psubsystem->get_argument_count1() >= 2)
      {

         string strArgument1 = psubsystem->get_argument1(0);

         string strArgument2 = psubsystem->get_argument1(1);

         string strArgument3 = psubsystem->get_argument1(2);

         string strArgument4 = psubsystem->get_argument1(3);

         string strArgument5 = psubsystem->get_argument1(4);

         if (strArgument1.case_insensitive_order("-package") == 0)
         {

            printf("application_build_helper -package %s\n", strArgument2.c_str());

            printf("output_dir : %s\n", strArgument3.c_str());

            application_build_helper applicationbuildhelper(this);

            applicationbuildhelper.set_package_folder(strArgument2);

            applicationbuildhelper.m_pathOutput = strArgument3;

            applicationbuildhelper.package();

            return;

         }
         else if (strArgument1.case_insensitive_order("-prepare_project") == 0)
         {

            string strArgument4 = psubsystem->get_argument1(3);

            //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

            application_build_helper applicationbuildhelper(this);

            applicationbuildhelper.set_package_folder(strArgument2);

            applicationbuildhelper.prepare_project();

            return;

         }
         else if (strArgument1.case_insensitive_order("-prepare_projects") == 0)
         {

            //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

            auto straProjects = psystem->m_pacmefile->lines(strArgument2);

            for (auto & strProject : straProjects)
            {

               printf("%s\n", strProject.c_str());

               if (strProject.case_insensitive_ends("/operating-system-windows/x64"))
               {

                  ::output_debug_string("is it here");

               }

               try
               {

                  application_build_helper applicationbuildhelper(this);

                  applicationbuildhelper.set_package_folder(strProject);

                  applicationbuildhelper.prepare_project();

               }
               catch (const ::exception & e)
               {

                  fprintf(stderr, "%s: \"%s\"\n", e.m_strMessage.c_str(), e.m_strDetails.c_str());

               }

            }

            return;

         }
         else if (strArgument1.case_insensitive_order("-prepare_application") == 0)
         {

            //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

            //set_package_folder(strArgument2);

            //prepare_project();

            ::string strPackageFolder = strArgument2;

            application_build_helper applicationbuildhelper(this);

            applicationbuildhelper.m_strProjectName = strArgument3;

            applicationbuildhelper.m_strBuildPlatform = strArgument4;

            applicationbuildhelper.m_strBuildConfiguration = strArgument5;

            applicationbuildhelper.m_bSoftBuild = true;

            applicationbuildhelper.set_package_folder(strPackageFolder);

            applicationbuildhelper.prepare_project();

            applicationbuildhelper.prepare_application();

            // return;

            return;

         }
         else if (strArgument1.case_insensitive_order("-prepare_applications") == 0)
         {

            //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

            auto straApplications = psystem->m_pacmefile->lines(strArgument2);

            for (auto & strApplication : straApplications)
            {

               try
               {

                  printf("%s\n", strApplication.c_str());

                  if (strApplication.case_insensitive_contains("musical_player_lite"))
                  {

                     output_debug_string("musical_player_lite");

                  }

                  application_build_helper applicationbuildhelper(this);

                  applicationbuildhelper.m_strBuildPlatform = strArgument3;

                  applicationbuildhelper.m_strBuildConfiguration = strArgument4;

                  applicationbuildhelper.m_bSoftBuild = true;

                  applicationbuildhelper.set_package_folder(strApplication);

                  applicationbuildhelper.prepare_application();

               }
               catch (const exception & exception)
               {

                  printf("Exception has occurred: %s\n", exception.m_strMessage.c_str());
                  printf("Exception details:\n%s\n", exception.m_strDetails.c_str());

               }
               catch (...)
               {

                  printf("catch all exception has occurred for application: %s\n", strApplication.c_str());
               }

            }

            return;

         }

      }

      if (psubsystem->get_argument_count1() == 3)
      {

         string strArgument1 = psubsystem->get_argument1(0);

         string strArgument2 = psubsystem->get_argument1(1);

         string strArgument3 = psubsystem->get_argument1(2);

         if (strArgument1.case_insensitive_order("-package") == 0)
         {

            printf("application_build_helper -package %s\n", strArgument2.c_str());

            printf("output_dir : %s\n", strArgument3.c_str());

            application_build_helper applicationbuildhelper(this);

            applicationbuildhelper.set_package_folder(strArgument2);

            applicationbuildhelper.m_pathOutput = strArgument3;

            applicationbuildhelper.package();

            return;

         }
         else if (strArgument1.case_insensitive_order("zip_matter") == 0)
         {

            string strFolder = strArgument2;

            application_build_helper applicationbuildhelper(this);

            applicationbuildhelper.set_package_folder(strFolder);

            applicationbuildhelper.zip_matter();

            return;

         }

      }

      if (psubsystem->get_argument_count1() >= 2)
      {

         ::string strPackageFolder = psubsystem->get_argument1(0);

         application_build_helper applicationbuildhelper(this); 
         
         applicationbuildhelper.m_strBuildPlatform = psubsystem->get_argument1(2);

         applicationbuildhelper.m_strBuildConfiguration = psubsystem->get_argument1(3);

         applicationbuildhelper.m_bSoftBuild = true;

         applicationbuildhelper.set_package_folder(strPackageFolder);

         applicationbuildhelper.prepare_project();

         applicationbuildhelper.prepare_application();

         return;

      }

      printf("Don't know what to do\n");

   }


} // namespace application_build_helper



