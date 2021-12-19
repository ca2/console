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

   string                        m_strAppId;
   string                        m_strUnderscoreAppId;
   string                        m_strRoot;
   string                        m_strItem;
   __pointer(::handle::ini)      m_piniPackageMap;


   bool                          m_bTranslateDependency;


   //string_to_string              m_mapAppId;




   application_build_helper();

   ~application_build_helper() override;


   void set_package_folder(const ::file::path& pathFolder);

   //void load_application_list();

   void create_package_list();

   void translate_package_list();

   void add_package(::package_reference& packagereference);
   void add_package_dependencies(const ::package_reference & packagereference);
   string_array get_lines(const ::file::path& path);
   package_reference_array get_package_list(const ::string& strList, const ::string& strPackage);
   package_reference_array get_package_references(const ::string& strPackage);
   package_reference_array get_package_dependencies(const ::string& strPackage);
   package_reference_array get_package_extensions(const ::string& strPackage);
   package_reference_array get_all_package_dependencies(const ::string& strPackage);

#ifdef WINDOWS

   void package_windows();

#endif

   
   void copy_icon_ico();
   void generate__main();
   void defer_matter();
   void zip_matter();


   void translate_items(const ::string& strFileDst, const ::string& strFileSrc);
   void static_factory(const ::string& strFileDst, const ::string& strFileSrc);
   string defer_translate_dependency(string strDependency);



};







