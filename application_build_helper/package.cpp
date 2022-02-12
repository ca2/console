// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
#ifdef WINDOWS
#include "apex_windows/_.h"
#endif
#include "acme/filesystem/filesystem/acme_dir.h"
#include "acme/filesystem/filesystem/acme_file.h"


void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder);


void application_build_helper::package()
{

   ::file::path pathZip;

   ::file::path pathOutput;

#ifdef WINDOWS

   pathZip = "S:/windows/" + m_strUnderscoreAppId + ".zip";

   pathOutput = (m_pathFolder - 3) / "time-windows/x64/stage";

#else

   pathZip = "/store/" + m_strSlashedOperatingSystem + "/" + m_strUnderscoreAppId + ".zip";

   pathOutput = m_pathOutput + "/output";

#endif

   ::file::path pathPackageList;

   pathPackageList = m_pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_packages.txt";

   string strInput = m_psystem->m_pacmefile->as_string(pathPackageList);

   string_array stra;

   stra.add_lines(strInput, false);

   //auto estatus = 
   
   m_psystem->m_pacmedir->change_current(pathOutput);

   //if(!estatus)
   //{

   //   fprintf(stderr, "Fatal: Current current directory to: %s (%" PRIestatus ")\n", pathOutput.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   ::file::path pathZipExe;

#ifdef WINDOWS

   pathZipExe = (m_pathFolder - 3) / "operating-system/tool-windows/bin/zip";

#else

   pathZipExe = "zip";

#endif

   bool bFirst = true;

   string strCmd = pathZipExe + " -FS \"" + pathZip + "\"";

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

                  //estatus = 
                  
                  if(!m_psystem->m_pacmefile->exists(pathItem))
                  {

                     fprintf(stderr, "Fatal: File doesn't exist: %s\n", pathItem.c_str());

                     throw ::exception(error_file_not_found);

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

               //estatus = 

               if(!m_psystem->m_pacmefile->exists(pathItem))
               {

                  fprintf(stderr, "Fatal: File doesn't exist: %s", pathItem.c_str());

                  throw ::exception(error_file_not_found);

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

   //estatus = 
   
   command_system(strOutput, strError, iExitCode, strCmd, e_command_system_inline_log);

   if (strError.trimmed().has_char())
   {

      fprintf(stderr, "%s\n", strError.c_str());

   }

   //return estatus;

}



