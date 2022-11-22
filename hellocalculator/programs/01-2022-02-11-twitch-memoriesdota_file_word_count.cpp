#include "framework.h"
#include <iostream>
#include <fstream>

//using namespace std;

int file_word_count(::std::ifstream & infile)
{

   int count = 0;

   ::std::string str;

   while (true)
   {

      infile >> str;

      if (!infile)
      {

         break;

      }

      count++;

   }

   return count;

}


int file_word_count(::std::string filename)
{

   ::std::ifstream infile(filename);

   if (!infile)
   {

      ::std::cout << "couldn't open file." << ::std::endl;

      return -1;

   }

   return file_word_count(infile);

}


int twitch::memoriesdota_file_word_count_main()
{


   ::std::string filename;

   ::std::cout << "Enter the name of a file (or \"quit\"): ";

   ::std::cin >> filename;

   if (filename == "quit")
   {

      return -1;

   }

   ::std::cout << "Word count of file \"" << filename << "\" is " << file_word_count(filename) << ::std::endl << ::std::endl;

   return 0;

}