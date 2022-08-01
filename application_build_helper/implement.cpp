// From application_build_helper to implement.cpp by camilo on 2021-12-17 21:04 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
#define FACTORY console_application_build_helper
#define __APP_ID "console/application_build_helper"
#ifdef CUBE
#include "_static_factory.inl"
#endif
//#include "_factory.h"
#include "_main.inl"
//#include "acme/console.h"
#include "acme/filesystem/file/_constant.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#ifdef WINDOWS_DESTKOP
#include <direct.h>
#endif
#include "application_build_helper.h"

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

   //auto estatus = 
   //m_psystem->m_pacmefile->set_file_normal(pathIconTarget);

   //if(!estatus)
   //{

   //   return estatus;

   //}

   //estatus = 

   if (!m_psystem->m_pacmefile->exists(pathIconSource))
   {

       string strMessage;

       strMessage.format("The icon file is missing: \"%s\".\n", pathIconSource.c_str());

       fprintf(stderr, "%s", strMessage.c_str());

       throw ::exception(error_not_found, strMessage);

   }
   
   m_psystem->m_pacmefile->overwrite_if_different(pathIconTarget, pathIconSource);

   //if(!estatus)
   //{

   //   string strStatus = estatus_to_string(estatus);

   //   fprintf(stderr, "error: copy_icon_ico overwrite_if_different \"%s\" \"%s\" (%s)", pathIconTarget.c_str(), pathIconSource.c_str(), strStatus.c_str());

   //   return estatus;

   //}

   //return estatus;

}


void application_build_helper::generate__main()
{

   //::e_status estatus = ::success;

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

   ::file::path pathApplicationMatter = m_pathSource / strDependency / "application_matter.txt";

   auto estatus =m_psystem->m_pacmefile->exists(pathApplicationMatter);

   if(estatus)
   {

      string strPath = pathApplicationMatter;

      strPath.ends_eat_ci("application_matter.txt");

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

   //estatus = m_psystem->m_pacmedirectory->change_current(pathOutput);

   //if(!estatus)
   //{

   //   return estatus;

   //}

//#ifdef WINDOWS_DESKTOP
//
//   _wchdir(wstring(pathOutput));
//
//#else
//
//   chdir(pathOutput);
//
//#endif

   bool bFirst = true;

//#ifdef WINDOWS_DESKTOP
//
//   ::file::path pathZipExe(m_psystem->m_pacmedirectory->module() / "zip.exe");
//
//   string strZipExe = "\"" + pathZipExe + "\"";
//
//#else

   //{

   //   string strOutput;

   //   string strError;

   //   int iExitCode = 0;

   //   auto estatus = command_system(strOutput, strError, iExitCode, "where zip");

   //}

   ::file::path pathZipExe;

#ifdef WINDOWS

   pathZipExe = (m_pathFolder - 3) / "operating-system/tool-windows/bin/zip";

#else

   pathZipExe = "zip";

#endif

   string strZipExe = pathZipExe;

   // strZipExe.replace("\\", "\\\\");

//#endif

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

               string strOutput;

               string strError;

               int iExitCode = 0;

               command_system(strOutput, strError, iExitCode, strZipExe + " -FSr \"" + strZip + "\" " + strFolder + "/*", e_command_system_inline_log);

               bFirst = false;

            }
            else
            {

               string strOutput;

               string strError;

               int iExitCode = 0;

               command_system(strOutput, strError, iExitCode, strZipExe + " -r \"" + pathZip + "\" " + strFolder + "/*", e_command_system_inline_log);

            }

            //if(estatus == error_file_not_found)
            //{
            //   
            //   

            //   fprintf(stderr, "Compressing failed: Is \"%s\" installed?\n", strZipExe.c_str());

            //   return estatus;

            //}

         }

      }

   }


#ifdef WINDOWS_DESKTOP

   _wchdir(wstring("C:\\"));

