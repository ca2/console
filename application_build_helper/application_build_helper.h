// Created by camilo on 2021-12-17 21:01 BRT <3ThomasBorregaardSørensen!!
#pragma once


class package_reference
{
public:


   string            m_strPackage;
   ::file::path      m_pathReference;
   int               m_iLine;


};


using package_reference_array = ::array < package_reference >;


class application_build_helper :
   virtual public ::object
{
public:


   string                        m_strPlatform2;
   string                        m_strSlashedPlatform;
   package_reference_array       m_packagereferencea;
   string_array                  m_straIgnorePackage;

   ::file::path                  m_pathBaseDir;
   ::file::path                  m_pathFolder;
   ::file::path                  m_pathArchive;
   ::file::path                  m_pathSource;
   ::file::path                  m_pathOutput;

   string                        m_strAppId;
   string                        m_strUnderscoreAppId;
   string                        m_strRoot;
   string                        m_strItem;
   __pointer(::handle::ini)      m_piniPackageMap;


   bool                          m_bTranslateDependency;


   string_map < string_to_string >  m_renamemap;




   application_build_helper();

   ~application_build_helper() override;


   void set_package_folder(const ::file::path& pathFolder);


   ::e_status prepare_application();

#if defined(FREEBSD) || defined(LINUX)

   ::e_status create_matter_object();

#endif

   ::e_status create_package_list();

   ::e_status translate_package_list();

   ::e_status add_package(::package_reference& packagereference);
   ::e_status add_package_dependencies(const ::package_reference & packagereference);
   status < string_array > get_lines(const ::file::path& path);
   status < package_reference_array > get_package_list(const ::string& strList, const ::string& strPackage);
   status < package_reference_array > get_package_references(const ::string& strPackage);
   status < package_reference_array > get_package_dependencies(const ::string& strPackage);
   status < package_reference_array > get_package_extensions(const ::string& strPackage);
   status < package_reference_array > get_all_package_dependencies(const ::string& strPackage);


   ::e_status package();


   ::e_status copy_icon_ico();
   ::e_status generate__main();
   ::e_status defer_matter();
   ::e_status zip_matter();


   ::e_status translate_items(const ::string& strFileDst, const ::string& strFileSrc);
   ::e_status static_factory(const ::string& strFileDst, const ::string& strFileSrc);
   status < string > defer_translate_dependency(string strDependency);
   status < string > defer_rename_package(string strPackage);


   ::e_status load_rename_map(string_to_string & renamemap, string strRoot);

   status < string > defer_translate_application_name(string strDependency);


};



