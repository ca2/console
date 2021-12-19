// From application_build_helper to implement.cpp by camilo on 2021-12-17 21:04 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "_main.inl"
//#include "acme/console.h"
#include "acme/filesystem/file/_const.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"

application_build_helper* g_phelper;

void package_windows(class ::system* psystem, const ::file::path& pathFolder);

//void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder)
//{
//
//   ::file::path pathFolder = pszFolder;
//
//   strItem = pathFolder.name();
//
//   pathFolder.go_up();
//
//   strRoot = pathFolder.name();
//
//}


void application_build_helper::copy_icon_ico()
{

   ::file::path pathRoot = m_pathFolder - 1;

   ::file::path pathSource = pathRoot / "_matter" / m_strItem / "_std/_std/main";

   ::file::path pathIconSource = pathSource / "icon.ico";

   ::file::path pathIconTarget = m_pathFolder / "icon.ico";

   m_psystem->m_pacmefile->set_file_normal(pathIconTarget);

   m_psystem->m_pacmefile->overwrite_if_different(pathIconTarget, pathIconSource);

}


void application_build_helper::generate__main()
{

   {

      ::file::path pathMain = m_pathFolder / "platform" / m_strSlashedPlatform / "_main.inl";

      string strMain;

      strMain += "#define APPLICATION " + m_strUnderscoreAppId + "\n";
      strMain += "#define __APP_ID \"" + m_strAppId + "\"\n";
      strMain += "#if defined(WINDOWS_DESKTOP) && defined(CUBE)\n";
      strMain += "#include \"_static_factory.inl\"\n";
      strMain += "#endif\n";
      strMain += "#include \"acme/application.h\"\n";

      m_psystem->m_pacmefile->set_file_normal(pathMain);

      m_psystem->m_pacmefile->put_contents(pathMain, strMain);

   }

   {

      ::file::path pathApps = m_pathFolder / "_apps.txt";

      string strApps = m_psystem->m_pacmefile->as_string(pathApps);

      string_array straApps;

      straApps.add_lines(strApps, false);

      straApps.add("");

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

            ::file::path pathApplication = m_pathFolder / "platform" / m_strSlashedPlatform / ("_" + strAppName + ".cpp");

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

               m_psystem->m_pacmefile->set_file_normal(pathApplication);

               m_psystem->m_pacmefile->put_contents(pathApplication, strApplication);

            }

         }

      }

   }

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

string application_build_helper::defer_translate_dependency(string strDependency)
{

   strDependency.trim();

   strDependency.make_lower();

   string strTranslatedDependency = (*m_piniPackageMap)[strDependency];

   if (strTranslatedDependency.is_empty())
   {

      if (strDependency.trimmed().begins_ci("default_"))
      {

         return "";

      }

      ::file::path pathApplicationMatter = m_pathSource / strDependency / "application_matter.txt";

      if (m_psystem->m_pacmefile->exists(pathApplicationMatter))
      {

         string strPath = pathApplicationMatter;

         strPath.ends_eat_ci("application_matter.txt");

         ::file::path path = strPath;

         string strItem = path.name();

         path.go_up();

         string strRoot = path.name();

         string strAppId = strRoot + "/" + strItem;

         string strUnderscoreAppId(strAppId);

         strUnderscoreAppId.replace("/", "_");

         strUnderscoreAppId.replace("-", "_");

         return strRoot + "/" + strUnderscoreAppId;

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


string application_build_helper::defer_rename_package(string strPackage)
{

   string_array stra;

   stra.explode("/", strPackage);

   if (stra.get_count() != 2)
   {

      return strPackage;

   }

   string strRoot = stra[0];

   string strName = stra[1];

   auto& renamemap = m_renamemap[strRoot];

   if (renamemap["loaded"].is_empty())
   {

      load_rename_map(renamemap, strRoot);

   }

   string strRename;

   strRename = renamemap[strName];

   if (strRename.is_empty())
   {

      return strPackage;

   }

   return strRoot + "/" + strRename;

}


void application_build_helper::load_rename_map(string_to_string& renamemap, string strRoot)
{

   ::file::path pathRenameBase;

   if (strRoot.begins_ci("platform-"))
   {

      pathRenameBase = m_pathArchive;

   }
   else
   {

      pathRenameBase = m_pathSource;

   }

   pathRenameBase /= strRoot;

   ::file::path pathRename;

   pathRename = pathRenameBase / "rename_map.txt";

   string_array straLines;

   m_pcontext->m_papexcontext->file().get_lines(straLines, pathRename);

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

         renamemap[strName] = strRename;

      }

   }

   renamemap["loaded"] = "true";

}


void application_build_helper::static_factory(const ::string& strFileDst, const ::string& strFileSrc)
{

   m_psystem->m_pacmefile->ensure_exists(strFileSrc);

   string strInput = m_psystem->m_pacmefile->as_string(strFileSrc);

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   strOutput += "#define DO_FACTORY(do) \\\n";

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

                  bFirst = false;

               }

            }

         }

      }

   }

   strOutput += "\n";

   m_psystem->m_pacmefile->set_file_normal(strFileDst);

   m_psystem->m_pacmefile->put_contents(strFileDst, strOutput);

}


