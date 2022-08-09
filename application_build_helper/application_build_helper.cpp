
#include "framework.h"
//#include "acme/console.h"
#include "acme/filesystem/file/_constant.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"
//#include "_factory.h"


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

   pathFolder = m_psystem->m_pacmepath->defer_process_relative_path(pathFolder);

   //printf("Processing folder: %s\n", pathFolder.c_str());

   m_pathFolder = pathFolder;

   m_pathBaseDir = pathFolder - 3;

   m_pathGroup = pathFolder - 2;

   m_pathOperatingSystem = m_pathBaseDir / "operating-system";

   m_pathSource = m_pathBaseDir / "source";

   {

      ::file::path pathIterator = pathFolder;

      m_strItem = pathIterator.name();

      pathIterator.ascend();

      m_strRoot = pathIterator.name();

   }

   //load_application_list();

   m_strAppId = m_strRoot + "/" + m_strItem;

   m_strUnderscoreAppId = m_strAppId;

   m_strUnderscoreAppId.find_replace("/", "_");

   m_strUnderscoreAppId.find_replace("-", "_");

#ifdef WINDOWS

   m_strOperatingSystem2 = "windows";

   m_strSlashedOperatingSystem = "windows";

#elif defined(FREEBSD)

   m_strOperatingSystem2 = "freebsd";

   m_strSlashedOperatingSystem = "freebsd";

#elif defined(MACOS)

   m_strOperatingSystem2 = "macos";

   m_strSlashedOperatingSystem = "macos";

#elif defined(LINUX)

   string strOperatingSystem;

   strOperatingSystem = getenv("__SYSTEM_UNDERSCORE_OPERATING_SYSTEM");

   string strSlashedOperatingSystem;

   strSlashedOperatingSystem = getenv("__SYSTEM_SLASHED_OPERATING_SYSTEM");

   if (strOperatingSystem.is_empty() || strSlashedOperatingSystem.is_empty())
   {

      printf("%s", "Did you set __SYSTEM_SLASHED_OPERATING_SYSTEM and __SYSTEM_UNDERSCORE_OPERATING_SYSTEM environment variables?\n");
      printf("%s", "(They can be set \"automatically\" with patch_bashrc)\n");

      //return error_wrong_state;

      throw ::exception(error_wrong_state);

   }

   m_strOperatingSystem2 = strOperatingSystem;

   m_strSlashedOperatingSystem = strSlashedOperatingSystem;

#endif

   m_strOperatingSystem2.trim();

   m_strSlashedOperatingSystem.trim();

   ///return ::success;

}


//
//
//void application_build_helper::load_application_list()
//{
//
//   auto pathApplicationMatterList = m_pathBaseDir / "application_list.txt";
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
//      strPath.ends_eat_ci("application.txt");
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

   auto pathIgnorePackage = m_pathOperatingSystem / ("operating-system-" OPERATING_SYSTEM_NAME) / "ignore_packages.txt";

   m_straIgnorePackage = get_lines(pathIgnorePackage);

   ::file::path pathPackageMap;

   pathPackageMap = m_pathOperatingSystem / ("operating-system-" OPERATING_SYSTEM_NAME) / "operating-system" / m_strSlashedOperatingSystem /"package_map.txt";

   try
   {

      m_piniPackageMap = m_psystem->m_papexsystem->file().get_ini(pathPackageMap);

   }
   catch(const ::exception & e)
   {

      fprintf(stderr,"\n\nFatal! Failed to open package map file: %s\n(Does it exist?)\n\n\n", pathPackageMap.c_str());

      throw e;

   }

   if(is_null(m_piniPackageMap))
   {

      fprintf(stderr,"\n\nFatal! Failed to open package map file: %s\n(Does it exist?)\n\n\n", pathPackageMap.c_str());

      throw ::exception(error_failed);

   }

   ::package_reference packagereference;

   packagereference.m_strPackage = m_strAppId;

   packagereference.m_iLine = -1;

   add_package(packagereference);

   //return ::success;

}


