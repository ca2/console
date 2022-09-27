// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#ifdef WINDOWS
#include "apex_windows/_.h"
#endif
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "aura/_defer.h"


void application_build_helper::prepare_project()
{

   auto pathBaseDeployIgnore = m_pathGroup / ".deployignore";

   auto straIgnoreRoot = m_psystem->m_pacmefile->lines(pathBaseDeployIgnore);

   if (straIgnoreRoot.contains_ci(m_strRoot))
   {

      return;

   }

   auto pathRootDeployIgnore = m_pathGroup / m_strRoot / ".deployignore";

   auto straIgnoreItem = m_psystem->m_pacmefile->lines(pathRootDeployIgnore);

   if (straIgnoreItem.contains_ci(m_strItem))
   {

      return;

   }

   if (m_strItem.compare_ci("include") == 0)
   {

      return;

   }

   if (m_strItem.begins("_"))
   {

      return;

   }

#ifdef WINDOWS_DESKTOP

   if (m_strRoot == "app"
      && m_strItem == "acme")
   {

      string_array straOutput;

      int iExitCode = 0;

      string_array straCommand;

      auto pathBeforeBase = m_pathBaseDir - 1;

      auto pathStorage = pathBeforeBase / "operating-system/storage-windows";

      auto pathPlatformConfiguration = pathStorage / m_strBuildPlatform / m_strBuildConfiguration;

      string strPlatformConfiguration = pathPlatformConfiguration;

      strPlatformConfiguration.find_replace("/", "\\");

      auto pathOutDir = m_pathBaseDir / "time-windows";

      string strOutDir = pathOutDir;

      strOutDir.find_replace("/", "\\");

      straCommand.add("cmd.exe /c xcopy /Y \"" + strPlatformConfiguration + "\\binary\\*.*\" \"" + strOutDir + "\"");
      straCommand.add("cmd.exe /c xcopy /Y \"" + strPlatformConfiguration + "\\third\\binary\\*.*\" \"" + strOutDir + "\"");
      straCommand.add("cmd.exe /c xcopy /Y \"" + strPlatformConfiguration + "\\library\\*.pdb\" \"" + strOutDir + "\"");

      for (auto & strCommand : straCommand)
      {

         command_system(straOutput, iExitCode, strCommand, e_command_system_inline_log);

      }

   }

#endif

   generate_deployment_rc();

   if (m_strItem.compare_ci("deployment") != 0)
   {

      ::file::path pathResource = m_pathFolder / "resource.h";

      if (!file_exists(pathResource))
      {

         ::file::path pathResourceTemplate = m_pathOperatingSystem / ("operating-system-" PLATFORM_STRING) / "deployment/resource1.h";

         m_psystem->m_pacmefile->copy(pathResource, pathResourceTemplate, false);

      }

   }

}


void application_build_helper::generate_deployment_rc()
{

   //::e_status estatus = ::success;

   if(m_strItem.compare_ci("deployment") != 0)
   {

      ::file::path pathDeploymentRcTemplate = m_pathOperatingSystem / ("operating-system-" PLATFORM_STRING) / "deployment/deployment_rc.txt";

      string strDeploymentRcTemplate = m_psystem->m_pacmefile->as_string(pathDeploymentRcTemplate);

      string strDeploymentRc = ::str().find_replace("%ROOTNAME%", m_strRoot, strDeploymentRcTemplate);

      strDeploymentRc.find_replace("%PROJECTNAME%", m_strItem);

      ::file::path pathDeploymentRc = m_pathFolder / "deployment.rc";

      m_psystem->m_pacmefile->put_contents(pathDeploymentRc, strDeploymentRc);

}

}

