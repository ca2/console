#include "framework.h"
#include "ffmpeg.h"
#include "openssl.h"
#include "x264.h"
#include "acme/console.h"
#include <stdio.h>
#include "acme/platform/system.h"
#include "acme/primitive/primitive/url.h"
#include "apex/platform/integration_context.h"
#include "apex/networking/http/context.h"


namespace console_integration
{


   class application :
      virtual public ::apex::application
   {
   public:


      ::file::path m_pathFolder;


      application()
      {

         m_bNetworking = true;

         m_bCrypto = false;

         m_bResource = false;

         m_strAppId = "console/integration";

         m_pathFolder = "C:\\";


      }
      
      
      //int __implement()
//{
//
//   auto papp = memory_new app_integration::application();
//
//   int iExitCode = papp->__implement();
//
//   return iExitCode;
//
//}

         //namespace console
         //{


         //   namespace integration
         //   {


         //      void application::main() override
         //      {

         //         auto psystem = acmesystem();

         //         auto psubsystem = psystem->m_psubsystem;

         //         for (int i = 0; i < psubsystem->get_argument_count1(); i++)
         //         {

         //            string strArgument = psubsystem->get_argument1(i);

         //            if (strArgument.case_insensitive_equals("ffmpeg"))
         //            {

         //               ffmpeg();

         //            }
         //            else if (strArgument.case_insensitive_equals("openssl"))
         //            {

         //               openssl();

         //            }

         //         }


         //      }


         //   } // namespace integration



         //} // namespace console



      void main() override
      {

         auto psystem = acmesystem();

         auto psubsystem = psystem->m_psubsystem;

         string strArgument = psubsystem->get_argument1(0);

         if (strArgument.case_insensitive_equals("ffmpeg"))
         {

            auto pffmpeg = __create_new < ffmpeg >();

            pffmpeg->m_pcontext->m_strPlatform = psubsystem->get_argument1(1);

            pffmpeg->m_pcontext->m_strConfiguration = psubsystem->get_argument1(2);

            pffmpeg->build();

         }
         else if (strArgument.case_insensitive_equals("openssl"))
         {

            auto popenssl = __create_new < openssl >();

            popenssl->m_pcontext->m_strPlatform = psubsystem->get_argument1(1);

            popenssl->m_pcontext->m_strConfiguration = psubsystem->get_argument1(2);

            popenssl->build();

         }
         else if (strArgument.case_insensitive_equals("x264"))
         {

            auto px264 = __create_new < x264 >();

            px264->m_pcontext->m_strPlatform = psubsystem->get_argument1(1);

            px264->m_pcontext->m_strConfiguration = psubsystem->get_argument1(2);

            px264->m_pcontext->m_pathPrefix = psubsystem->get_argument1(3);

            px264->build();

         }


      }


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

      //   string strCommand;
      //   
      //   strCommand = 
      //      "configure --enable-asm --enable-yasm --arch=" + strArch + 
      //      " --disable-doc "+ strShared + strStatic + 
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


::console_integration::application g_console_http_get_application;



