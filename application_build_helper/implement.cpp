// From application_build_helper to implement.cpp by camilo on 2021-12-17 21:04 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#define FACTORY console_application_build_helper
#define __APP_ID "console/application_build_helper"
#ifdef CUBE
#include "_static_factory.inl"
#endif
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/platform/system.h"
#define NO_NETWORKING
#include "_main.inl"
//#include "acme/console.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"


void package_windows(::acme::system* psystem, const ::file::path& pathFolder);


//#define EXTRA_DEBUG


void implement(::acme::context * pcontext)
{

#ifdef EXTRA_DEBUG

   auto pwszCommandLine = ::GetCommandLineW();

   ::Sleep(30'000);

#endif

   application_build_helper helper;

   helper.initialize(pcontext);

   auto psystem = pcontext->acmesystem();

   auto psubsystem = psystem->m_psubsystem;

   if (psubsystem->get_argument_count1() == 2 || psubsystem->get_argument_count1() == 3)
   {

      string strArgument1 = psubsystem->get_argument1(0);

      string strArgument2 = psubsystem->get_argument1(1);

      string strArgument3 = psubsystem->get_argument1(2);

      if (strArgument1.compare_ci("-package") == 0)
      {

         printf("application_build_helper -package %s\n", strArgument2.c_str());

         printf("output_dir : %s\n", strArgument3.c_str());

         helper.set_package_folder(strArgument2);

         helper.m_pathOutput = strArgument3;

         helper.package();

         return;

      }
      else if (strArgument1.compare_ci("-prepare_project") == 0)
      {

         //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

         helper.set_package_folder(strArgument2);

         helper.prepare_project();

         return;

      }
      else if (strArgument1.compare_ci("-prepare_projects") == 0)
      {

         //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

         auto straProjects = psystem->m_pacmefile->lines(strArgument2);

         for (auto & strProject : straProjects)
         {

            printf("%s\n", strProject.c_str());

            helper.set_package_folder(strProject);

            helper.prepare_project();

         }

         return;

      }
      
   }
   
   if (psubsystem->get_argument_count1() == 3)
   {

      string strArgument1 = psubsystem->get_argument1(0);

      string strArgument2 = psubsystem->get_argument1(1);

      string strArgument3 = psubsystem->get_argument1(2);

      if (strArgument1.compare_ci("-package") == 0)
      {

         printf("application_build_helper -package %s\n", strArgument2.c_str());

         printf("output_dir : %s\n", strArgument3.c_str());

         helper.set_package_folder(strArgument2);

         helper.m_pathOutput = strArgument3;

         helper.package();

         return;

      }
      else if(strArgument1.compare_ci("zip_matter") == 0)
      {

         string strFolder = strArgument2;

         helper.set_package_folder(strFolder);

         helper.zip_matter();

         return;

      }

   }
   
   if (psubsystem->get_argument_count1() >= 1)
   {

      helper.m_strBuildPlatform = psubsystem->get_argument1(2);

      helper.m_strBuildConfiguration = psubsystem->get_argument1(3);

      helper.m_bSoftBuild = true;

      helper.prepare_project();

      helper.prepare_application();

      return;

   }

   printf("Don't know what to do\n");

}


