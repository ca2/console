// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#pragma once


#include "acme/platform/application.h"
//#include "acme/filesystem/filesystem/path.h"
////#include "acme/primitive/primitive/object.h"
//#include "acme/primitive/collection/string_array.h"
#include "acme/primitive/collection/map.h"
#include "acme/primitive/collection/string_map.h"


class package_reference
{
public:


   string            m_strPackage;
   ::file::path      m_pathReference;
   int               m_iLine;


};


using package_reference_array = ::array < package_reference >;


class application_build_helper :
   virtual public ::acme::application
{
public:


   bool                          m_bSoftBuild = false;

   string                        m_strOperatingSystem2;
   string                        m_strSlashedOperatingSystem;
   package_reference_array       m_packagereferencea;
   string_array                  m_straIgnorePackage;


   string                        m_strProjectName;

   ::file::path                  m_pathBaseDir;
   ::file::path                  m_pathGroup;
   ::file::path                  m_pathFolder;
   ::file::path                  m_pathOperatingSystem;
   ::file::path                  m_pathSource;
   ::file::path                  m_pathOutput;

   string                        m_strPackageAppId;
   string                        m_strUnderscoreAppId;
   string                        m_strRoot;
   string                        m_strItem;
   ::pointer<::handle::ini>     m_piniPackageMap;

   string                        m_strBuildPlatform;
   string                        m_strBuildConfiguration;

   bool                          m_bTranslateDependency;


   string_map < string_to_string >  m_mapBinaryToProject;
   string_map < string_to_string >  m_mapProjectToBinary;




   application_build_helper();

   ~application_build_helper() override;


   //void on_request(::request* prequest) override;

   void main() override;

   virtual void application_build_helper_main();


   //virtual void on_application_build_helper_request(::request* prequest);


   void set_package_folder(const ::file::path& pathFolder);


   void prepare_application();

   void create_linux_matter_object();

   void create_package_list();

   void translate_package_list();

   void generate_documentation();
   void generate_documentation(const ::scoped_string & scopedstrSubPath);

   void add_package(::package_reference& packagereference);
   void add_package_dependencies(const ::package_reference & packagereference);
   string_array get_lines(const ::file::path& path, bool bNoExceptionIfNotFound = true);
   package_reference_array get_package_list(const ::string& strList, const ::string& strPackage);
   package_reference_array get_package_references(const ::string& strPackage);
   package_reference_array get_package_dependencies(const ::string& strPackage);
   package_reference_array get_package_extensions(const ::string& strPackage);
   package_reference_array get_all_package_dependencies(const ::string& strPackage);


   void package();


   void copy_icon_ico();
   void generate__main();
   void defer_matter();
   void zip_matter();


   void prepare_project();
   void generate_deployment_rc();


   void translate_items(const ::string& strFileDst, const ::string& strFileSrc);
   //void static_factory(const ::string& strFileDst, const ::string & strFileFactory, const ::string& strFileSrc);
   void static_factory(const ::string & strFileDst, const ::string & strFileSrc);
   string defer_translate_dependency(string strDependency);
   string defer_binary_to_project(string strBinary);
   string defer_project_to_binary(string strProject);


   void load_map(string_to_string & map, string strMap, string strRoot);

   string defer_translate_application_name(string strDependency);


};