void application_build_helper::translate_items(const ::string& strFileDst, const ::string& strFileSrc)
{

   //printf("translate_items %s\n", strFileSrc.c_str());

   m_psystem->m_pacmefile->ensure_exists(strFileSrc);

   string strInput = m_psystem->m_pacmefile->as_string(strFileSrc);

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

   m_psystem->m_pacmefile->set_file_normal(strFileDst);

   m_psystem->m_pacmefile->put_contents(strFileDst, strOutput);

}


void application_build_helper::defer_matter()
{

   ::file::path pathMatter = m_pathFolder / "matter.txt";

   m_psystem->m_pacmefile->ensure_exists(pathMatter);

   m_psystem->m_pacmefile->set_file_normal(pathMatter);

   string strInput = m_psystem->m_pacmefile->as_string(pathMatter);

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

   m_psystem->m_pacmefile->ensure_exists(pathMatter);

   string strInput = m_psystem->m_pacmefile->as_string(pathMatter);

   //auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   ::file::path pathOutput = m_pathFolder - 2;

#ifdef WINDOWS_DESKTOP

   _wchdir(wstring(m_pathFolder));

#else

   chdir(m_pathFolder);

#endif

   bool bFirst = true;

#ifdef WINDOWS_DESKTOP

   ::file::path pathZipExe(m_psystem->m_pacmedir->module() / "zip.exe");

   string strZipExe = "\"" + pathZipExe + "\"";

#else

   ::file::path pathZipExe("zip");

   string strZipExe = pathZipExe;

#endif

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

            if (bFirst)
            {

               int iExitCode = 0;

               auto estatus = command_system(iExitCode, strZipExe + " -FSr \"" + pathZip + "\" " + strFolder + "/*");

               bFirst = false;

            }
            else
            {

               int iExitCode = 0;

               auto estatus = command_system(iExitCode, strZipExe + " -r \"" + pathZip + "\" " + strFolder + "/*");

            }

         }

      }

   }


#ifdef WINDOWS_DESKTOP

   _wchdir(wstring("C:\\"));

#else

   {

      ::file::path pathHome = getenv("HOME");

      chdir(pathHome);

   }

#endif

   int iExitCode = 0;

   auto estatus = command_system(iExitCode, strZipExe + " -r \"" + pathZip + "\" sensitive/sensitive/api/*");

}


#if defined(FREEBSD) || defined(LINUX)


void create_matter_object(class ::system* psystem, const ::string& strFolder)
{

   ::file::path pathFolder = strFolder;

   chdir(pathFolder);

   string strRoot;

   string strItem;

   get_root_and_item(strRoot, strItem, pathFolder);

   string strAppId;

   strAppId = strRoot + "/" + strItem;

   ::file::path pathMatterZipO = pathFolder / ".link_object/_matter.zip.o";

   chdir(pathFolder);

   psystem->m_pacmedir->create(pathFolder / ".link_object");

#if defined(LINUX)

   command_system("ld -r -b binary -o " + pathMatterZipO + " _matter.zip");

#else

   command_system("ld -r -b binary -o " + pathMatterZipO + " -m elf_amd64_fbsd -z noexecstack _matter.zip");

#endif

}


#endif