void application_build_helper::translate_package_list()
{

   //::e_status estatus = ::success;

   m_bTranslateDependency = true;

   auto packagereferenceaCopy = m_packagereferencea;

   m_packagereferencea.clear();

   for (auto& packagereference : packagereferenceaCopy)
   {

      //estatus = 
      
      add_package(packagereference);

      //if(!estatus)
      //{

      //   break;

      //}

   }

//   return estatus;

}

   //void application_build_helper::set_base_dir(const ::file::path& pathBaseDir)
   //{

   //   m_pathOperatingSystem = pathBaseDir / "operating-system";

   //   m_pathSource = pathBaseDir / "source";

   //   m_straIgnorePackage = get_lines(m_pathOperatingSystem / ("operating-system-" OPERATING_SYSTEM_NAME) / "ignore_packages.txt");

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

         printf("%s", "");

      }

      if (m_straIgnorePackage.contains_ci(packagereference.m_strPackage))
      {

         return;

      }

      if (packagereference.m_strPackage.ends_ci("node_windows"))
      {

         printf("%s", "");

      }

      string_array stra;

      stra.explode("/", packagereference.m_strPackage);

      if(stra.get_size() == 1 && packagereference.m_strPackage.compare_ci("none") == 0)
      {

         return;

      }

      if (stra.get_size() != 2 && !packagereference.m_strPackage.begins_ci("default_"))
      {

         //printf("Error in package: \"%s\"\n", strPackage.c_str());

         auto psz =

#ifdef WINDOWS

         "%s(%d,1)"

#else

         "%s:%d:1"

#endif
         ": error: package name must have one and only one slash.\n";

         fprintf(stderr, psz, packagereference.m_pathReference.c_str(), packagereference.m_iLine + 1);

         throw ::exception(error_failed);

      }

      if (m_packagereferencea.is_empty())
      {

         package_reference packagereferenceNew;

         packagereferenceNew.m_strPackage = m_strRoot + "/" + m_strUnderscoreAppId;

         packagereferenceNew.m_pathReference = packagereference.m_pathReference;

         packagereferenceNew.m_iLine = packagereference.m_iLine;

         if (packagereferenceNew.m_strPackage.ends_ci("veriwell_multimedia"))
         {

            printf("%s", "");

         }

         m_packagereferencea.add(packagereferenceNew);

      }
      else
      {

         package_reference packagereferenceNew;

         packagereferenceNew = packagereference;

         packagereferenceNew.m_strPackage = defer_translate_application_name(packagereferenceNew.m_strPackage);

         packagereferenceNew.m_strPackage = defer_binary_to_project(packagereferenceNew.m_strPackage);

         for (auto& packagereferenceItem : m_packagereferencea)
         {

            if (packagereferenceItem.m_strPackage.trimmed().compare_ci(packagereferenceNew.m_strPackage.trimmed()) == 0)
            {

               return;

            }

         }

         if (packagereference.m_strPackage.ends_ci("node_windows"))
         {

            //printf("test");

         }

         if (packagereferenceNew.m_strPackage.ends_ci("veriwell_multimedia"))
         {

            printf("%s", "");

         }

         m_packagereferencea.add(packagereferenceNew);

      }

      add_package_dependencies(packagereference);

      //if(!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   void application_build_helper::add_package_dependencies(const ::package_reference& packagereference)
   {

      //::e_status estatus = ::success;

      auto packagereferencea = get_all_package_dependencies(packagereference.m_strPackage);

      for (auto& packagereferenceItem : packagereferencea)
      {

         //estatus = 
         
         add_package(packagereferenceItem);

         //if(!estatus)
         //{

         //   break;

         //}

      }

      //return estatus;

   }


   string_array application_build_helper::get_lines(const ::file::path & path, bool bNoExceptionIfNotFound)
   {

      auto strInput = m_psystem->m_pacmefile->as_string(path, -1, bNoExceptionIfNotFound);

      if(strInput.is_empty())
      {

         return {};

      }

      string_array stra;

      stra.add_lines(strInput, true);

      return stra;

   }


   package_reference_array application_build_helper::get_package_list(const ::string& strList, const ::string& strPackage)
   {

      ::file::path path;

      if (strPackage.begins_ci("operating-system-"))
      {

         path = m_pathOperatingSystem;

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



