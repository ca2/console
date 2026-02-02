// Created by camilo on 2022-10-13 13:42 <3ThomasBorregaardSorensen!!

//__START(string)

__begin(char_natural_pointer_size)

//auto naturalpointer = natural_pointer < range < const_char_pointer >, string_meta_data < char >, string_memory_allocator >();

//auto iNaturalPointerSize = sizeof(naturalpointer);

//printf("sizeof(natural_pointer<\"char\">) = % " PRIiPTR "\n", iNaturalPointerSize);

//__end(iNaturalPointerSize == sizeof(void *));

__end(1);

__begin(char_natural_pointer_string_type_size)

//auto stringtypenaturalpointer = natural_pointer < range < const_char_pointer >, string_meta_data < char >, string_memory_allocator >();

//int iStringTypeNaturalPointerSize = sizeof(stringtypenaturalpointer);

//printf("sizeof(string_type < natural_pointer<\"char\"> >)=%" PRIiPTR "\n", iStringTypeNaturalPointerSize);


//__end(iStringTypeNaturalPointerSize == sizeof(void *));

__end(1);

//__START(xxx1)
//
//__begin(dummy_test_AAA)
//
//__end(true)
//
//__begin(dummy_test_BBB)
//
//__end(false)
//
//__START(xxx3)
//
//__begin(dummy_test_xxx3_AAA)
//
//__end(true)
//
//__begin(dummy_test_xxx3_BBB)
//
//__end(false)
//
//
//__END()
//
//__begin(dummy_test_CCC)
//
//__end(true)
//
//__begin(dummy_test_DDD)
//
//__end(true)
//
//__START(xxx4)
//
//__begin(dummy_test_xxx4_AAA)
//
//__end(true)
//
//__begin(dummy_test_xxx4_BBB)
//
//__end(false)
//
//
//__END()
//
//
//__begin(dummy_test_EEE)
//
//__end(true)
//
//__begin(dummy_test_FFF)
//
//__end(true)
//
//__END()

__begin(string)


::string str = "string should act like a pointer to c string";

printf("psz = \"%s\"\n", (const_char_pointer )str);

auto iStringClassSize = sizeof(str);

printf("sizeof(str)=%" PRIiPTR "\n", iStringClassSize);

printf("sizeof(&str)=%" PRIiPTR "\n", sizeof(&str));


__end(iStringClassSize == sizeof(void *));


//__END()

//__begin(dummy_test_1)
//
//__end(true)

__START(atom)


__begin(atom)


::atom atom = "atom should act like a pointer to c string";

printf("(const_char_pointer )atom = \"%s\"\n", (const_char_pointer )::string(atom));

auto iAtomClassSize = sizeof(atom);

printf("sizeof(atom)=%" PRIiPTR "\n", sizeof(atom));

printf("sizeof(&atom)=%" PRIiPTR "\n", sizeof(&atom));



__end(iAtomClassSize == sizeof(void *) * 2);




__begin(int_atom_assign_int)


::atom atom(1);

atom = 2;

throw todo;
//__end(atom.is_integer() && atom.m_i == 2);
__end(1);


__begin(int_atom_assign_text)


::atom atom(1);

atom = "2";


__end(atom.is_text() && atom.m_str == "2");


__begin(text_atom_assign_int)


::atom atom("1");

atom = 2;

throw todo;
//__end(atom.is_integer() && atom.m_i == 2);
__end(1);



__begin(text_atom_assign_text)


::atom atom("1");

atom = "2";


__end(atom.is_text() && atom.m_str == "2");

__END();

__START(numeric_array_copy)

__begin(numeric_array_copy_constructor)


int_array_base ia1;

ia1.add(1);
ia1.add(1000);
ia1.add(200'000'000);

int_array_base ia2(ia1);

__end(ia2.size() == 3 && ia2[0] == 1 && ia2[1] == 1'000 && ia2[2] == 200'000'000)


__begin(numeric_array_assign_construct)


int_array_base ia1;

ia1.add(1);
ia1.add(1000);
ia1.add(200'000'000);

int_array_base ia2 = ia1;

__end(ia2.size() == 3 && ia2[0] == 1 && ia2[1] == 1'000 && ia2[2] == 200'000'000)


__begin(numeric_array_assign)


int_array_base ia1;

ia1.add(1);
ia1.add(1000);
ia1.add(200'000'000);

int_array_base ia2;

ia2 = ia1;

__end(ia2.size() == 3 && ia2[0] == 1 && ia2[1] == 1'000 && ia2[2] == 200'000'000)

__END();


__START(pointer_array_copy)

__begin(pointer_array_copy_constructor)

throw todo;

//::pointer_array < ::item> itema1;

//itema1.add(øallocate ::item(1));
//itema1.add(øallocate< ::item >(1'000));
//itema1.add(øallocate< ::item >(200'000'000));

//::pointer_array < ::item> itema2(itema1);

//__end(itema2.size() == 3 && itema2[0]->m_item.m_iItem == 1 && itema2[1]->m_item.m_iItem == 1'000 && itema2[2]->m_item.m_iItem == 200'000'000)

__end(1)

__END();