void implement(class ::system* psystem)
{

   g_phelper = new application_build_helper;

   g_phelper->initialize(psystem);

   if (psystem->m_argc == 3)
   {

#ifdef WINDOWS_DESKTOP

      string strArg2 = psystem->m_wargv[1];

      string strArg3 = psystem->m_wargv[2];

#else

      string strArg2 = psystem->m_argv[1];

      string strArg3 = psystem->m_argv[3];

#endif

      if (strArg2.compare_ci("-package") == 0)
      {

         g_phelper->set_package_folder(strArg3);

#ifdef WINDOWS

         g_phelper->package_windows();

#endif

      }

   }
   else if (psystem->m_argc == 2)
   {

#ifdef WINDOWS_DESKTOP

      string strFolder = psystem->m_wargv[1];

#else

      string strFolder = psystem->m_argv[1];

#endif

      g_phelper->set_package_folder(strFolder);

      auto pathFolder = g_phelper->m_pathFolder;

      printf("build_helper \"%s\"\n", pathFolder.c_str());

      printf("platform: \"%s\"\n", g_phelper->m_strPlatform2.c_str());

      g_phelper->create_package_list();

      string strPackages;

      for (auto& packagereference : g_phelper->m_packagereferencea)
      {

         strPackages += packagereference.m_strPackage.trimmed() + "\n";

      }

      ::file::path pathInl = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_static_factory.inl";

      ::file::path pathSourcePackages = pathFolder / "_packages.txt";

      ::file::path pathTargetPackages = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_packages.txt";

      psystem->m_pacmefile->put_contents(pathSourcePackages, strPackages);

      ::file::path pathSourceReferences;

      pathSourceReferences = pathFolder / "_references.txt";

      ::file::path pathTargetReferences;

      pathTargetReferences = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_references.txt";

      ::file::path pathDepsDeprecated;

      pathDepsDeprecated = pathFolder / "deps.txt";

      ::file::path pathSourceDependencies;

      pathSourceDependencies = pathFolder / "_dependencies.txt";

      ::file::path pathTargetDependencies;

      pathTargetDependencies = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_dependencies.txt";

      ::file::path pathSourceExtensions;

      pathSourceExtensions = pathFolder / "_extensions.txt";

      ::file::path pathTargetExtensions;

      pathTargetExtensions = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_extensions.txt";

      psystem->m_pacmefile->set_file_normal(pathTargetReferences);

      psystem->m_pacmefile->set_file_normal(pathTargetDependencies);

      psystem->m_pacmefile->set_file_normal(pathTargetExtensions);

      psystem->m_pacmefile->set_file_normal(pathTargetPackages);

      auto lenDepsDeprecated = psystem->m_pacmefile->as_string(pathDepsDeprecated).trimmed().length();

      auto lenSourceDependencies = psystem->m_pacmefile->as_string(pathSourceDependencies).trimmed().length();

      if (lenDepsDeprecated > 0 && lenSourceDependencies == 0)
      {

         psystem->m_pacmefile->set_file_normal(pathSourceDependencies);

         psystem->m_pacmefile->copy(pathSourceDependencies, pathDepsDeprecated, true);

      }

      g_phelper->generate__main();

      g_phelper->copy_icon_ico();

      g_phelper->static_factory(pathInl, pathSourceDependencies);

      g_phelper->translate_items(pathTargetReferences, pathSourceReferences);
      g_phelper->translate_items(pathTargetDependencies, pathSourceDependencies);
      g_phelper->translate_items(pathTargetExtensions, pathSourceExtensions);
      //g_phelper->translate_items(pathTargetPackages, pathSourcePackages);

      g_phelper->translate_package_list();

      string strTranslatedPackages;

      for (auto& packagereference : g_phelper->m_packagereferencea)
      {

         strTranslatedPackages += packagereference.m_strPackage.trimmed() + "\n";

      }

      psystem->m_pacmefile->put_contents(pathTargetPackages, strTranslatedPackages);


      g_phelper->defer_matter();

      g_phelper->zip_matter();

#if defined(FREEBSD) || defined(LINUX)

      create_matter_object(psystem, pathFolder);

#endif


   }

   if (psystem->m_argc == 4)
   {

      string strOp = psystem->m_wargv[1];

      if (strOp == "([a-z0-9_]+)_factory")
      {

         string strFileDst = psystem->m_wargv[3];

         string strFileSrc = psystem->m_wargv[2];

         //         ::file::path pathPlatform;
         //
         //         ::file::path pathFolder = strFolder;
         //
         //         pathPlatform = (pathFolder - 2) / "platform.txt";
         //
         //         string strPlatform = psystem->m_pacmefile->as_string(pathPlatform);
         //
         //         ::file::path pathTranslate;
         //
         //         pathTranslate = (pathFolder - 2) / (strPlatform + "_deps.txt");
         //
         //         static_factory(psystem, strFileDst, strFileSrc);
         //

      }
      else if (strOp == "zip_matter")
      {

         string strFolder = psystem->m_wargv[2];

         g_phelper->set_package_folder(strFolder);

         g_phelper->zip_matter();

      }

   }

   delete g_phelper;

}



