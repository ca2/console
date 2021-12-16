#include "framework.h"
#include "_main.inl"
//#include "acme/console.h"
#include "acme/filesystem/file/_const.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif


class application_build_helper
{
public:


   string m_strPlatform2;
   string m_strSlashedPlatform;


};


application_build_helper * g_phelper;


void get_root_and_item(string & strRoot, string & strItem, const char* pszFolder)
{

   ::file::path pathFolder = pszFolder;

   strItem = pathFolder.name();

   pathFolder.go_up();

   strRoot = pathFolder.name();

}


void copy_icon_ico(class ::system* psystem, const char* pszFolder)
{


   string strRoot;

   string strItem;

   get_root_and_item(strRoot, strItem, pszFolder);

   ::file::path pathFolder = pszFolder;

   string strAppId;

   strAppId = strRoot + "/" + strItem;

   ::file::path pathRoot = pathFolder - 1;

   ::file::path pathSource = pathRoot / "_matter" / strItem /"_std/_std/main";

   ::file::path pathIconSource = pathSource / "icon.ico";

   ::file::path pathIconTarget = pathFolder / "icon.ico";
   
   psystem->m_pacmefile->overwrite_if_different(pathIconTarget, pathIconSource);

}


void generate__main(class ::system * psystem, const char* pszFolder)
{

   string strRoot;

   string strItem;

   get_root_and_item(strRoot, strItem, pszFolder);

   ::file::path pathFolder = pszFolder;

   string strAppId;

   strAppId = strRoot + "/" + strItem;

   string strApplicationCppNamespace(strAppId);

   strApplicationCppNamespace.replace("/", "_");

   strApplicationCppNamespace.replace("-", "_");

   {

      ::file::path pathMain = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_main.inl";

      string strMain;

      strMain += "#define APPLICATION " + strApplicationCppNamespace + "\n";
      strMain += "#define __APP_ID \"" + strAppId + "\"\n";
      strMain += "#if defined(WINDOWS_DESKTOP) && defined(CUBE)\n";
      strMain += "#include \"_static_factory.inl\"\n";
      strMain += "#endif\n";
      strMain += "#include \"acme/application.h\"\n";

      psystem->m_pacmefile->put_contents(pathMain, strMain);

   } 

   {

      ::file::path pathApps = pathFolder / "_apps.txt";

      string strApps = psystem->m_pacmefile->as_string(pathApps);

      string_array straApps;

      straApps.add_lines(strApps, false);

      straApps.add("");

      for (index i = 0; i < straApps.get_count(); i++)
      {

         ::string strAppAddUp = straApps[i];

         strAppAddUp.trim();

         string strAppName = strApplicationCppNamespace;

         if (strAppAddUp.has_char())
         {

            strAppName += "_" + strAppAddUp;

         }

         {

            ::file::path pathApplication = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / ("_" + strAppName + ".cpp");

            //if (!psystem->m_pacmefile->exists(pathApplication))
            {

               string strApplication;

               strApplication += "#include \"framework.h\"\n";

               if (strAppAddUp.has_char())
               {

                  strAppAddUp.make_upper();

                  strApplication += "#define "+strAppAddUp+"\n";

               }

               strApplication += "#include \"_main.inl\"\n";

               psystem->m_pacmefile->put_contents(pathApplication, strApplication);

            }

         }

      }

   }

}


void command_system(const char* psz)
{


#ifdef WINDOWS_DESKTOP

   string str(psz);

   wstring wstr;

   wstr = str;

   ::OutputDebugStringW(wstr);

   ::OutputDebugStringW(L"\n");

   STARTUPINFO info = { sizeof(info) };
   PROCESS_INFORMATION processInfo;
   if (CreateProcessW(nullptr, wstr, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &info, &processInfo))
   {
      WaitForSingleObject(processInfo.hProcess, INFINITE);
      CloseHandle(processInfo.hProcess);
      CloseHandle(processInfo.hThread);
   }
#else

   printf("%s\n", psz);
   ::system(psz);

#endif
}


string defer_translate_dependency(string strDependency)
{

   strDependency.trim();

   strDependency.make_lower();

   if(strDependency == "default_draw2d")
   {

#ifdef WINDOWS_DESKTOP

      return "draw2d_gdiplus";

#else

      return "draw2d_cairo";

#endif

   }
   else if(strDependency == "default_node")
   {

#ifdef WINDOWS_DESKTOP

      return "node_windows";

#else

      return "node_linux";

#endif

   }
   else if(strDependency == "default_windowing")
   {

#ifdef WINDOWS_DESKTOP

      return "windowing_win32";

#else

      return "";

#endif

   }
   else if(strDependency == "default_imaging")
   {

#ifdef WINDOWS_DESKTOP

      return "imaging_wic";

#else

      return "imaging_freeimage";

#endif

   }
   else if(strDependency == "default_write_text")
   {

#ifdef WINDOWS_DESKTOP

      return "write_text_win32";

#else

      return "write_text_pango";

#endif

   }

   return strDependency;

}


