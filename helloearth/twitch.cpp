// Created by camilo on 2022-10-01 03:25 <3ThomasBorregaardSorensen
#include "framework.h"
#include <iostream>
#include <stdio.h>


int twitch::show_main_menu_and_get_menu_item()
{

   flush_stdin();

   ::std::cout << "1. for run memories dota program:" << ::std::endl;
   ::std::cout << "2. korishama polymorphism programs" << ::std::endl;
   ::std::cout << "3. octaelliptical stars programs" << ::std::endl;
   ::std::cout << "4. octaelliptical stars programs with odd only line count" << ::std::endl;
   ::std::cout << "5. octaelliptical iterative fibonacci" << ::std::endl;
   ::std::cout << "other number to resume" << ::std::endl;

   int iMenuItem = -1;

   ::std::cin >> iMenuItem;

   return iMenuItem;

}


int twitch::do_menu_item_and_get_next_menu_item(int iMenuItem)
{

   int iResult = -1;

   try
   {

      switch (iMenuItem)
      {
      case 1:
         iResult = memoriesdota_file_word_count_main();
         break;
      case 2:
         iResult = korishama_polymorphism_main();
         break;
      case 3:
         iResult = octaelliptical_star_main();
         break;
      case 4:
         iResult = octaelliptical_star_main_only_odd_count_main();
         break;
      case 5:
         iResult = octaelliptical_iterative_fibonacci_main();
         break;
      };

   }
   catch (const ::exit_exception &)
   {

   }

   int iNextMenuItem = -1;  // invalid next menu item

   if (iResult == 0)
   {

      iNextMenuItem = iMenuItem; // repeat current menu item

   }

   return iNextMenuItem;

}