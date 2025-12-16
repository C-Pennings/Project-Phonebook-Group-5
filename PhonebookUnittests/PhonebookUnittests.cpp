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
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			Entry* test_entry = create_entry(name, phone_number);

			Assert::AreEqual("Ted", test_entry->name->data);
			Assert::AreEqual("123", test_entry->phone_number->data);
		}

		TEST_METHOD(append_to_empty_test)
		{
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			Entry* test_entry; test_entry->name = name; test_entry->phone_number = phone_number;

			List* test_list; test_list->head = NULL; test_list->tail = NULL; test_list->length = 0;

			append(test_list, test_entry);

			Assert::AreEqual("Ted", test_list->head->value->name->data);
			Assert::AreEqual("123", test_list->head->value->phone_number->data);
		}

		TEST_METHOD(append_to_filled_test)
		{
			//New entry data
			String* name1; name1->data = "Ted"; name1->length = sizeof(name1->data);
			String* phone_number1; phone_number1->data = "123"; phone_number1->length = sizeof(phone_number1->data);

			//Entry to be added
			Entry* test_entry; test_entry->name = name1; test_entry->phone_number = phone_number1;



			//Entry data already in list
			String* name2; name2->data = "Ted"; name2->length = sizeof(name2->data);
			String* phone_number2; phone_number2->data = "123"; phone_number2->length = sizeof(phone_number2->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name2; list_entry->phone_number = phone_number2;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			//Make the list with a single node
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;



			append(test_list, test_entry);

			Assert::AreEqual(test_entry, test_list->tail->value);
		}

		TEST_METHOD(prepend_to_empty_test)
		{
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			Entry* test_entry; test_entry->name = name; test_entry->phone_number = phone_number;

			List* test_list; test_list->head = NULL; test_list->tail = NULL; test_list->length = 0;

			append(test_list, test_entry);

			Assert::AreEqual("Ted", test_list->head->value->name->data);
			Assert::AreEqual("123", test_list->head->value->phone_number->data);
		}

		TEST_METHOD(prepend_to_filled_test)
		{
			//New entry data
			String* name1; name1->data = "Ted"; name1->length = sizeof(name1->data);
			String* phone_number1; phone_number1->data = "123"; phone_number1->length = sizeof(phone_number1->data);

			//Entry to be added
			Entry* test_entry; test_entry->name = name1; test_entry->phone_number = phone_number1;



			//Entry data already in list
			String* name2; name2->data = "Ted"; name2->length = sizeof(name2->data);
			String* phone_number2; phone_number2->data = "123"; phone_number2->length = sizeof(phone_number2->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name2; list_entry->phone_number = phone_number2;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			//Make the list with a single node
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;



			prepend(test_list, test_entry);

			Assert::AreEqual(test_entry, test_list->head->value);
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