void static_factory(class ::system* psystem, const ::string & strFileDst, const ::string & strTranslateFile, const ::string & strFileSrc)
{

   psystem->m_pacmefile->ensure_exists(strFileSrc);

   string strInput = psystem->m_pacmefile->as_string(strFileSrc);

   //auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   strOutput += "#define DO_FACTORY(do) \\\n";

   string strTranslate;

   for (index i = 0; i < stra.get_count(); i++)
   {

      auto& strLine = stra[i];

      strLine.trim();

      if (strLine.has_char())
      {

         string strDependency = defer_translate_dependency(strLine);

         if(strDependency.has_char())
         {

            strOutput += "do(" + strDependency + ");";

            if (i < stra.get_upper_bound())
            {

               strOutput += " \\";

            }

            strOutput += "\n";

            strTranslate += strDependency;

            strTranslate += "\n";

         }

      }

   }

   strOutput += "\n";

   psystem->m_pacmefile->put_contents(strFileDst, strOutput);

   psystem->m_pacmefile->put_contents(strTranslateFile, strTranslate);

}


void defer_matter(class ::system* psystem, const ::string& strFolder)
{

   ::file::path pathFolder = strFolder;

   ::file::path pathMatter = pathFolder / "matter.txt";

   psystem->m_pacmefile->ensure_exists(pathMatter);

   psystem->m_pacmefile->clear_read_only(pathMatter);

   string strInput = psystem->m_pacmefile->as_string(pathMatter);

   strInput.trim();

   if (strInput.has_char())
   {

      return;

   }

   string strOutput;

   strOutput += "app/main\n";

   string strRoot;

   string strItem;

   get_root_and_item(strRoot, strItem, strFolder);

   string strAppId;

   strAppId = strRoot + "/" + strItem;

   strOutput += strAppId + "\n";

   psystem->m_pacmefile->put_contents(pathMatter, strOutput);

}


void zip_matter(class ::system* psystem, const ::string& strFolder)
{

   ::file::path pathFolder = strFolder;

   ::file::path pathZip = pathFolder / "_matter.zip";

   ::file::path pathMatter = pathFolder / "matter.txt";

   psystem->m_pacmefile->ensure_exists(pathMatter);

   string strInput = psystem->m_pacmefile->as_string(pathMatter);

   //auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   pathFolder -= 2;

#ifdef WINDOWS_DESKTOP

   _wchdir(wstring(pathFolder));

#else

   chdir(pathFolder);

#endif

   bool bFirst = true;

#ifdef WINDOWS_DESKTOP

   ::file::path pathZipExe(psystem->m_pacmedir->module() / "zip.exe");
   string strZipExe = "\"" + pathZipExe + "\"";


#else

   ::file::path pathZipExe("zip");

   string strZipExe = pathZipExe;

#endif

   for (auto & strLine: stra)
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

               command_system(strZipExe + " -FSr \"" + pathZip + "\" " + strFolder + "/*");

               bFirst = false;

            }
            else
            {

               command_system(strZipExe + " -r \"" + pathZip + "\" " + strFolder + "/*");

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

   command_system(strZipExe + " -r \"" + pathZip + "\" sensitive/sensitive/api/*");

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

   command_system("ld -r -b binary -o "  + pathMatterZipO + " _matter.zip");

#else

   command_system("ld -r -b binary -o "  + pathMatterZipO + " -m elf_amd64_fbsd -z noexecstack _matter.zip");

#endif

}


#endif


void implement(class ::system * psystem)
{

   if (psystem->m_argc == 2)
   {

#ifdef WINDOWS_DESKTOP

      string strFolder = psystem->m_wargv[1];

#else

      string strFolder = psystem->m_argv[1];

#endif

      g_phelper = new application_build_helper;

      ::file::path pathFolder = strFolder;

      printf("build_helper \"%s\"\n", pathFolder.c_str());

#ifdef WINDOWS

      g_phelper->m_strPlatform = "windows";

#elif defined(LINUX)

      string strPlatform;

      strPlatform = getenv("UNDERSCORE_PLATFORM");

      string strSlashedPlatform;

      strSlashedPlatform = getenv("SLASHED_PLATFORM");

      if(strPlatform.is_empty() || strSlashedPlatform.is_empty())
      {

         printf("%s", "Did you set UNDERSCORE_PLATFORM and UNDERSCORE_PLATFORM environment variables?\n");
         printf("%s", "(They can be set \"automatically\" with patch_bashrc)\n");

         psystem->m_estatus = error_wrong_state;

         return;

      }

      g_phelper->m_strPlatform2 = strPlatform;

      g_phelper->m_strSlashedPlatform = strSlashedPlatform;

#endif


      g_phelper->m_strPlatform2.trim();

      g_phelper->m_strSlashedPlatform.trim();

      printf("platform: \"%s\"\n", g_phelper->m_strPlatform2.c_str());

      ::file::path pathDeps = pathFolder / "deps.txt";

      ::file::path pathInl = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "_static_factory.inl";

      generate__main(psystem, pathFolder);

      copy_icon_ico(psystem, pathFolder);

      ::file::path pathTranslate;

      pathTranslate = pathFolder / "platform" / g_phelper->m_strSlashedPlatform / "deps.txt";

      static_factory(psystem, pathInl, pathTranslate, pathFolder / "deps.txt");

      defer_matter(psystem, pathFolder);

      zip_matter(psystem, pathFolder);

#if defined(FREEBSD) || defined(LINUX)

      create_matter_object(psystem, pathFolder);

#endif


      delete g_phelper;
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

         zip_matter(psystem, strFolder);

      }

   }

}



