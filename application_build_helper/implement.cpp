// From application_build_helper to implement.cpp by camilo on 2021-12-17 21:04 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#define FACTORY console_application_build_helper
#define __APP_ID "console/application_build_helper"
#ifdef CUBE
#include "_static_factory.inl"
#endif
//#include "_factory.h"
#define NO_NETWORKING
#include "_main.inl"
//#include "acme/console.h"
#include "acme/filesystem/file/_constant.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"


void package_windows(::acme::system* psystem, const ::file::path& pathFolder);


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


void implement(::acme::system* psystem)
{

   //::Sleep(30'000);

   application_build_helper helper;

   helper.initialize(psystem);

   if (psystem->get_argument_count1() == 2 || psystem->get_argument_count1() == 3)
   {

      string strArgument1 = psystem->get_argument1(0);

      string strArgument2 = psystem->get_argument1(1);

      string strArgument3 = psystem->get_argument1(2);

      if (strArgument1.compare_ci("-package") == 0)
      {

         printf("application_build_helper -package %s\n", strArgument2.c_str());

         printf("output_dir : %s\n", strArgument3.c_str());

         helper.set_package_folder(strArgument2);

         helper.m_pathOutput = strArgument3;

         helper.package();

         return;

      }
      else if (strArgument1.compare_ci("-prepare_project") == 0)
      {

         //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

         helper.set_package_folder(strArgument2);

         helper.prepare_project();

         return;

      }
      else if (strArgument1.compare_ci("-prepare_projects") == 0)
      {

         //printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

         auto straProjects = psystem->m_pacmefile->lines(strArgument2);

         for (auto & strProject : straProjects)
         {

            printf("%s\n", strProject.c_str());

            helper.set_package_folder(strProject);

            helper.prepare_project();

         }

         return;

      }
      
   }
   
   if (psystem->get_argument_count1() == 3)
   {

      string strArgument1 = psystem->get_argument1(0);

      string strArgument2 = psystem->get_argument1(1);

      string strArgument3 = psystem->get_argument1(2);

      if (strArgument1.compare_ci("-package") == 0)
      {

         printf("application_build_helper -package %s\n", strArgument2.c_str());

         printf("output_dir : %s\n", strArgument3.c_str());

         helper.set_package_folder(strArgument2);

         helper.m_pathOutput = strArgument3;

         helper.package();

         return;

      }
      else if(strArgument1.compare_ci("zip_matter") == 0)
      {

         string strFolder = strArgument2;

         helper.set_package_folder(strFolder);

         helper.zip_matter();

         return;

      }

   }
   else if (psystem->get_argument_count1() == 1 || psystem->get_argument_count1() == 2)
   {

      helper.prepare_application();

      return;

   }


   printf("Don't know what to do\n");

}


