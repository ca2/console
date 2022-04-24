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


   string                        m_strOperatingSystem2;
   string                        m_strSlashedOperatingSystem;
   package_reference_array       m_packagereferencea;
   string_array                  m_straIgnorePackage;

   ::file::path                  m_pathBaseDir;
   ::file::path                  m_pathFolder;
   ::file::path                  m_pathOperatingSystem;
   ::file::path                  m_pathSource;
   ::file::path                  m_pathOutput;

   string                        m_strAppId;
   string                        m_strUnderscoreAppId;
   string                        m_strRoot;
   string                        m_strItem;
   __pointer(::handle::ini)      m_piniPackageMap;


   bool                          m_bTranslateDependency;


   string_map < string_to_string >  m_mapBinaryToProject;
   string_map < string_to_string >  m_mapProjectToBinary;




   application_build_helper();

   ~application_build_helper() override;


   void set_package_folder(const ::file::path& pathFolder);


   void prepare_application();

   void create_linux_matter_object();

   void create_package_list();

   void translate_package_list();

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


   void translate_items(const ::string& strFileDst, const ::string& strFileSrc);
   //void static_factory(const ::string& strFileDst, const ::string & strFileFactory, const ::string& strFileSrc);
   void static_factory(const ::string & strFileDst, const ::string & strFileSrc);
   string defer_translate_dependency(string strDependency);
   string defer_binary_to_project(string strBinary);
   string defer_project_to_binary(string strProject);


   void load_map(string_to_string & map, string strMap, string strRoot);

   string defer_translate_application_name(string strDependency);


};



