// Created by camilo on 203-06-08 22:50 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "application.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/primitive/primitive/memory.h"


namespace console_hello
{


   void application::search_special_characters()
   {

      ::file::listing listing;

      auto pathFolder = acmedirectory()->get_current();

      listing.set_pattern_file_listing(pathFolder, {"*.h", "*.cpp", "*.c", "*.hpp" }, e_depth_recursively);
      ::file::path_array patha;
      ::string strReports;

      listing.m_functionOnNewPath = [this,&patha,&strReports](auto & path)
         {
            auto lines = acmefile()->lines(path);

            for(int iLine = 1; iLine <= lines.size(); iLine++)
            {

               auto & line = lines[iLine - 1];

               for (int iCharacter = 1; iCharacter <= line.size(); iCharacter++)
               {

                  auto & character = line[iCharacter - 1];

                  if (character & 0x80)
                  {

                     string strReport;

                     strReport.format("%s(%d,%d): %s\r\n",path.c_str(), iLine, iCharacter, line.substr(iCharacter - 1, line.length() - iCharacter + 1).c_str());

                     printf("%s", strReport.c_str());

                     output_debug_string(strReport);

                     strReports += strReport;

                     break;

                  }

               }

            }



};

      acmedirectory()->enumerate(listing);

      auto pathFileWithBoms = pathFolder / "file_with_boms.txt";


      //for (auto & path : listing)
      //{

      //   if (path.case_insensitive_ends("/thumbnail_dc.cpp"))
      //   {


      //   }

      //   //char szBomCandidate;

      //   //pfile->read(szBomCandidate, 3);

      //   //if (szBomCandidate[0] == '0xEF'
      //   //   && szBomCandidate[1] == '0xBB'
      //   //   && szBomCandidate[1] == '0xBF')
      //   //{


      //   //}

      //}

      acmefile()->put_lines(pathFileWithBoms, strReports);

   }


} // namespace console_hello



