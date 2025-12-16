#include "pch.h"
#include "CppUnitTest.h"
#include "../Phonebook/main.h"
#include "../Phonebook/functions.h"
#include "../Phonebook/input.h"
#include "../Phonebook/File_IO.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PhonebookUnittests
{
	//Contains tests for functions in the functions.c file
	TEST_CLASS(FunctionsUnitTests)
	{
	public:
		
		TEST_METHOD(create_entry_test)
		{
			struct String* name;
			name->data = "Ted";
			name->length = sizeof(name->data);
			struct String* phone_number;
			phone_number->data = "123";
			phone_number->length = sizeof(phone_number->data);

			struct Entry* test_entry = create_entry(name, phone_number);

			Assert::AreEqual("Ted", test_entry->name->data);
			Assert::AreEqual("123", test_entry->phone_number->data);
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
