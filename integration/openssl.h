﻿// From impact.h on 2023-01-15 19:26 <3ThomasBorregaardSørensen!!
#pragma once


namespace integration { class context; }


namespace console_integration
{


   class openssl :
      virtual public ::particle
   {
   public:


      ::pointer < ::integration::context > m_pcontext;


      ::string       m_strConfigure;
      ::string       m_strDebug;
      ::string       m_strShared;


      openssl();
      ~openssl() override;


      void initialize(::particle * pparticle);


      void build();

      void prepare();

      void download();

      void configure();

      void compile();

      void install();


   };


} // namespace console_integration


