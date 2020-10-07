// 2020-10-06 18:04 BRT Dunno(P4ndaExpress, AndPerd) watched.


void asterisk(int* pi)
{

   *pi = 11;

   printf("ampersand %d\n", *pi);

}

void ampersand(int& i)
{

   i = 22;

   printf("ampersand %d\n", i);

}


void naked_type(int i)
{

   i = 33;

   printf("naked_type %d\n", i);

}