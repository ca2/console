

void do_xml_test(::platform::system * psystem)
{

   {

      string strXml;

      {

         auto pdocument = psystem->øcreate_new < xml::document >();

         pdocument->set_name("xml");

         auto proot = pdocument->root();

         proot->add_child("node1", { "attribute1", "value1", "attribute2", "value2" }, "node1 value");

         strXml = pdocument->get_xml();

      }

      printf("xml=\"%s\"\n", strXml.c_str());

   }

   {

      string strXml;

      {

         auto pdocument = psystem->øcreate_new< xml::document>();

         pdocument->set_name("xml");

         auto proot = pdocument->root();

         {

            string strAttr3Value("value3");

            string strNode2Value("node2_ _value");

            strNode2Value.replace("_", "");

            proot->add_child("node2", { "attribute3", strAttr3Value }, strNode2Value);

         }

         {

            string strAttr4Value("value4");

            string strNode3Value("node3 v_a_l_u_e");

            strNode3Value.replace("_", "");

            proot->add_child("node3", { "attribute4", strAttr4Value }, strNode3Value);

         }

         {

            proot->add_child("separator");

         }

         {

            string strAttr5Value("value5");

            string strNode4Value("n_o_d_e_4 value");

            strNode4Value.replace("_", "");

            proot->add_child("node4", { "attribute5", strAttr5Value }, strNode4Value);

         }

         string str1("value1");

         if (pdocument->rear_find("node1", { "attribute", str1 }) == nullptr)
         {

            string strAttr6Value("value6");

            string strNode5Value("_n_o_d_e_5_ _v_a_l_u_e_");

            strNode5Value.replace("_", "");

            proot->add_child("node5", { "attribute6", strAttr6Value }, strNode5Value);

         }

         string str2("Attr1Value123456789");

         if (pdocument->rear_find("test", { "attr1", str2 }) == nullptr)
         {

            string strAttr7Value("value7");

            string strNode6Value("node6 value");

            strNode6Value.replace("_", "");

            auto pnode6 = proot->add_child("node6", { "attribute7", strAttr7Value }, strNode6Value);

            pnode6->add_child("node6.1", { "attribute7.1", "value7.1" }, "node6.1");
            pnode6->add_child("node6.3", { "attribute7.3", "value7.3" }, "node6.3");
            auto pnode66 = pnode6->add_child("node6.6", { "attribute7.6", "value7.6" }, "node6.6");
            pnode66->add_child("node6.6.1", { "attribute8.1", "value8.1" }, "node6.6.1");
            pnode66->add_child("node6.6.3", { "attribute8.3", "value8.3" }, "node6.6.3");
            pnode66->add_child("node6.6.6", { "attribute8.6", "value8.6" }, "node6.6.6");
            pnode66->add_child("node6.6.9", "node6.6.9");

         }

         strXml = pdocument->get_xml();

      }

      printf("xml=\"%s\"\n", strXml.c_str());

   }

}



