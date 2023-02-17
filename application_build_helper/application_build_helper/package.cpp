// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "application_build_helper.h"
////#include "acme/exception/exception.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/operating_system/process.h"
#include "acme/platform/node.h"


void get_root_and_item(string& strRoot, string& strItem, const char* pszFolder);


namespace application_build_helper
{


   void application_build_helper::package()
   {

      ::file::path pathZip;

      ::file::path pathOutput;

#ifdef WINDOWS

      pathZip = "S:/windows/" + m_strUnderscoreAppId + ".zip";

      pathOutput = "C:/release/time-windows/x64/Release";

#else

      pathZip = "/store/" + m_strSlashedOperatingSystem + "/" + m_strUnderscoreAppId + ".zip";

      pathOutput = m_pathOutput + "/cmake-build-stage/output";

#endif

      ::file::path pathPackageList;

      pathPackageList = m_pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_packages.txt";

      string strInput = acmefile()->as_string(pathPackageList);

      string_array stra;

      stra.add_lines(strInput, false);

      acmedirectory()->change_current(pathOutput);

      ::file::path pathZipExe;

#ifdef WINDOWS

      pathZipExe = "C:/operating-system/tool-windows/bin/zip";

#else

      pathZipExe = "zip";

#endif

      bool bFirst = true;

      string strCmd = pathZipExe + " -FS \"" + pathZip + "\"";

      for (auto & strLine : stra)
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

                     if (!acmefile()->exists(pathItem))
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

               if (strItem.case_insensitive_order("none") != 0)
               {

#ifdef WINDOWS

                  string strName = strItem + ".dll";

#else

                  string strName = "lib" + strItem + ".so";

#endif

                  ::file::path pathItem = pathOutput / strName;

                  if (!acmefile()->exists(pathItem))
                  {

                     fprintf(stderr, "Fatal: File doesn't exist: %s", pathItem.c_str());

                     throw ::exception(error_file_not_found);

                  }

                  strCmd += " \"" + strName + "\"";

               }

            }

         }

      }

      printf("%s", strCmd.c_str());

      int iExitCode = 0;

      string_array straOutput;

      acmenode()->command_system(straOutput, iExitCode, strCmd, e_command_system_inline_log);

      string strOutput = straOutput.implode("\n");

      if (strOutput.has_char())
      {

         fprintf(stderr, "%s\n", strOutput.c_str());

      }

   }


} // namespace application_build_helper



