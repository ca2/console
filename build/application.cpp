#include "framework.h"


#define TEST_DATA_LOCAL 1

void hellomultiverse_debugging();

namespace app_core_build
{

   __IMPLEMENT_APPLICATION_RELEASE_TIME();
IMPLEMENT_APPLICATION_FACTORY();


   application::application()
   {

      m_bInterprocessCommunication = true;

      m_ptemplateHelloMultiverseMain = nullptr;
      m_ptemplateHelloMultiverseImpact = nullptr;

      m_strAppId = "app-core/build";
      m_strAppName = "app-core/build";
      m_strBaseSupportId = "app-core/build";
      m_bLicense = false;

      m_etype = type_normal;

      m_strHelloMultiverseDefault = "Hello Multiverse!!";
      m_strAlternateHelloMultiverseDefault = "Hello!!";

      m_strHelloMultiverse = m_strHelloMultiverseDefault;
      m_strAlternateHelloMultiverse = m_strAlternateHelloMultiverseDefault;

      m_bMultiverseChat = true;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {


#if defined(LINUX)

      factory()->add_factory_item < linux_build, build >();

#else

      #error "not implemented"

#endif

      if (is_true("hellomultiverse_debugging"))
      {

         hellomultiverse_debugging();

      }

      set_local_data();

      

      auto puser = user();

      puser->will_use_impact_hint(FONTSEL_IMPACT);

      factory()->add_factory_item <::app_core_build::document >();
      factory()->add_factory_item <::app_core_build::frame >();
      factory()->add_factory_item <::app_core_build::main_frame >();
      factory()->add_factory_item <::user::button_impact >();
      factory()->add_factory_item <::app_core_build::impact >();
      factory()->add_factory_item <::app_core_build::main_impact >();
      factory()->add_factory_item <::app_core_build::pane_impact >();

      if (!::core::application::init_instance())
      {

         return false;

      }

      string str = payload("hellomultiverse");

      if (str.has_character())
      {

         m_strHelloMultiverse = str;

      }

      auto ptemplate = __initialize_new ::user::single_document_template(
                            "main",
                            typeid(simple_pane_document ),
                            typeid(main_frame ),
                            typeid(pane_impact )));

      m_ptemplateHelloMultiverseMain = ptemplate;

      add_document_template(ptemplate);

      ptemplate = __initialize_new ::user::single_document_template(
                       "main",
                       typeid(document),
                       typeid(frame),
                       typeid(main_impact )));

      m_ptemplateHelloMultiverseImpact = ptemplate;

      add_document_template(ptemplate);

      return true;

   }


   void application::term_application()
   {

      ::core::application::term_application();

   }


   void application::on_request(::request * prequest)
   {


#if 0

#ifdef _DEBUG

      informationf("_DEBUG build? (basis)");

      ASSERT(false);

#else

      informationf("RELEASE build? (stage)");

      ASSERT(false);

#endif

#endif

      m_bMultiverseChat = !is_true("no_hello_edit");

      if (m_ptemplateHelloMultiverseMain->get_document_count() == 0)
      {

         if (pcreate->m_payloadFile.is_empty())
         {

            ::file::path path;

            datastream()->get("last_opened_file", path);

            if (!file()->exists(path))
            {

               path = directory()->document2() / "default.hellomultiverse";

            }

            pcreate->m_payloadFile = path;

            pcreate->m_ecommand = ::command_line::command_file_open;

         }

         m_ptemplateHelloMultiverseMain->do_request(pcreate);

         return;

      }

      if (pcreate->has_file())
      {

         m_ptemplateHelloMultiverseImpact->do_request(pcreate);

      }

      informationf("----> finished hellomultiverse::on_request");

   }


   ::e_status application::set_finish()
   {

      return ::thread::set_finish();

   }


   string application::preferred_experience()
   {

      string strExperience = payload("experience");

      if (strExperience.has_character())
      {

         return strExperience;

      }

      return "core";

   }


   //long long application::increment_reference_count()
   //{

   //   return ::object::increment_reference_count();

   //}

   //long long application::decrement_reference_count()
   //{

   //   return ::object::decrement_reference_count();

   //}


} // namespace app_core_build



void hellomultiverse_debugging()
{

   const_char_pointer pszFree;

   {

      string strOh = "Oh!! Life!!";

      pszFree = strOh;

      string strXX;

      strXX = strOh + "123" + as_string(15.59) + "%";

      information(strXX);

   }

   information(scopedstrFree);

}




