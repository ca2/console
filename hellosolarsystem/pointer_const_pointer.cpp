// polyglot_developer@Twitch Present : 2020-11-28 14:49 BRT 8.0


void print_const_char_pointer (const_char_pointer psz)
{

   //psz[0] = 'a';

   ::i8 * psz1 = (::i8 *)psz;

   psz1[0] = 'b';

   psz++;

   printf("%s", psz);

}

void print_char_const_pointer(::i8 * const psz)
{

   psz[0] = 'b';

   //psz++;

   printf("%s", psz);

}


void pointer_const_pointer()
{

   ::i8 sz[8];

   sz[0] = 'p';
   sz[1] = 'o';
   sz[2] = 'i';
   sz[3] = 'n';
   sz[4] = 't';
   sz[5] = '3'; 
   sz[6] = 'r'; 
   sz[7] = 0;

   //print_const_char_pointer ("string");

   print_const_char_pointer (sz);

   print_char_const_pointer(sz);

}



void print_const_char_pointer 0(const_char_pointer psz)
{

   psz++;

   printf("%s", psz);

}

void print_char_const_pointer0(::i8 * const psz)
{

   psz[0] = 'b';

   printf("%s", psz);

}


void print_const_char_const_pointer0(::i8 const * const psz)
{

   printf("%s", psz);

}


void pointer_const_pointer0()
{

   ::i8 sz[8];

   sz[0] = 'p';
   sz[1] = 'o';
   sz[2] = 'i';
   sz[3] = 'n';
   sz[4] = 't';
   sz[5] = '3';
   sz[6] = 'r';
   sz[7] = 0;

   //print_const_char_pointer ("string");

   print_const_char_pointer 0(sz);

   print_char_const_pointer0(sz);

   print_const_char_const_pointer0(sz);

}
