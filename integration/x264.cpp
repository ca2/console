// From ffmpeg.cpp on 2023-01-23 17:26 <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "x264.h"
#include "application.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
#include "acme/primitive/datetime/datetime.h"
#include "acme/primitive/primitive/url.h"
#include "apex/networking/http/context.h"
#include "apex/platform/integration_context.h"


namespace console_integration
{


   x264::x264()
   {

   }


   x264::~x264()
   {

   }


   void x264::initialize(::particle * pparticle)
   {

      ::particle::initialize(pparticle);

      acmenode()->integration_factory();

      __construct(m_pcontext);

      m_pcontext->m_bMsys = true;

      m_pcontext->m_strName = "x264";

   }


   void x264::build()
   {

      prepare();

      clean();

      download();

      configure();

      compile();

      install();

   }


   //void download();

   //void compile();

   //void install();

   void x264::prepare()
   {

      property_set set;

      acmesystem()->url()->defer_raw_http(set);

      set["disable_common_name_cert_check"] = true;

      //::string strRelease = acmeapplication()->m_papexapplication->http().get("https://raw.githubusercontent.com/FFmpeg/FFmpeg/master/RELEASE", set);

      ::string strRelease = acmesystem()->datetime()->international().get_date_time_for_file();

      strRelease.trim();

      strRelease.case_insensitive_ends_eat(".git");

      m_pcontext->m_strRelease = strRelease;

      m_pcontext->m_pathDownloadURL = "http://git.videolan.org/git/x264.git";

      m_pcontext->prepare_compile_and_link_environment();


      if (m_pcontext->m_strConfiguration.case_insensitive_contains("Static"))
      {

         m_strShared = "--enable-shared";

         m_strStatic = "";

      }
      else
      {

         m_strShared = "";

         m_strStatic = "--enable-static";

      }


   }


   void x264::clean()
   {

      m_pcontext->clean();

   }


   void x264::download()
   {


      //RELEASE = `http_get - case_insensitive_ends_eat.git - trim https ://raw.githubusercontent.com/FFmpeg/FFmpeg/master/RELEASE`


      //auto path = m_pcontext->m_pathFolder / m_pcontext->m_path;


      //m_pcontext->m_pathDownloadURL = "https://git.x264.org/x264.git";


      //m_pcontext->git_clone();


      //acmedirectory()->create(path);


      //acmedirectory()->change_current(path);


      //m_pcontext->command_system(strCommand);


      m_pcontext->git_clone();


      //string strCommand = "git clone https ://git.x264.org/x264.git .


//         if[!- d $BASE_DIR]; then
//
//            echo "$BASE_DIR does not exist!!"
//
//            exit - 1
//
//            fi
//
//
//            cd $BASE_DIR
//
//

   }

   void x264::configure()
   {

      //PLATFORM = $1
      //   CONFIGURATION = $2


         //prepare


         //cd "$BASE_DIR"
         //mkdir - p "$PATH"
         //cd "$PATH"


         //echo "BASE_DIR is $BASE_DIR"
         //echo "PATH is $PATH"
         //echo "RELEASE is $RELEASE"
         //echo "ARCH is $ARCH"
         //echo "DEBUG is $DEBUG"
         //echo "SHARED is $SHARED"
         //echo "STATIC is $STATIC"


         //exit - 1
         //#DEBUG --enable - debug

         //#ARCH i386   x86_64

         //#for shared: --enable - shared --disable - static
         //#for static: ""              ""

//#(compile x64 Debug --enable-debug --enable-shared --disable-static -MDd???) &
//#(compile x64 Release --disable-debug --enable-shared --disable-static -MD???) &
//#(compile x64 StaticDebug --enable-debug "" "" -MTd???) &
//#(compile x64 StaticRelease --disable-debug "" "" -MT???) &



//#./configure --enable-asm --enable-yasm --arch=$ARCH --disable-ffserver --disable-avdevice --disable-swscale --disable-doc --disable-ffplay --disable-ffprobe --disable-x264 $SHARED $STATIC --disable-bzlib --disable-libopenjpeg --disable-iconv --disable-zlib --prefix=$BASE_DIR/output/$NAME --toolchain=msvc $DEBUG

      string strCommand;

      auto strPrefix = m_pcontext->prepare_path(m_pcontext->m_pathFolder / m_pcontext->m_path / "build");

      strCommand += "./configure";
      strCommand += " " + m_strShared + " " + m_strStatic;
      strCommand += " --prefix=" + m_strPrefix;

      m_pcontext->bash(strCommand);


   }



