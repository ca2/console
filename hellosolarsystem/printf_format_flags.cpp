// P4ndaExpress (A.P.)
// : i see in your print debug functions
// you have stuff like %d. what does %d mean and what kinds exist?
// Present on 2020-11-08 11:25BRT


void printf_format_flags()
{

   int i = 'a';
   int * pi = &i;
   float f = 23.130456734f;
   const char * psz = "This is a string";

   printf("=======================================\n");
   printf("|\n");
   printf("|   printf format_flags\n");
   printf("|\n");
   printf("|   %%d %d\n", i);
   printf("|   %%x %x\n", i);
   printf("|   %%X %X\n", i);
   printf("|   %%04d %04d\n", i);
   printf("|   %%8x %8x\n", i);
   printf("|   %%08X %08X\n", i);
   printf("|   %%X %c\n", i);
   printf("|   %%016" PRIdPTR " %016" PRIdPTR "\n", (uptr)&i);
   printf("|   %%f %f\n", f);
   printf("|   %%04.2f %04.2f\n", f);
   printf("|   %%s %s\n", psz);
   printf("|\n");
   printf("=============================================================\n");
   printf("\n");
   printf("\n");
   printf("\n");

}
