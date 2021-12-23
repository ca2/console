// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#ifdef WINDOWS
#include "apex_windows/_.h"
#endif


void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder);


::e_status application_build_helper::package()
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

   auto estatus = m_psystem->m_pacmedir->change_current(pathOutput);

   if(!estatus)
   {

      fprintf(stderr, "Fatal: Current current directory to: %s (%" PRIestatus ")\n", pathOutput.c_str(), estatus.m_estatus);

      return estatus;

   }

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

                  estatus = m_psystem->m_pacmefile->exists(pathItem);

                  if(!estatus)
                  {

                     fprintf(stderr, "Fatal: File doesn't exist: %s (%" PRIestatus ")\n", pathItem.c_str(), estatus.m_estatus);

                     return estatus;

                  }

                  //string strCommand = strZipExe + " -FS \"" + pathZip + "\" \"" + strName + "\"";

                  strCmd += " \"" + strName + "\"";

                  //int iExitCode = 0;

                  //auto estatus = command_system(iExitCode, strCommand);

               }

               bFirst = false;

            }

            if(strItem.compare_ci("none") != 0)
            {

#ifdef WINDOWS

               string strName = strItem + ".dll";

#else

               string strName = "lib" + strItem + ".so";

#endif

               ::file::path pathItem = pathOutput / strName;

               estatus = m_psystem->m_pacmefile->exists(pathItem);

               if(!estatus)
               {

                  fprintf(stderr, "Fatal: File doesn't exist: %s (%" PRIestatus ")", pathItem.c_str(), estatus.m_estatus);

                  return estatus;

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

   estatus = command_system(strOutput, strError, iExitCode, strCmd, e_command_system_inline_log);

   if (!estatus || strError.trimmed().has_char())
   {

      fprintf(stderr, "%s %" PRIestatus "\n", strError.c_str(), estatus.m_estatus);

   }

   return estatus;

}


