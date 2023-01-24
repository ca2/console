// From impact.h on 2023-01-15 09:46 <3ThomasBorregaardSørensen!!
#pragma once


namespace integration { class context; }


namespace console_integration
{

   class x264;

   class ffmpeg :
      virtual public ::particle
   {
   public:
      
      
      
      string m_strArch;
      string m_strDebug;
      string m_strShared;
      string m_strStatic;


      ::pointer < ::integration::context > m_pcontext;

      //::pointer < x264 > m_px264;

      ::string_array m_strax264;



      ffmpeg();
      ~ffmpeg() override;


      void initialize(::particle * pparticle);


      void build_dependencies();

      void build();

      void clean();

      void prepare();

      void download();

      void configure();

      void compile();

      void install_lib(const ::scoped_string & scopedstr);

      void install();


   };


} // namespace console_integration



