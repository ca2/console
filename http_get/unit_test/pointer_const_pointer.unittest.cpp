// polyglot_developer@Twitch Present : 2020-11-28 14:49 BRT 8.0


__begin(print_const_char_pointer )
{

   auto psz = "Test";

   char * psz1 = (char *)psz;

   psz1[0] = 'b';

   psz++;

   printf("%s", psz);

__end(true);

__begin(print_char_const_pointer)


   auto psz = "Test";


   psz[0] = 'b';

   //psz++;

   printf("%s", psz);

__end(true);


__begin(pointer_const_pointer)

auto psz = "Test";

   char sz[8];

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

__end(true)



__begin(print_const_char_pointer 0)



   auto psz = "Test";

   psz++;

   printf("%s", psz);

__end(true);


__begin(print_char_const_pointer0)


auto psz = "Test";


   psz[0] = 'b';

   printf("%s", psz);

__end(true)


__begin(print_const_char_const_pointer0)

auto psz = "Test";


   printf("%s", psz);

__end(true)


__begin(pointer_const_pointer0)
{

   char sz[8];

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

__end(true);
