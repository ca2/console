// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#include "apex_windows/_.h"


void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder);


void application_build_helper::package_windows()
{

   ::file::path pathZip;

   pathZip = "B:/windows/" + m_strUnderscoreAppId + ".zip";

   ::file::path pathPackageList;

   pathPackageList = m_pathFolder / "platform" / m_strSlashedPlatform / "_packages.txt";

   string strInput = m_psystem->m_pacmefile->as_string(pathPackageList);

   string_array stra;

   stra.add_lines(strInput, false);

   ::file::path pathOutput = (m_pathFolder - 3) / "time-windows/x64/stage";

#ifdef WINDOWS_DESKTOP

   _wchdir(wstring(pathOutput));

#else

   chdir(pathOutput);

#endif

   bool bFirst = true;

   string strCmd;

   strCmd = "7za u \"" + pathZip + "\"";

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

                  string strName = "shared_" + strItem + ".exe";

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

               string strName = strItem + ".dll";

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
   int iExitCode = 0;

   auto estatus = command_system(iExitCode, strCmd);

}



