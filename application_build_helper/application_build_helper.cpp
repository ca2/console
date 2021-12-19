
#include "framework.h"
//#include "acme/console.h"
#include "acme/filesystem/file/_const.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"


application_build_helper::application_build_helper()
   {
   m_bTranslateDependency = false;
   }

application_build_helper::~application_build_helper()
   {


   }



void application_build_helper::set_package_folder(const ::file::path& pathFolderParam)
{

   ::file::path pathFolder(pathFolderParam);

   if (pathFolder.length() >= 3)
   {

      if ((pathFolder[0] == '\\' || pathFolder[0] == '/')
         && (pathFolder[2] == '\\' || pathFolder[2] == '/')
         && ansi_char_is_alphabetic(pathFolder[1]))
      {

         string str;

         str.format("%c:/", ansi_toupper(pathFolder[1]));

         pathFolder = str / (pathFolder.c_str() + 3);

      }

   }

   m_pathFolder = pathFolder;

   m_pathBaseDir = pathFolder - 3;

   m_pathArchive = m_pathBaseDir / "archive";

   m_pathSource = m_pathBaseDir / "source";

   {

      ::file::path pathIterator = pathFolder;

      m_strItem = pathIterator.name();

      pathIterator.go_up();

      m_strRoot = pathIterator.name();

   }

   //load_application_list();

   m_strAppId = m_strRoot + "/" + m_strItem;

   m_strUnderscoreAppId = m_strAppId;

   m_strUnderscoreAppId.replace("/", "_");

   m_strUnderscoreAppId.replace("-", "_");

#ifdef WINDOWS

   m_strPlatform2 = "windows";

   m_strSlashedPlatform = "windows";

#elif defined(LINUX)

   string strPlatform;

   strPlatform = getenv("UNDERSCORE_PLATFORM");

   string strSlashedPlatform;

   strSlashedPlatform = getenv("SLASHED_PLATFORM");

   if (strPlatform.is_empty() || strSlashedPlatform.is_empty())
   {

      printf("%s", "Did you set UNDERSCORE_PLATFORM and UNDERSCORE_PLATFORM environment variables?\n");
      printf("%s", "(They can be set \"automatically\" with patch_bashrc)\n");

      m_psystem->m_estatus = error_wrong_state;

      return;

   }

   m_strPlatform2 = strPlatform;

   m_strSlashedPlatform = strSlashedPlatform;

#endif

   m_strPlatform2.trim();

   m_strSlashedPlatform.trim();


}
//
//
//void application_build_helper::load_application_list()
//{
//
//   auto pathApplicationMatterList = m_pathBaseDir / "application_matter_list.txt";
//
//   string_array straApplications;
//
//   m_psystem->m_papexsystem->file().get_lines(straApplications, pathApplicationMatterList);
//
//   straApplications.trim();
//
//   for (string& strPath : straApplications)
//   {
//
//      strPath.ends_eat_ci("application_matter.txt");
//
//      ::file::path path = strPath;
//
//      string strItem = path.name();
//
//      path.go_up();
//
//      string strRoot = path.name();
//
//      string strAppId = strRoot + "/" + strItem;
//
//      string strUnderscoreAppId(strAppId);
//
//      strUnderscoreAppId.replace("/", "_");
//
//      strUnderscoreAppId.replace("-", "_");
//
//      m_mapAppId.set_at(strAppId, strRoot + "/" + strUnderscoreAppId);
//
//   }
//
//}


void application_build_helper::create_package_list()
{
   
   m_straIgnorePackage = get_lines(m_pathArchive / ("platform-" PLATFORM_NAME) / "ignore_packages.txt");

   m_piniPackageMap = m_psystem->m_papexsystem->file().get_ini(m_pathArchive / ("platform-" PLATFORM_NAME) / "package_map.txt");

   ::package_reference packagereference;

   packagereference.m_strPackage = m_strAppId;

   packagereference.m_iLine = -1;

   add_package(packagereference);

}


