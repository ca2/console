// From impact.cpp on 2023-01-15 09:46 <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "ffmpeg.h"
#include "x264.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
#include "acme/primitive/primitive/url.h"
#include "apex/networking/http/context.h"
#include "apex/platform/integration_context.h"


namespace console_integration
{


   ffmpeg::ffmpeg()
   {

   }


   ffmpeg::~ffmpeg()
   {

   }


   void ffmpeg::initialize(::particle * pparticle)
   {

      ::particle::initialize(pparticle);

      acmenode()->integration_factory();

      __construct(m_pcontext);

      m_pcontext->m_bMsys = true;

      m_pcontext->m_strName = "ffmpeg";

   }


   void ffmpeg::build()
   {

      prepare();

      clean();

      build_dependencies();

      download();

      configure();

      compile();

      install();

   }


   void ffmpeg::prepare()
   {

      property_set set;

      acmesystem()->url()->defer_raw_http(set);

      set["disable_common_name_cert_check"] = true;

      ::string strRelease = acmeapplication()->m_papexapplication->http().get("https://raw.githubusercontent.com/FFmpeg/FFmpeg/master/RELEASE", set);

      strRelease.trim();

      strRelease.case_insensitive_ends_eat(".git");

      m_pcontext->m_strRelease = strRelease;

      m_pcontext->m_pathDownloadURL = "https://git.ffmpeg.org/ffmpeg.git";

      m_pcontext->prepare();

      if (m_pcontext->m_strPlatform == "Win32")
      {

         m_strArch = "i386";

      }
      else if (m_pcontext->m_strPlatform == "x64")
      {

         m_strArch = "x86_64";

      }
      else
      {

         throw ::exception(error_failed, "Unsupported Platform \"" + m_pcontext->m_strPlatform + "\"?!?");

      }

      if (m_pcontext->m_strConfiguration.case_insensitive_contains("Debug"))
      {

         m_strDebug = "--enable-debug";

      }
      else
      {

         m_strDebug = "--disable-debug";

      }

      if (m_pcontext->m_strConfiguration.case_insensitive_contains("Static"))
      {

         m_strShared = "";

         m_strStatic = "";

      }
      else
      {

         m_strShared = "--enable-shared";

         m_strStatic = "--disable-static";

      }

      m_pcontext->m_pathPrefix = m_pcontext->m_pathFolder / m_pcontext->m_path / "build";

      m_pcontext->prepare_compile_and_link_environment();

   }


   void ffmpeg::build_dependencies()
   {

      int iExitCode = 0;

      ::string strParameters;

      strParameters = "x264 " + m_pcontext->m_strPlatform + " " + m_pcontext->m_strConfiguration;

      strParameters += " " + m_pcontext->m_pathPrefix;

      acmenode()->command_system(m_strax264, iExitCode, acmefile()->module() + " " + strParameters, e_command_system_inline_log);

      if (iExitCode == 0)
      {

         m_strax264.add("x264 Completed!!");

      }
      else
      {

         m_strax264.add("x264 Finished with error exit code: " + ::as_string(iExitCode) + "!");

      }


      //__construct_new(m_px264);

      //m_px264->m_pcontext->m_pathPrefix = m_pcontext->m_pathPrefix;

      //m_px264->m_pcontext->m_strPlatform = m_pcontext->m_strPlatform;

      //m_px264->m_pcontext->m_strConfiguration = m_pcontext->m_strConfiguration;

      //m_px264->build();

   }


   void ffmpeg::clean()
   {

      m_pcontext->change_to_source_directory();

      m_pcontext->clean();

   }


   void ffmpeg::download()
   {

      m_pcontext->change_to_source_directory();

      m_pcontext->git_clone();

   }


   void ffmpeg::configure()
   {

      m_pcontext->change_to_source_directory();

      string strPrefix = m_pcontext->prepare_path(m_pcontext->m_pathPrefix);

      string strCommand;

      strCommand += "./configure --enable-asm --enable-yasm --arch=" + m_strArch;
      strCommand += " --disable-doc " + m_strShared + " " + m_strStatic;
      strCommand += " --disable-bzlib --disable-libopenjpeg --disable-iconv --disable-zlib";
      strCommand += " --disable-programs";
      strCommand += " --enable-libx264 --enable-gpl";
      strCommand += " --prefix=" + strPrefix + "/ --toolchain=msvc " + m_strDebug;
      strCommand += " --extra-ldflags=-LIBPATH:" + strPrefix + "/lib/";
      strCommand += " --extra-cflags=-I" + strPrefix + "/include/";

      m_pcontext->bash(strCommand);

   }


   void ffmpeg::compile()
   {

      m_pcontext->change_to_source_directory();

      m_pcontext->bash("make");

   }


   void ffmpeg::install_lib(const ::scoped_string & scopedstrLibrary)
   {

      auto pathSource = m_pcontext->m_pathSource2;

      auto pathOperatingSystemStorageFolder = m_pcontext->m_pathOperatingSystemStorageFolder / m_pcontext->m_strPlatform / m_pcontext->m_strConfiguration;

      auto strSource = m_pcontext->prepare_path(pathSource);

      auto strStorage = m_pcontext->prepare_path(pathOperatingSystemStorageFolder);

      //m_pcontext->bash("cp -f " + strSource + "/lib" + scopedstrLibrary + "/*.dll " + strStorage + "/binary/");
      m_pcontext->bash("cp -f " + strSource + "/lib" + scopedstrLibrary + "/*.pdb " + strStorage + "/binary/");

   }


   void ffmpeg::install()
   {

      m_pcontext->change_to_source_directory();

      m_pcontext->bash("make install");

      auto pathOperatingSystemIncludeFolder = m_pcontext->m_pathOperatingSystemIncludeFolder;

      auto pathOperatingSystemStorageFolder = m_pcontext->m_pathOperatingSystemStorageFolder / m_pcontext->m_strPlatform / m_pcontext->m_strConfiguration;

      auto strPrefix = m_pcontext->prepare_path(m_pcontext->m_pathPrefix);

      auto strInclude = m_pcontext->prepare_path(pathOperatingSystemIncludeFolder);

      auto strStorage = m_pcontext->prepare_path(pathOperatingSystemStorageFolder);

      m_pcontext->bash("cp -Rf " + strPrefix + "/include/* " + strInclude + "/include/");
      m_pcontext->bash("cp -f " + strPrefix + "/bin/*.exe " + strStorage + "/binary/");
      m_pcontext->bash("cp -f " + strPrefix + "/bin/*.dll " + strStorage + "/binary/");
      m_pcontext->bash("cp -f " + strPrefix + "/bin/*.lib " + strStorage + "/library/");
      m_pcontext->bash("cp -f " + strPrefix + "/lib/* " + strStorage + "/library/");

      install_lib("avcodec");
      install_lib("avdevice");
      install_lib("avfilter");
      install_lib("avformat");
      install_lib("avutil");
      install_lib("swresample");
      install_lib("swscale");

   }


} // namespace console_integration



