// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#ifdef WINDOWS
#include "apex_windows/_.h"
#endif
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"


void application_build_helper::prepare_project()
{

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

      ::file::path pathDeploymentRcTemplate = m_pathOperatingSystem / ("operating-system-" PLATFORM_STRING) / "deployment/deployment.rc";

      string strDeploymentRcTemplate = m_psystem->m_pacmefile->as_string(pathDeploymentRcTemplate);

      string strDeploymentRc = ::str().find_replace("%ROOTNAME%", m_strRoot, strDeploymentRcTemplate);

      strDeploymentRc.find_replace("%PROJECTNAME%", m_strItem);

      ::file::path pathDeploymentRc = m_pathFolder / "deployment.rc";

      m_psystem->m_pacmefile->put_contents(pathDeploymentRc, strDeploymentRc);

}

}

