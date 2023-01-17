﻿#include "framework.h"
#include "openssl.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "apex/platform/integration_context.h"
#include "acme/platform/node.h"


namespace console_integration
{


   openssl::openssl()
   {


   }


   openssl::~openssl()
   {

   }


   void openssl::initialize(::particle * pparticle)
   {

      ::particle::initialize(pparticle);

      acmenode()->integration_factory();

      __construct(m_pcontext);

      m_pcontext->m_strName = "openssl";

   }


   void openssl::build()
   {

      prepare();

      download();

      configure();

      compile();

      install();

   }


   void openssl::prepare()
   {

      m_pcontext->m_strRelease = "3.0.7";

      m_pcontext->m_pathDownloadURL = "https://www.openssl.org/source/openssl-" + m_pcontext->m_strRelease + ".tar.gz";

      m_pcontext->prepare_compile_and_link_environment();

      if (m_pcontext->m_strPlatform == "Win32")
      {

         if (m_pcontext->m_strConfiguration.case_insensitive_contains("Debug"))
         {

            m_strConfigure = "debug-VC-WIN32";

            m_strDebug = "--debug";

         }
         else
         {

            m_strConfigure = "VC-WIN32";

            m_strDebug = "";

         }

      }
      else if (m_pcontext->m_strPlatform == "x64")
      {

         if (m_pcontext->m_strConfiguration.case_insensitive_contains("Debug"))
         {

            m_strConfigure = "debug-VC-WIN64A";

            m_strDebug = "--debug";

         }
         else
         {

            m_strConfigure = "VC-WIN64A";

            m_strDebug = "";

         }

      }
      else
      {

         throw ::exception(error_failed, "Unsupported Platform \"" + m_pcontext->m_strPlatform + "\"?!?");

      }

      if (m_pcontext->m_strConfiguration.case_insensitive_contains("Static"))
      {

         m_strShared = "no-shared";

      }
      else
      {

         m_strShared = "shared";

      }

   }


   void openssl::download()
   {

      m_pcontext->download_and_uncompress();

   }


   //void openssl::install()
   //{

   //   m_pcontext->m_pathSourceFolder = "C:/operating-system-new/operating-system-windows";


   //   m_pcontext->m_pathStorageFolder = "C:/operating-system-new/storage-windows";






   //   //VERSION = "3.0.7"


   //   //   SRC_FOLDER = "/c/main/operating-system/operating-system-windows"


   //   //   STG_FOLDER = "/c/operating-system/storage-windows"


   //      //if[!- d $BASE_DIR]; then

   //      //   echo "$BASE_DIR does not exist!!"

   //      //   exit - 1

   //      //   fi


   //      //   cd $BASE_DIR

   //}


   void openssl::configure()
   {

      ::string strCommand;

      auto pathBase = m_pcontext->m_pathFolder;

      auto path = m_pcontext->m_path;

      auto pathBuild = pathBase / path / "build";

      auto pathProgram = pathBase / path / "program";

      strCommand =
         "perl Configure " + m_strConfigure + " " + m_strDebug + " --prefix=" + pathBuild + " --openssldir=" + pathProgram + " " + m_strShared;

      m_pcontext->command_system(strCommand);

   }


   void openssl::compile()
   {


      //PLATFORM = $1
      //   CONFIGURATION = $2
      //   NAME = $3
      //   DEBUG = $4
      //   CONFIGURE = $5
      //   SHARED = $6


         //RELATIVE = openssl / $VERSION / $PLATFORM / $CONFIGURATION


         //cd $BASE_DIR
         //mkdir - p $RELATIVE
         //cd $RELATIVE


         //echo "Downloading openssl.tar.gz to $RELATIVE ..."
         //wget - O openssl.tar.gz  https ://www.openssl.org/source/openssl-$VERSION.tar.gz
      //echo "Uncompressing openssl.tar.gz to $RELATIVE ..."
        // tar - xzf openssl.tar.gz --strip - components = 1 - C .

         ///nmake

      m_pcontext->command_system("nmake");

   }


   void openssl::install()
   {

      //BASE_DIR = $1
      //   VERSION = $2
      //   PLATFORM = $3
      //   CONFIGURATION = $4
      //   REL = $5
      //   SRC_FOLDER = $6
      //   STG_FOLDER = $7


      //RELATIVE = openssl / $VERSION / $PLATFORM / $CONFIGURATION


        // cd $BASE_DIR
         //cd $RELATIVE

      m_pcontext->command_system("nmake install_sw");

      auto pathSourceFolder = m_pcontext->m_pathSourceFolder;
      auto pathStorageFolder = m_pcontext->m_pathStorageFolder / m_pcontext->m_strPlatform / m_pcontext->m_strConfiguration;

      acmedirectory()->create(pathSourceFolder / "include");
      acmedirectory()->create(pathStorageFolder / "binary");
      acmedirectory()->create(pathStorageFolder / "library");

      //mkdir - p $SOURCE_DIR / include /
      //mkdir - p $STORAGE_DIR / binary /
      //mkdir - p $STORAGE_DIR / library /


         //cp -Rf $BASE_DIR/$NAME/build/bin/* $STORAGE_DIR/binary/
         //cp -Rf $BASE_DIR/$NAME/build/lib/* $STORAGE_DIR/library/

      auto str  = m_pcontext->prepare_path(m_pcontext->m_pathFolder / m_pcontext->m_path);

      auto strSource = m_pcontext->prepare_path(pathSourceFolder);

      auto strStorage = m_pcontext->prepare_path(pathStorageFolder);

      m_pcontext->bash("cp -Rf " + str + "/build/include/* " + strSource + "/include/");
      m_pcontext->bash("cp -Rf " + str + "/build/bin/* " + strStorage + "/binary/");
      m_pcontext->bash("cp -Rf " + str + "/build/lib/* " + strStorage + "/library/");

   }



} // namespace console_integration



