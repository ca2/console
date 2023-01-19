// Created by camilo on 2023-01-15 02:59 <3ThomasBorregaardSørensen!!
#pragma once


#include "apex/platform/application.h"


namespace console_integration
{


   //namespace integration
   //{


   class application :
      virtual public ::apex::application
   {
   public:


      ::file::path m_pathFolder;


      application();


      void main() override;


      //void ffmpeg()
      //{

      //   ffmpeg("Win32", "Debug");
      //   ffmpeg("Win32", "Release");
      //   ffmpeg("Win32", "StaticDebug");
      //   ffmpeg("Win32", "StaticRelease");

      //   ffmpeg("x64", "Debug");
      //   ffmpeg("x64", "Release");
      //   ffmpeg("x64", "StaticDebug");
      //   ffmpeg("x64", "StaticRelease");


      //}


      //void ffmpeg(const ::scoped_string & scopedstrPlatform, const ::scoped_string & scopedstrConfiguration)
      //{

      //   printf("Building ffmpeg");

      //   ::file::path path;

      //   path = "ffmpeg" / strVersion / scopedstrPlatform / scopedstrConfiguration;

      //   ::file::path pathPrefix = m_pathFolder / path / "build"

      //      string strCommand;

      //   strCommand =
      //      "configure --enable-asm --enable-yasm --arch=" + strArch +
      //      " --disable-doc " + strShared + strStatic +
      //      " --disable-bzlib --disable-libopenjpeg --disable-iconv --disable-zlib" +
      //      " --prefix=" + strBaseDir + "/" + strPath + "/build$BASE_DIR / $PATH / build --toolchain = msvc $DEBUG


      //}

      //void openssl()
      //{

      //   printf("Building openssl");


      //}


   };


   //} // namespace integration


} // namespace console_integration