#else

   {

      ::file::path pathHome = getenv("HOME");

      //estatus =
      //
      m_psystem->m_pacmedirectory->change_current(pathHome);

//      if (!estatus)
//      {
//
//         return estatus;
//
//      }

   }

#endif

   {

   string strOutput;

   string strError;

   int iExitCode = 0;

   command_system(strOutput, strError, iExitCode, strZipExe + " -r \"" + pathZip + "\" sensitive/sensitive/api/*", e_command_system_inline_log);
      
      
   }

}



//#if defined(FREEBSD) || defined(LINUX)


void application_build_helper::create_linux_matter_object()
{

   //::file::path pathFolder = strFolder;

   //chdir(m_pathFolder);

   //string strRoot;

   //string strItem;

   //get_root_and_item(strRoot, strItem, pathFolder);

   //string strAppId;

   //strAppId = strRoot + "/" + strItem;

   ::file::path pathMatterZipO = m_pathFolder / ".link_object/_matter.zip.o";

   //auto estatus =

      m_psystem->m_pacmedirectory->change_current(m_pathFolder);

//   if(!estatus)
//   {
//
//      return estatus;
//
//   }

   //estatus =

      m_psystem->m_pacmedirectory->create(m_pathFolder / ".link_object");

//   if(!estatus)
//   {
//
//      return estatus;
//
//   }

   string strOutput;

   string strError;

   int iExitCode = 0;

#if defined(FREEBSD)

   command_system(strOutput, strError, iExitCode, "ld -r -b binary -o " + pathMatterZipO + " -m elf_amd64_fbsd -z noexecstack _matter.zip", e_command_system_inline_log);

#else

   //estatus =
   //

   string strCommand = "ld -r -b binary -o " + pathMatterZipO + " _matter.zip";

   command_system(strOutput, strError, iExitCode, strCommand, e_command_system_inline_log);

   if (iExitCode != 0)
   {

      fprintf(stderr, "Command failed: %s\n%s", strCommand.c_str(), strError.c_str());

   }

#endif

//   if(!estatus)
//   {
//
//      return estatus;
//
//   }
//
//   return estatus;

}


//#endif


void implement(class ::system* psystem)
{

   //::Sleep(30'000);

   //::e_status estatus = ::success;

   application_build_helper helper;

   //estatus = 
   
   helper.initialize(psystem);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: implement: helper.initialize %" PRIestatus, estatus.m_estatus);

   //   psystem->m_estatus = estatus;

   //   return;

   //}

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

         //if(estatus)
         //{

            helper.m_pathOutput = strArgument3;

            //estatus = helper.package();

            helper.package();

         //}

      }
      else if (strArgument1.compare_ci("-prepare_project") == 0)
      {

         printf("application_build_helper -prepare_project %s\n", strArgument2.c_str());

         helper.set_package_folder(strArgument2);

         helper.prepare_project();

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

         //estatus = 
         
         helper.set_package_folder(strArgument2);

         //if(estatus)
         //{

            helper.m_pathOutput = strArgument3;

            //estatus = 
            
            helper.package();

         //}

      }
      else if (strArgument1.compare_ci("node_factory") == 0)
      {

         string strFileSrc = strArgument2;

         string strFileDst = strArgument3;

         //         ::file::path pathOperatingSystem;
         //
         //         ::file::path pathFolder = strFolder;
         //
         //         pathOperatingSystem = (pathFolder - 2) / "operating-system.txt";
         //
         //         string strOperatingSystem = psystem->m_pacmefile->as_string(pathOperatingSystem);
         //
         //         ::file::path pathTranslate;
         //
         //         pathTranslate = (pathFolder - 2) / (strOperatingSystem + "_deps.txt");
         //
         //         static_factory(psystem, strFileDst, strFileSrc);
         //

      }
      else if(strArgument1.compare_ci("zip_matter") == 0)
      {

         string strFolder = strArgument2;

         //estatus = 
         helper.set_package_folder(strFolder);

         //if(estatus)
         {

            //estatus =
            
            helper.zip_matter();

         }

      }

   }
   else if (psystem->get_argument_count1() == 1 || psystem->get_argument_count1() == 2)
   {

      //estatus = 
      helper.prepare_application();

   }

   //psystem->m_estatus = estatus;


}


