#ifdef CUBE
#define DO_FACTORY(do) \
do(acme_windows); \
do(acme_windows_common); 
#endif
#include "acme/console.h"
#include "acme/filesystem/file/_const.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif


void get_root_and_item(string & strRoot, string & strItem, const char* pszFolder)
{

   ::file::path pathFolder = pszFolder;

   strItem = pathFolder.name();

   pathFolder.go_up();

   strRoot = pathFolder.name();

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

      ::file::path pathMain = pathFolder / "_main.inl";

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

            ::file::path pathApplication = pathFolder / ("_" + strAppName + ".cpp");

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
   string str(psz);

   wstring wstr;
   wstr = str;

#ifdef WINDOWS_DESKTOP

   STARTUPINFO info = { sizeof(info) };
   PROCESS_INFORMATION processInfo;
   if (CreateProcessW(nullptr, wstr, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &info, &processInfo))
   {
      WaitForSingleObject(processInfo.hProcess, INFINITE);
      CloseHandle(processInfo.hProcess);
      CloseHandle(processInfo.hThread);
   }
#else

   ::system(psz);

#endif
}

void static_factory(class ::system* psystem, const ::string & strFileDst, const ::string & strFileSrc)
{

   psystem->m_pacmefile->ensure_exists(strFileSrc);

   string strInput = psystem->m_pacmefile->as_string(strFileSrc);

   //auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   strOutput += "#define DO_FACTORY(do) \\\n";

   for (index i = 0; i < stra.get_count(); i++)
   {

      auto& strLine = stra[i];

      strLine.trim();

      if (strLine.has_char())
      {

         strOutput += "do(" + strLine + ");";

         if (i < stra.get_upper_bound())
         {

            strOutput += " \\";

         }

         strOutput += "\n";

      }

   }

   strOutput += "\n";

   psystem->m_pacmefile->put_contents(strFileDst, strOutput);

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

#else

   ::file::path pathZipExe("zip");

#endif

   string strZipExe = "\"" + pathZipExe + "\"";

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



void implement(class ::system * psystem)
{

   if (psystem->m_argc == 2)
   {

#ifdef WINDOWS_DESKTOP

      string strFolder = psystem->m_wargv[1];

#else

      string strFolder = psystem->m_argv[1];

#endif

      ::file::path pathFolder = strFolder;

      printf("build_helper \"%s\"", pathFolder.c_str());

      ::file::path pathDeps = pathFolder / "deps.txt";

      ::file::path pathInl = pathFolder / "_static_factory.inl";

      generate__main(psystem, pathFolder);

      static_factory(psystem, pathInl, pathFolder / "deps.txt");

      defer_matter(psystem, pathFolder);

      zip_matter(psystem, pathFolder);

   }

   if (psystem->m_argc == 4)
   {

      string strOp = psystem->m_wargv[1];

      if (strOp == "([a-z0-9_]+)_factory")
      {

         string strFileDst = psystem->m_wargv[3];

         string strFileSrc = psystem->m_wargv[2];

         static_factory(psystem, strFileDst, strFileSrc);


      }
      else if (strOp == "zip_matter")
      {

         string strFolder = psystem->m_wargv[2];

         zip_matter(psystem, strFolder);

      }

   }

}



