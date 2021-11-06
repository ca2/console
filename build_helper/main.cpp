﻿#ifdef CUBE
#define DO_FACTORY_EXCHANGE(do) \
do(acme_windows); \
do(acme_windows_common); 
#endif
#include "acme/console.h"
#include "acme/filesystem/file/_const.h"
#include <direct.h>


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

   ::file::path pathMain = pathFolder / "_main.cpp";

   string strMain;

   string strAppId;

   strAppId = strRoot + "/" + strItem;

   string strApplicationCppNamespace(strAppId);

   strApplicationCppNamespace.replace("/", "_");

   strApplicationCppNamespace.replace("-", "_");

   strMain += "#include \"framework.h\"\n";
   strMain += "#define APPLICATION " + strApplicationCppNamespace + "\n";
   strMain += "#define __APP_ID \"" + strAppId + "\"\n";
   strMain += "#if defined(WINDOWS_DESKTOP) && defined(CUBE)\n";
   strMain += "#include \"_static_factory_exchange.inl\"\n";
   strMain += "#endif\n";
   strMain += "#include \"acme/application.h\"\n";

   psystem->m_pacmefile->put_contents(pathMain, strMain);

}


void command_system(const char* psz)
{
   string str(psz);

   wstring wstr;
   wstr = str;
   

   STARTUPINFO info = { sizeof(info) };
   PROCESS_INFORMATION processInfo;
   if (CreateProcessW(nullptr, wstr, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &info, &processInfo))
   {
      WaitForSingleObject(processInfo.hProcess, INFINITE);
      CloseHandle(processInfo.hProcess);
      CloseHandle(processInfo.hThread);
   }
}

void static_factory_exchange(class ::system* psystem, const ::string & strFileDst, const ::string & strFileSrc)
{

   psystem->m_pacmefile->ensure_exists(strFileSrc);

   string strInput = psystem->m_pacmefile->as_string(strFileSrc);

   auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   strOutput += "#define DO_FACTORY_EXCHANGE(do) \\\n";

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


void zip_matter(class ::system* psystem, const ::string& strFolder)
{

   ::file::path pathFolder = strFolder;

   ::file::path pathZip = pathFolder / "_matter.zip";

   ::file::path pathMatter = pathFolder / "matter.txt";

   psystem->m_pacmefile->ensure_exists(pathMatter);

   string strInput = psystem->m_pacmefile->as_string(pathMatter);

   auto len = strInput.length();

   string_array stra;

   stra.add_lines(strInput, false);

   string strOutput;

   pathFolder -= 2;

   _wchdir(wstring(pathFolder));

   bool bFirst = true;

   ::file::path pathZipExe(psystem->m_pacmedir->module() / "zip.exe");

   string strZipExe = "\"" + pathZipExe + "\"";

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

}



void implement(class ::system * psystem)
{

   if (psystem->m_argc == 2)
   {

      string strFolder = psystem->m_wargv[1];

      ::file::path pathFolder = strFolder;

      printf("build_helper \"%s\"", pathFolder.c_str());

      ::file::path pathDeps = pathFolder / "deps.txt";

      ::file::path pathInl = pathFolder / "_static_factory_exchange.inl";

      generate__main(psystem, pathFolder);

      static_factory_exchange(psystem, pathInl, pathFolder / "deps.txt");

      zip_matter(psystem, pathFolder);

   }

   if (psystem->m_argc == 4)
   {

      string strOp = psystem->m_wargv[1];

      if (strOp == "static_factory_exchange")
      {

         string strFileDst = psystem->m_wargv[3];

         string strFileSrc = psystem->m_wargv[2];

         static_factory_exchange(psystem, strFileDst, strFileSrc);


      }
      else if (strOp == "zip_matter")
      {

         string strFolder = psystem->m_wargv[2];

         zip_matter(psystem, strFolder);

      }

   }

}


