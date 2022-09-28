// From implement.cpp by camilo on 2022-09-23 20:08 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "application_build_helper.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"


void application_build_helper::prepare_application()
{

   string strFolder = m_psystem->get_argument1(0);

   string strProjectName = m_psystem->get_argument1(1);

   set_package_folder(strFolder);

   auto pathFolder = m_pathFolder;

   ::file::path pathApplicationTxt;

   pathApplicationTxt = pathFolder / "application.txt";

   if (!m_psystem->m_pacmefile->exists(pathApplicationTxt))
   {

      return;

   }

   if (strProjectName.has_char())
   {

      if (strProjectName.begins_ci("shared_") || strProjectName.begins_ci("static_"))
      {

         return;

      }

   }

   printf("build_helper \"%s\"\n", pathFolder.c_str());

   printf("operating system: \"%s\"\n", m_strOperatingSystem2.c_str());

   create_package_list();

   string strPackages;

   for (auto & packagereference : m_packagereferencea)
   {

      strPackages += packagereference.m_strPackage.trimmed() + "\n";

   }

   ::file::path pathInl = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_static_factory.inl";

   ::file::path pathSourcePackages = pathFolder / "_packages.txt";

   ::file::path pathTargetPackages = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_packages.txt";

   m_psystem->m_pacmefile->put_contents(pathSourcePackages, strPackages);

   ::file::path pathSourceReferences;

   pathSourceReferences = pathFolder / "_references.txt";

   ::file::path pathTargetReferences;

   pathTargetReferences = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_references.txt";

   ::file::path pathDepsDeprecated;

   pathDepsDeprecated = pathFolder / "deps.txt";

   ::file::path pathSourceDependencies;

   pathSourceDependencies = pathFolder / "_dependencies.txt";

   ::file::path pathTargetDependencies;

   pathTargetDependencies = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_dependencies.txt";

   ::file::path pathSourceExtensions;

   pathSourceExtensions = pathFolder / "_extensions.txt";

   ::file::path pathTargetExtensions;

   pathTargetExtensions = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_extensions.txt";

   auto lenDepsDeprecated = m_psystem->m_pacmefile->as_string(pathDepsDeprecated).trimmed().length();

   auto lenSourceDependencies = m_psystem->m_pacmefile->as_string(pathSourceDependencies).trimmed().length();

   if (lenDepsDeprecated > 0 && lenSourceDependencies == 0)
   {

      m_psystem->m_pacmefile->set_file_normal(pathSourceDependencies);

      m_psystem->m_pacmefile->copy(pathSourceDependencies, pathDepsDeprecated, true);

   }

   generate__main();

   copy_icon_ico();

   static_factory(pathInl, pathSourceDependencies);

   translate_items(pathTargetReferences, pathSourceReferences);

   translate_items(pathTargetDependencies, pathSourceDependencies);

   translate_items(pathTargetExtensions, pathSourceExtensions);

   translate_package_list();

   string strTranslatedPackages;

   for (auto & packagereference : m_packagereferencea)
   {

      string strPackage = packagereference.m_strPackage.trimmed();

      string strTranslatedPackage = defer_project_to_binary(strPackage);

      strTranslatedPackages += strTranslatedPackage + "\n";

   }

   m_psystem->m_pacmefile->put_contents(pathTargetPackages, strTranslatedPackages);

   defer_matter();

   zip_matter();

   ::file::path pathZip = m_pathFolder / "_matter.zip";

   if (!m_psystem->m_pacmefile->exists(pathZip))
   {

      string strError;

      strError.format("\"%s\" wasn't created.", pathZip.c_str());

      throw ::exception(error_failed, strError);

   }

   auto pathSeedAndroid = m_pathOperatingSystem / "seed-android";

   if (m_psystem->m_pacmedirectory->is(pathSeedAndroid))
   {

      auto pathAssetsMatterZip = pathSeedAndroid / m_strAppId / "app/src/main/assets/_matter.zip";

      m_psystem->m_pacmefile->copy(pathAssetsMatterZip, pathZip, true);
      
   }


   int iCreateLinuxMatterObject = string(getenv("DISTRO")) == "raspbian";

#if defined(FREEBSD) || defined(LINUX)

   iCreateLinuxMatterObject = 1;

#endif

   if (iCreateLinuxMatterObject)
   {

      create_linux_matter_object();

   }

}