void application_build_helper::translate_package_list()
{

   m_bTranslateDependency = true;

   auto packagereferenceaCopy = m_packagereferencea;

   m_packagereferencea.clear();

   for (auto& packagereference : packagereferenceaCopy)
   {

      add_package(packagereference);

   }

}

   //void application_build_helper::set_base_dir(const ::file::path& pathBaseDir)
   //{

   //   m_pathArchive = pathBaseDir / "archive";

   //   m_pathSource = pathBaseDir / "source";

   //   m_straIgnorePackage = get_lines(m_pathArchive / ("platform-" PLATFORM_NAME) / "ignore_packages.txt");

   //}


   void application_build_helper::add_package(::package_reference & packagereference)
   {

      if (m_bTranslateDependency)
      {

         string strTranslate = defer_translate_dependency(packagereference.m_strPackage);

         if (strTranslate.has_char() && strTranslate != packagereference.m_strPackage)
         {

            packagereference.m_strPackage = strTranslate;

         }

         if (packagereference.m_strPackage.begins_ci("default_"))
         {

            return;

         }

      }

      if (packagereference.m_strPackage.is_empty())
      {

         return;

      }

      if (packagereference.m_strPackage.ends_ci("node_windows"))
      {

         printf("");

      }

      if (m_straIgnorePackage.contains_ci(packagereference.m_strPackage))
      {

         return;

      }

      if (packagereference.m_strPackage.ends_ci("node_windows"))
      {

         printf("");

      }

      string_array stra;

      stra.explode("/", packagereference.m_strPackage);

      if (stra.get_size() != 2 && !packagereference.m_strPackage.begins_ci("default_"))
      {

         //printf("Error in package: \"%s\"\n", strPackage.c_str());

         printf("%s(%d,1): error: package name must have one and only one slash.\n", packagereference.m_pathReference.c_str(), packagereference.m_iLine + 1);

         return;

      }

      if (m_packagereferencea.is_empty())
      {

         package_reference packagereferenceNew;

         packagereferenceNew.m_strPackage = m_strRoot + "/" + m_strUnderscoreAppId;

         packagereferenceNew.m_pathReference = packagereference.m_pathReference;

         packagereferenceNew.m_iLine = packagereference.m_iLine;

         m_packagereferencea.add(packagereferenceNew);

      }
      else
      {

         for (auto& packagereferenceItem : m_packagereferencea)
         {

            if (packagereferenceItem.m_strPackage.trimmed().compare_ci(packagereference.m_strPackage.trimmed()) == 0)
            {

               return;

            }

         }

         if (packagereference.m_strPackage.ends_ci("node_windows"))
         {

            //printf("test");

         }

         package_reference packagereferenceNew;

         packagereferenceNew = packagereference;

         packagereferenceNew.m_strPackage = defer_rename_package(packagereferenceNew.m_strPackage);

         m_packagereferencea.add(packagereferenceNew);

      }

      add_package_dependencies(packagereference);

   }


   void application_build_helper::add_package_dependencies(const ::package_reference& packagereference)
   {

      auto packagereferencea = get_all_package_dependencies(packagereference.m_strPackage);

      for (auto& packagereferenceItem : packagereferencea)
      {

         add_package(packagereferenceItem);

      }

   }


   string_array application_build_helper::get_lines(const ::file::path & path)
   {

      string strInput = m_psystem->m_pacmefile->as_string(path);

      string_array stra;

      stra.add_lines(strInput, true);

      return stra;

   }


   package_reference_array application_build_helper::get_package_list(const ::string& strList, const ::string& strPackage)
   {

      ::file::path path;

      if (strPackage.begins_ci("platform-"))
      {

         path = m_pathArchive;

      }
      else
      {

         path = m_pathSource;

      }

      path /= strPackage.trimmed();

      path /= (strList.trimmed() + ".txt");

      auto stra = get_lines(path);

      package_reference_array packagereferencea;

      int iLine = 0;

      for (auto& str : stra)
      {

         packagereferencea.add({ str, path, iLine });

         iLine++;

      }

      return packagereferencea;

   }


   package_reference_array application_build_helper::get_package_references(const ::string& strPackage)
   {

      return get_package_list("_references", strPackage);

   }


   package_reference_array application_build_helper::get_package_dependencies(const ::string& strPackage)
   {

      return get_package_list("_dependencies", strPackage);

   }


   package_reference_array application_build_helper::get_package_extensions(const ::string& strPackage)
   {

      return get_package_list("_extensions", strPackage);

   }


   package_reference_array application_build_helper::get_all_package_dependencies(const ::string& strPackage)
   {

      package_reference_array packagereferencea;

      package_reference_array straReferences = get_package_references(strPackage);

      package_reference_array straDependencies = get_package_dependencies(strPackage);

      package_reference_array straExtensions = get_package_extensions(strPackage);

      packagereferencea.append(straReferences);

      packagereferencea.append(straDependencies);

      packagereferencea.append(straExtensions);

      return packagereferencea;

   }



