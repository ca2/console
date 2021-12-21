// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#ifdef WINDOWS
#include "apex_windows/_.h"
#endif


void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder);


void application_build_helper::package()
{

   ::file::path pathZip;

   ::file::path pathOutput;

#ifdef WINDOWS

   pathZip = "B:/windows/" + m_strUnderscoreAppId + ".zip";

   pathOutput = (m_pathFolder - 3) / "time-windows/x64/stage";

#else

   pathZip = "/store/" + m_strSlashedPlatform + "/" + m_strUnderscoreAppId + ".zip";

   pathOutput = m_pathOutput + "/output";

#endif

   ::file::path pathPackageList;

   pathPackageList = m_pathFolder / "platform" / m_strSlashedPlatform / "_packages.txt";

   string strInput = m_psystem->m_pacmefile->as_string(pathPackageList);

   string_array stra;

   stra.add_lines(strInput, false);

#ifdef WINDOWS_DESKTOP

   _wchdir(wstring(pathOutput));

#else

   chdir(pathOutput);

#endif

   bool bFirst = true;

#ifdef WINDOWS

   m_psystem->m_pacmefile->delete_file(pathZip);

   string strCmd = "7za a -tzip \"" + pathZip + "\"";

#else

   string strCmd = "zip -FS \"" + pathZip + "\"";

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

            string strItem = straMatter[1];

            if (bFirst)
            {

               {

#ifdef WINDOWS

                  string strName = "shared_" + strItem + ".exe";

#else

                  string strName = "_" + strItem;

#endif

                  ::file::path pathItem = pathOutput / strName;

                  if (!m_psystem->m_pacmefile->exists(pathItem))
                  {

                     printf("Fatal: File doesn't exist: %s\n", pathItem.c_str());

                     return;

                  }

                  //string strCommand = strZipExe + " -FS \"" + pathZip + "\" \"" + strName + "\"";

                  strCmd += " \"" + strName + "\"";

                  //int iExitCode = 0;

                  //auto estatus = command_system(iExitCode, strCommand);

               }

               bFirst = false;

            }

            {

#ifdef WINDOWS

               string strName = strItem + ".dll";

#else

               string strName = "lib" + strItem + ".so";

#endif

               ::file::path pathItem = pathOutput / strName;

               if (!m_psystem->m_pacmefile->exists(pathItem))
               {

                  printf("Fatal: File doesn't exist: %s", pathItem.c_str());

                  return;

               }

               /// string strCommand = strZipExe + " \"" + pathZip + "\" \"" + strName + "\"";

               strCmd += " \"" + strName + "\"";

               //int iExitCode = 0;

               //auto estatus = command_system(iExitCode, strCommand);

            }

         }

      }

   }

   printf("%s", strCmd.c_str());

   string strOutput;

   string strError;

   int iExitCode = 0;

   auto estatus = command_system(strOutput, strError, iExitCode, strCmd);

   if (strError.trimmed().has_char())
   {

      fprintf(stderr, "%s", strError.c_str());

   }

}