void application_build_helper::prepare_application()
{

   string strFolder = m_psystem->get_argument1(0);


   string strProjectName = m_psystem->get_argument1(1);

   //auto estatus =
   set_package_folder(strFolder);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application set_package_folder (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   auto pathFolder = m_pathFolder;

   ::file::path pathApplicationMatter;

   pathApplicationMatter = pathFolder / "application_matter.txt";

   if (!m_psystem->m_pacmefile->exists(pathApplicationMatter))
   {

       return;

   }

   if (strProjectName.has_char())
   {

       if (strProjectName.begins_ci("shared_") || strProjectName.begins_ci("static_"))
       {

           return;

       }

   }


   printf("build_helper \"%s\"\n", pathFolder.c_str());

   printf("operating system: \"%s\"\n", m_strOperatingSystem2.c_str());

   //estatus = 
   
   create_package_list();

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application create_package_list \"%s\" (%" PRIestatus ")", m_pathFolder.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   string strPackages;

   for (auto & packagereference: m_packagereferencea)
   {

      strPackages += packagereference.m_strPackage.trimmed() + "\n";

   }

   ::file::path pathInl = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_static_factory.inl";

   //::file::path pathFactory = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_factory.h";

   ::file::path pathSourcePackages = pathFolder / "_packages.txt";

   ::file::path pathTargetPackages = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_packages.txt";

   //estatus = 
   
   m_psystem->m_pacmefile->put_contents(pathSourcePackages, strPackages);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application put_contents (1) \"%s\" (%" PRIestatus ")", pathSourcePackages.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   ::file::path pathSourceReferences;

   pathSourceReferences = pathFolder / "_references.txt";

   ::file::path pathTargetReferences;

   pathTargetReferences = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_references.txt";

   ::file::path pathDepsDeprecated;

   pathDepsDeprecated = pathFolder / "deps.txt";

   ::file::path pathSourceDependencies;

   pathSourceDependencies = pathFolder / "_dependencies.txt";

   ::file::path pathTargetDependencies;

   pathTargetDependencies = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_dependencies.txt";

   ::file::path pathSourceExtensions;

   pathSourceExtensions = pathFolder / "_extensions.txt";

   ::file::path pathTargetExtensions;

   pathTargetExtensions = pathFolder / "operating-system" / m_strSlashedOperatingSystem / "_extensions.txt";

   //if (m_psystem->m_pacmefile->exists(pathTargetReferences))
   //{

   //   m_psystem->m_pacmefile->set_file_normal(pathTargetReferences);

   //}

   /*if(!estatus)
   {

      fprintf(stderr, "error: application_build_helper::prepare_application set_file_normal (1) \"%s\" (%" PRIestatus ")", pathTargetReferences.c_str(), estatus.m_estatus);

      return estatus;

   }*/

   //estatus =
   
   //m_psystem->m_pacmefile->set_file_normal(pathTargetDependencies);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application set_file_normal (2) \"%s\" (%" PRIestatus ")", pathTargetDependencies.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus =
   
   //m_psystem->m_pacmefile->set_file_normal(pathTargetExtensions);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application set_file_normal (3) \"%s\" (%" PRIestatus ")", pathTargetExtensions.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus =
   
   //m_psystem->m_pacmefile->set_file_normal(pathTargetPackages);

   /*if(!estatus)
   {

      fprintf(stderr, "error: application_build_helper::prepare_application set_file_normal (4) \"%s\" (%" PRIestatus ")", pathTargetPackages.c_str(), estatus.m_estatus);

      return estatus;

   }*/

   auto lenDepsDeprecated = m_psystem->m_pacmefile->as_string(pathDepsDeprecated).trimmed().length();

   auto lenSourceDependencies = m_psystem->m_pacmefile->as_string(pathSourceDependencies).trimmed().length();

   if (lenDepsDeprecated > 0 && lenSourceDependencies == 0)
   {

      //estatus = 
      
      m_psystem->m_pacmefile->set_file_normal(pathSourceDependencies);

      //if(!estatus)
      //{

      //   fprintf(stderr, "error: application_build_helper::prepare_application set_file_normal (5) \"%s\" (%" PRIestatus ")", pathSourceDependencies.c_str(), estatus.m_estatus);

      //   return estatus;

      //}

      //estatus = 
      
      m_psystem->m_pacmefile->copy(pathSourceDependencies, pathDepsDeprecated, true);

      //if(!estatus)
      //{

      //   fprintf(stderr, "error: application_build_helper::prepare_application copy \"%s\" \"%s\" (%" PRIestatus ")", pathSourceDependencies.c_str(), pathDepsDeprecated.c_str(), estatus.m_estatus);

      //   return estatus;

      //}

   }

   //estatus = 
   
   generate__main();


   //generate_deployment_rc();



   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application generate__main (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   copy_icon_ico();

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application copy_icon_ico (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   //static_factory(pathInl, pathFactory, pathSourceDependencies);

   static_factory(pathInl, pathSourceDependencies);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application static_factory \"%s\" \"%s\" (%" PRIestatus ")", pathInl.c_str(), pathSourceDependencies.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   translate_items(pathTargetReferences, pathSourceReferences);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application translate_items (1) \"%s\" \"%s\" (%" PRIestatus ")", pathTargetReferences.c_str(), pathSourceReferences.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   translate_items(pathTargetDependencies, pathSourceDependencies);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application translate_items (2) \"%s\" \"%s\" (%" PRIestatus ")", pathTargetDependencies.c_str(), pathSourceDependencies.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   translate_items(pathTargetExtensions, pathSourceExtensions);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application translate_items (3) \"%s\" \"%s\" (%" PRIestatus ")", pathTargetExtensions.c_str(), pathSourceExtensions.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //g_phelper->translate_items(pathTargetPackages, pathSourcePackages);

   //estatus = 
   
   translate_package_list();

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application translate_package_list (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   string strTranslatedPackages;

   for (auto & packagereference: m_packagereferencea)
   {

      string strPackage = packagereference.m_strPackage.trimmed();

      string strTranslatedPackage = defer_project_to_binary(strPackage);

      strTranslatedPackages +=  strTranslatedPackage + "\n";

   }

   //estatus = 
   
   m_psystem->m_pacmefile->put_contents(pathTargetPackages, strTranslatedPackages);

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application put_contents (2) \"%s\" (%" PRIestatus ")", pathTargetPackages.c_str(), estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   defer_matter();

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application defer_matter (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   //estatus = 
   
   zip_matter();

   //if(!estatus)
   //{

   //   fprintf(stderr, "error: application_build_helper::prepare_application zip_matter (%" PRIestatus ")", estatus.m_estatus);

   //   return estatus;

   //}

   ::file::path pathZip = m_pathFolder / "_matter.zip";

   if(!m_psystem->m_pacmefile->exists(pathZip))
   {

      fprintf(stderr, "\"%s\" wasn't created.", pathZip.c_str());

      throw ::exception(error_failed);

   }

   int iCreateLinuxMatterObject = string(getenv("DISTRO")) == "raspbian";

#if defined(FREEBSD) || defined(LINUX)
   iCreateLinuxMatterObject = 1;
#endif

   if (iCreateLinuxMatterObject)
   {

      //create_matter_object(psystem, pathFolder);

      //estatus =
      //
      create_linux_matter_object();

   }

//#endif

//   if(!estatus)
//   {
//
//      fprintf(stderr, "error: application_build_helper::prepare_application create_matter_object (%" PRIestatus ")", estatus.m_estatus);
//
//      return estatus;
//
//   }

//#endif


   //return estatus;

}
