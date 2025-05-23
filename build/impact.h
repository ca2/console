#pragma once


namespace app_core_build
{


   class CLASS_DECL_APP_CORE_BUILD impact :
      virtual public ::app_consumer < application, ::user::impact >
   {
   public:


      string_array      m_straLine;

      ::pointer<build>       m_pbuild;


      impact();
      ~impact() override;

      void install_message_routing(::channel* pchannel) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);




      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;
#ifdef _DEBUG
      // void assert_ok() const override;
      void dump(dump_context& dumpcontext) const override;
#endif

      void _001OnDraw(::draw2d::graphics_pointer& pgraphics);


   };


} // namespace app_core_build




