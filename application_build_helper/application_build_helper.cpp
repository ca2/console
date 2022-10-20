
#include "framework.h"
//#include "acme/console.h"
#include "acme/filesystem/file/_constant.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "apex/filesystem/filesystem/file_context.h"
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


   package_reference_array application_build_helper::get_package_list(const ::string& strList, const ::string& strPackageParam)
   {

      ::file::path path;

      ::string strPackage = strPackageParam;

      if (strPackage.begins_ci("operating-system-"))
      {

         path = m_pathOperatingSystem;

      }
      else
      {

         path = m_pathSource;

         ::str().replace_prefix(strPackage, "port/", "third/");

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





void application_build_helper::copy_icon_ico()
{

   ::file::path pathRoot = m_pathFolder - 1;

   ::file::path pathSource = pathRoot / "_matter" / m_strItem / "_std/_std/main";

   ::file::path pathIconSource = pathSource / "icon.ico";

   ::file::path pathIconTarget = m_pathFolder / "icon.ico";

   if (!m_psystem->m_pacmefile->exists(pathIconSource))
   {

      string strMessage;

      strMessage.format("The icon file is missing: \"%s\".\n", pathIconSource.c_str());

      fprintf(stderr, "%s", strMessage.c_str());

      throw ::exception(error_not_found, strMessage);

   }

   m_psystem->m_pacmefile->overwrite_if_different(pathIconTarget, pathIconSource);

}


void application_build_helper::generate__main()
{

   {

      ::file::path pathMain = m_pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_main.inl";

      string strMain;

      strMain += "#define APPLICATION " + m_strUnderscoreAppId + "\n";
      strMain += "#define __APP_ID \"" + m_strAppId + "\"\n";
      //strMain += "#if defined(WINDOWS_DESKTOP) && defined(CUBE)\n";
      strMain += "#include \"_static_factory.inl\"\n";
      //strMain += "#endif\n";
      //strMain += "#include \"_factory.h\"\n";
      strMain += "#include \"acme/application.h\"\n";

      ///estatus =
      //m_psystem->m_pacmefile->set_file_normal(pathMain);

      //if(!estatus)
      //{

      //   return estatus;

      //}

      //estatus =

      m_psystem->m_pacmefile->put_contents(pathMain, strMain);

      //if(!estatus)
      //{

      //   return estatus;

      //}

   }

   {

      ::file::path pathApps = m_pathFolder / "_apps.txt";

      string strApps = m_psystem->m_pacmefile->as_string(pathApps);

      strApps.trim();

      string_array straApps;

      straApps.add_lines(strApps, false);

      straApps.trim();

      straApps.erase_empty();

      straApps.add("");

      //if(strApps.has_char())
      {

         for (index i = 0; i < straApps.get_count(); i++)
         {

            ::string strAppAddUp = straApps[i];

            strAppAddUp.trim();

            string strAppName = m_strUnderscoreAppId;

            if (strAppAddUp.has_char())
            {

               strAppName += "_" + strAppAddUp;

            }

            {

               ::file::path pathApplication =
                  m_pathFolder / "operating-system" / m_strSlashedOperatingSystem / ("_" + strAppName + ".cpp");

               //if (!psystem->m_pacmefile->exists(pathApplication))
               {

                  string strApplication;

                  strApplication += "#include \"framework.h\"\n";

                  if (strAppAddUp.has_char())
                  {

                     strAppAddUp.make_upper();

                     strApplication += "#define " + strAppAddUp + "\n";

                  }

                  strApplication += "#include \"_main.inl\"\n";

                  //m_psystem->m_pacmefile->set_file_normal(pathApplication);

                  //if (!estatus)
                  //{

                  //   return estatus;

                  //}

                  ///estatus =

                  m_psystem->m_pacmefile->put_contents(pathApplication, strApplication);

                  /*         if (!estatus)
                           {

                              return estatus;

                           }*/

               }

            }

         }

      }

   }

   //return estatus;

}




//void command_system(const char* psz)
//{
//
//
//#ifdef WINDOWS_DESKTOP
//
//   string str(psz);
//
//   wstring wstr;
//
//   wstr = str;
//
//   ::OutputDebugStringW(wstr);
//
//   ::OutputDebugStringW(L"\n");
//
//   STARTUPINFO info = { sizeof(info) };
//   PROCESS_INFORMATION processInfo;
//   if (CreateProcessW(nullptr, wstr, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &info, &processInfo))
//   {
//      WaitForSingleObject(processInfo.hProcess, INFINITE);
//      CloseHandle(processInfo.hProcess);
//      CloseHandle(processInfo.hThread);
//   }
//#else
//
//   printf("%s\n", psz);
//   ::system(psz);
//
//#endif
//}
//

string application_build_helper::defer_translate_application_name(string strDependency)
{

   ::file::path pathApplicationMatter = m_pathSource / strDependency / "application.txt";

   auto estatus =m_psystem->m_pacmefile->exists(pathApplicationMatter);

   if(estatus)
   {

      string strPath = pathApplicationMatter;

      strPath.ends_eat_ci("application.txt");

      ::file::path path = strPath;

      string strItem = path.name();

      path.ascend();

      string strRoot = path.name();

      string strAppId = strRoot + "/" + strItem;

      string strUnderscoreAppId(strAppId);

      strUnderscoreAppId.find_replace("/", "_");

      strUnderscoreAppId.find_replace("-", "_");

      return strRoot + "/" + strUnderscoreAppId;

   }

   return strDependency;

}


string application_build_helper::defer_translate_dependency(string strDependency)
{

   strDependency.trim();

   strDependency.make_lower();

   string strTranslatedDependency = (*m_piniPackageMap)[strDependency];

   if (strTranslatedDependency.is_empty())
   {

      if (strDependency.trimmed().begins_ci("default_"))
      {

         //return success_none;
         return "";

      }

      return strDependency;

   }

   return strTranslatedDependency;

//   if (strDependency == "default_draw2d")
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      return "draw2d_gdiplus";
//
//#else
//
//      return "draw2d_cairo";
//
//#endif
//
//   }
//   else if (strDependency == "default_node")
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      return "node_windows";
//
//#else
//
//      return "node_linux";
//
//#endif
//
//   }
//   else if (strDependency == "default_windowing")
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      return "windowing_win32";
//
//#else
//
//      return "";
//
//#endif
//
//   }
//   else if (strDependency == "default_imaging")
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      return "imaging_wic";
//
//#else
//
//      return "imaging_freeimage";
//
//#endif
//
//   }
//   else if (strDependency == "default_write_text")
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      return "write_text_win32";
//
//#else
//
//      return "write_text_pango";
//
//#endif
//
//   }
//
//   return strDependency;

}


string application_build_helper::defer_binary_to_project(string strBinary)
{

   string_array stra;

   stra.explode("/", strBinary);

   if (stra.get_count() != 2)
   {

      return strBinary;

   }

   string strRoot = stra[0];

   string strName = stra[1];

   auto& map = m_mapBinaryToProject[strRoot];

   if (map["(--loaded--)"].is_empty())
   {

      load_map(map, "binary_to_project", strRoot);

   }

   string strRename;

   strRename = map[strBinary];

   if (strRename.is_empty())
   {

      return strBinary;

   }

   return strRename;

}


string application_build_helper::defer_project_to_binary(string strProject)
{

   string_array stra;

   stra.explode("/", strProject);

   if (stra.get_count() != 2)
   {

      return strProject;

   }

   string strRoot = stra[0];

   string strName = stra[1];

   auto & map = m_mapProjectToBinary[strRoot];

   if (map["(--loaded--)"].is_empty())
   {

      load_map(map, "project_to_binary", strRoot);

   }

   string strRename;

   strRename = map[strProject];

   if (strRename.is_empty())
   {

      return strProject;

   }

   return strRename;

}


void application_build_helper::load_map(string_to_string& map, string strMap, string strRoot)
{

   ::file::path pathMapBase;

   if (strRoot.begins_ci("operating-system-"))
   {

      pathMapBase = m_pathOperatingSystem;

   }
   else
   {

      pathMapBase = m_pathSource;

   }

   pathMapBase /= strRoot;

   ::file::path pathMap;

   pathMap = pathMapBase / (strMap + ".txt");

   string_array straLines;

   m_pcontext->m_papexcontext->file().get_lines(straLines, pathMap);

   for (auto& strLine : straLines)
   {

      string_array stra;

      stra.explode("=", strLine);

      if (stra.get_size() == 2)
      {

         string strName = stra[0];

         string strRename = stra[1];

         strName.trim();

         strRename.trim();

         map[strName] = strRename;

      }

   }

   map["(--loaded--)"] = "true";

}


void application_build_helper::static_factory(const ::string& strFileDst, const ::string& strFileSrc)
{

   //auto estatus =

   m_psystem->m_pacmefile->ensure_exists(strFileSrc);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   auto strInput = m_psystem->m_pacmefile->as_string(strFileSrc);

   //if(!strInput)
   //{


   //   return strInput;

   //}

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   strOutput += "#define DO_FACTORY(do) \\\n";

   //string strFactory;

   //strFactory += "BEGIN_FACTORY("+ m_strUnderscoreAppId +") \n";

   bool bFirst = true;

   for (index i = 0; i < stra.get_count(); i++)
   {

      auto& strLine = stra[i];

      strLine.trim();

      if (strLine.has_char())
      {

         string strDependency = defer_translate_dependency(strLine);

         if (strDependency.has_char())
         {

            string_array stra;

            stra.explode("/", strDependency);

            if (stra.get_size() == 2)
            {

               string strPackage = stra[1];

               if (strPackage.has_char())
               {

                  if (!bFirst)
                  {

                     strOutput += " \\\n";

                  }

                  strOutput += "do(" + strPackage + ");";

                  //strFactory += "FACTORY_DEPENDENCY(" + strPackage + ") \n";

                  bFirst = false;

               }

            }

         }

      }

   }

   strOutput += "\n";

   ///strFactory += "FACTORY_DEPENDENCY(" + m_strUnderscoreAppId + ") \n";

   //strFactory += "END_FACTORY() \n";

   //estatus =

   //m_psystem->m_pacmefile->set_file_normal(strFileDst);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //estatus =

   m_psystem->m_pacmefile->put_contents(strFileDst, strOutput);

   //m_psystem->m_pacmefile->put_contents(strFileFactory, strFactory);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //return estatus;

}


void application_build_helper::translate_items(const ::string& strFileDst, const ::string& strFileSrc)
{

   //auto estatus =

   m_psystem->m_pacmefile->ensure_exists(strFileSrc);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   auto strInput = m_psystem->m_pacmefile->as_string(strFileSrc);

   //if(!strInput)
   //{

   //   return strInput;

   //}

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   for (index i = 0; i < stra.get_count(); i++)
   {

      auto& strLine = stra[i];

      strLine.trim();

      if (strLine.has_char())
      {

         string strDependency = defer_translate_dependency(strLine);

         if (strDependency.has_char())
         {

            strOutput += strDependency;

            strOutput += "\n";

         }

      }

   }

   //estatus =

   //m_psystem->m_pacmefile->set_file_normal(strFileDst);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //estatus =

   m_psystem->m_pacmefile->put_contents(strFileDst, strOutput);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //return estatus;

}


void application_build_helper::defer_matter()
{

   ::file::path pathMatter = m_pathFolder / "matter.txt";

   //auto estatus =

   m_psystem->m_pacmefile->ensure_exists(pathMatter);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //m_psystem->m_pacmefile->set_file_normal(pathMatter);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   auto strInput = m_psystem->m_pacmefile->as_string(pathMatter);

   //if(!strInput)
   //{

   //   return strInput;

   //}

   strInput.trim();

   if (strInput.has_char())
   {

      return;

   }

   string strOutput;

   strOutput += "app/main\n";

   strOutput += m_strAppId + "\n";

   m_psystem->m_pacmefile->put_contents(pathMatter, strOutput);

}


void application_build_helper::zip_matter()
{

   ::file::path pathZip = m_pathFolder / "_matter.zip";

   ::file::path pathMatter = m_pathFolder / "matter.txt";

   //auto estatus = m_psystem->m_pacmefile->ensure_exists(pathMatter);

   m_psystem->m_pacmefile->ensure_exists(pathMatter);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   auto strInput = m_psystem->m_pacmefile->as_string(pathMatter);

   /*if(!strInput)
   {

      return strInput;

   }*/

   string strZip = pathZip;

   strZip.find_replace("\\", "/");

   string_array stra;

   stra.add_lines(strInput, false);

   ::file::path pathOutput = m_pathFolder - 2;

   m_psystem->m_pacmedirectory->change_current(pathOutput);

   bool bFirst = true;

   ::file::path pathZipExe;

#ifdef WINDOWS

   pathZipExe = (m_pathFolder - 3) / "operating-system/tool-windows/bin/zip";

#else

   pathZipExe = "zip";

#endif

   string strZipExe = pathZipExe;

   for (auto& strLine : stra)
   {

      strLine.trim();

      if (strLine.has_char())
      {

         string_array straMatter;

         straMatter.explode("/", strLine);

         if (straMatter.get_size() == 2)
         {

            string strFolder = straMatter[0] + "/_matter/" + straMatter[1];

            string_array straOutput;

            int iExitCode = 0;

            if (bFirst)
            {

               command_system(straOutput, iExitCode, strZipExe + " -FSr \"" + strZip + "\" " + strFolder + "/*", e_command_system_inline_log);

               bFirst = false;

            }
            else
            {

               command_system(straOutput, iExitCode, strZipExe + " -r \"" + pathZip + "\" " + strFolder + "/*", e_command_system_inline_log);

            }

         }

      }

   }


#ifdef WINDOWS_DESKTOP

   _wchdir(wstring("C:\\"));

#else

   {

      ::file::path pathHome = getenv("HOME");

      m_psystem->m_pacmedirectory->change_current(pathHome);

   }

#endif

   string_array straOutput;

   int iExitCode = 0;

   command_system(straOutput, iExitCode, strZipExe + " -r \"" + pathZip + "\" sensitive/sensitive/api/*", e_command_system_inline_log);

}


void application_build_helper::create_linux_matter_object()
{

   ::file::path pathMatterZipO = m_pathFolder / ".link_object/_matter.zip.o";

   m_psystem->m_pacmedirectory->change_current(m_pathFolder);

   m_psystem->m_pacmedirectory->create(m_pathFolder / ".link_object");

   string_array straOutput;

   int iExitCode = 0;

   string strCommand;

#if defined(FREEBSD)

   strCommand = "ld -r -b binary -o " + pathMatterZipO + " -m elf_amd64_fbsd -z noexecstack _matter.zip";

#else

   strCommand = "ld -r -b binary -o " + pathMatterZipO + " _matter.zip";

#endif

   command_system(straOutput, iExitCode, strCommand, e_command_system_inline_log);

   if (iExitCode != 0)
   {

      fprintf(stderr, "Command failed: %s\n", straOutput.implode("\n").c_str());

   }

}