   void x264::compile()
   {

      //PLATFORM = $1
      //   CONFIGURATION = $2


         //prepare


         //cd "$BASE_DIR"
         //mkdir - p "$PATH"
         //cd "$PATH"


         //echo "BASE_DIR is $BASE_DIR"
         //echo "PATH is $PATH"
         //echo "RELEASE is $RELEASE"
         //echo "ARCH is $ARCH"
         //echo "DEBUG is $DEBUG"
         //echo "SHARED is $SHARED"
         //echo "STATIC is $STATIC"


         //exit - 1
         //#DEBUG --enable - debug

         //#ARCH i386   x86_64

         //#for shared: --enable - shared --disable - static
         //#for static: ""              ""

//#(compile x64 Debug --enable-debug --enable-shared --disable-static -MDd???) &
//#(compile x64 Release --disable-debug --enable-shared --disable-static -MD???) &
//#(compile x64 StaticDebug --enable-debug "" "" -MTd???) &
//#(compile x64 StaticRelease --disable-debug "" "" -MT???) &



//#./configure --enable-asm --enable-yasm --arch=$ARCH --disable-ffserver --disable-avdevice --disable-swscale --disable-doc --disable-ffplay --disable-ffprobe --disable-x264 $SHARED $STATIC --disable-bzlib --disable-libopenjpeg --disable-iconv --disable-zlib --prefix=$BASE_DIR/output/$NAME --toolchain=msvc $DEBUG

         //string strCommand;

         //strCommand += "./configure --enable-asm --enable-yasm --arch=" + m_strArch + " --disable-doc " + m_strShared + " " + m_strStatic;
         //strCommand += " --disable-bzlib --disable-libopenjpeg --disable-iconv --disable-zlib";
         //strCommand += " --prefix=" + (m_pcontext->m_pathFolder / m_pcontext->m_path / "build") + " --toolchain=msvc " + m_strDebug;

         //m_pcontext->bash(strCommand);

      m_pcontext->bash("make");

   }


   void x264::install_lib(const ::scoped_string & scopedstrLibrary)
   {

      //REL = $3
        // SRC_FOLDER = $4
         //STG_FOLDER = $5
         //LIBRARY_NAME = $6

         //cp - Rf $BASE_DIR / $NAME / lib$LIBRARY_NAME/*.dll $STORAGE_DIR/binary/
         //cp -Rf $BASE_DIR/$NAME/lib$LIBRARY_NAME/*.pdb $STORAGE_DIR/binary/

      auto str = m_pcontext->prepare_path(m_pcontext->m_pathFolder / m_pcontext->m_path);

      auto pathStorageFolder = m_pcontext->m_pathStorageFolder / m_pcontext->m_strPlatform / m_pcontext->m_strConfiguration;

      auto strStorage = m_pcontext->prepare_path(pathStorageFolder);

      m_pcontext->bash("cp -Rf " + str + "/lib" + scopedstrLibrary + "/*.dll " + strStorage + "/binary/");
      m_pcontext->bash("cp -Rf " + str + "/lib" + scopedstrLibrary + "/*.pdb " + strStorage + "/binary/");

   }


   void x264::install()
   {

      //m_pcontext->m_pathSourceFolder = "C:/main/operating-system/operating-system-windows";


//m_pcontext->m_pathStorageFolder = "C:/operating-system/storage-windows";



//   NAME=$2
  // REL=$3
//   SRC_FOLDER=$4
  // STG_FOLDER=$5

//   cd $BASE_DIR
//   cd $NAME

//   make install

//   SOURCE_DIR="$SRC_FOLDER"
//   STORAGE_DIR="$STG_FOLDER/$REL"

//   mkdir -p $SOURCE_DIR/include/
//   mkdir -p $STORAGE_DIR/binary/
//   mkdir -p $STORAGE_DIR/library/

      m_pcontext->bash("make install");




      auto pathSourceFolder = m_pcontext->m_pathSourceFolder;

      auto pathStorageFolder = m_pcontext->m_pathStorageFolder / m_pcontext->m_strPlatform / m_pcontext->m_strConfiguration;

      auto str = m_pcontext->prepare_path(m_pcontext->m_pathFolder / m_pcontext->m_path);

      auto strSource = m_pcontext->prepare_path(pathSourceFolder);

      auto strStorage = m_pcontext->prepare_path(pathStorageFolder);


      m_pcontext->bash("cp -Rf " + str + "/build/include/* " + strSource + "/include/");
      m_pcontext->bash("cp -Rf " + str + "/build/bin/*.exe " + strStorage + " /binary/");
      m_pcontext->bash("cp -Rf " + str + "/build/bin/*.lib " + strStorage + " /library/");
      m_pcontext->bash("cp -Rf " + str + "/build/lib/* " + strStorage + "/library/");

      install_lib("avcodec");
      install_lib("avdevice");
      install_lib("avfilter");
      install_lib("avformat");
      install_lib("avutil");
      install_lib("swresample");
      install_lib("swscale");

   }





   //}


   //void x264::handle(::topic * ptopic, ::context * pcontext)
   //{

   //   if (ptopic->m_atom == "simple_checkbox"
   //      || ptopic->m_atom == "no_client_frame")
   //   {

   //      set_need_redraw();
   //      
   //      post_redraw();

   //   }

   //   ::user::impact::handle(ptopic, pcontext);
   //}


   //::user::document * x264::get_document()
   //{

   //   return ::user::impact::get_document();

   //}


   //void x264::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   //{

   //   if (get_app()->application_properties().m_echeckNoClientFrame != ::e_check_checked)
   //   {

   //      ::rectangle_i32 rectangle = client_rectangle();

   //      for (index i = 0; i < 11; i++)
   //      {

   //         pgraphics->draw_inset_rectangle(rectangle, argb(180, 80, 80, 80));

   //         rectangle.deflate(1, 1);

   //      }

   //   }

   //   //m_prender->_001OnDraw(pgraphics);

   //}


   //void x264::on_layout(::draw2d::graphics_pointer & pgraphics)
   //{

   //   auto rectangleClient = client_rectangle();

   //   if(rectangleClient.is_empty())
   //   {

   //      return;

   //   }

   //   //m_prender->m_rectangle = rectangleClient;

   //}


} // namespace console_integration



