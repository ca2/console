// From impact.h on 2023-01-23 17:27 <3ThomasBorregaardSørensen!!
#pragma once


namespace integration { class context; }


namespace console_integration
{


   class x264 :
      virtual public ::particle
   {
   public:



      string m_strPrefix;
      string m_strShared;
      string m_strStatic;


      ::pointer < ::integration::context > m_pcontext;


      x264();
      ~x264() override;


      void initialize(::particle * pparticle);


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



