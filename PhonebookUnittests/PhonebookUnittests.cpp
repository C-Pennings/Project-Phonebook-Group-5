#include "pch.h"
#include "CppUnitTest.h"
#include "../Phonebook/main.h"
#include <ctype.h>

extern "C" typedef struct String;
extern "C" typedef struct Entry;
extern "C" typedef struct Node;
extern "C" typedef struct List;

extern "C" bool append(List*, Entry*);
extern "C" bool prepend(List*, Entry*);
extern "C" int search(List*, String*, String*);
extern "C" void search_all(List*, List*, String*, String*);
extern "C" bool delete(List*, int);
extern "C" bool free_list(List*);
extern "C" Entry* step_node(Node*, int);
extern "C" Entry* step_back_node(Node*, int);
extern "C" Entry* create_entry(String*, String*);
extern "C" void init_list(List* list);
extern "C" String* get_search_type();
extern "C" bool A_Contains_B(String*, String*);
extern "C" void free_temp_list(List*);
extern "C" bool checkString(String* str, String* pattern);
extern "C" bool con_run();

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PhonebookUnittests
{
	//Contains tests for functions in the functions.c file
	TEST_CLASS(FunctionsUnitTests)
	{
	public:
		
		TEST_METHOD(create_entry_test)
		{

		}

		TEST_METHOD(append_test)
		{

		}

		TEST_METHOD(prepend_test)
		{

		}

		TEST_METHOD(search_test)
		{

		}

		TEST_METHOD(delete_test)
		{

		}

		TEST_METHOD(free_list_test)
		{

		}

		TEST_METHOD(step_node_test)
		{

		}

		TEST_METHOD(step_back_node_test)
		{

		}

		TEST_METHOD(get_entry_at_test)
		{

		}

		TEST_METHOD(init_list_test)
		{

		}

		TEST_METHOD(A_Contains_B_test)
		{

		}

		TEST_METHOD(search_all_test)
		{

		}

		TEST_METHOD(free_temp_list_test)
		{

		}

		TEST_METHOD(con_run_test)
		{

		}

		TEST_METHOD(checkString_test)
		{

		}
	};

	//Contains tests for functions in the input.c file
	TEST_CLASS(InputUnitTests)
	{
	public:

		TEST_METHOD(input_number_test)
		{

		}

		TEST_METHOD(input_string_test)
		{

		}

		TEST_METHOD(clear_input_buffer_test)
		{

		}

		TEST_METHOD(get_search_type_test)
		{

		}
	};

	//Contains tests for functions in the File_IO.c file
	TEST_CLASS(FileIOUnitTests)
	{
	public:

		TEST_METHOD(open_mode_test)
		{

		}

		TEST_METHOD(read_x_data_test)
		{

		}
	};
}
