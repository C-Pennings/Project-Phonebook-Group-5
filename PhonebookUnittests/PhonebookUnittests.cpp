#include "pch.h"
#include "CppUnitTest.h"
#include "../Phonebook/main.h"
#include "../Phonebook/functions.h"
#include "../Phonebook/input.h"
#include "../Phonebook/File_IO.h"
#include <stdbool.h>

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
			//Entry data already in list
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name; list_entry->phone_number = phone_number;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			//Make the list with a single node
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;



			String* search_value; search_value->data = "Ted"; search_value->length = sizeof(search_value->data);
			String* search_type; search_type->data = "n"; search_type->length = sizeof(search_type->data);

			int test_index = search(test_list, search_value, search_type);

			Assert::AreEqual(1, test_index);
		}

		TEST_METHOD(delete_test)
		{
			//Entry data already in list
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name; list_entry->phone_number = phone_number;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			//Make the list with a single node
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;


			int test_index = 1;
			bool deleted = delete(test_list, 1);

			Assert::AreEqual(true, deleted);
		}

		TEST_METHOD(free_list_test)
		{
			//Entry data already in list
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name; list_entry->phone_number = phone_number;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			//Make the list with a single node
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;



			free_list(test_list);

			Assert::AreEqual(0, (int)test_list->length);
		}

		TEST_METHOD(step_node_test)
		{
			String* name2; name2->data = "Ted"; name2->length = sizeof(name2->data);
			String* phone_number2; phone_number2->data = "123"; phone_number2->length = sizeof(phone_number2->data);

			Entry* list_entry2; list_entry2->name = name2; list_entry2->phone_number = phone_number2;

			Node* list_node2; list_node2->next = NULL; list_node2->value = list_entry2;



			String* name1; name1->data = "Ted"; name1->length = sizeof(name1->data);
			String* phone_number1; phone_number1->data = "123"; phone_number1->length = sizeof(phone_number1->data);

			Entry* list_entry1; list_entry1->name = name1; list_entry1->phone_number = phone_number1;

			Node* list_node1; list_node1->next = list_node2; list_node1->value = list_entry1;


			Entry* stepped_node = step_node(list_node1, 1);
			Assert::AreEqual(list_node2->value, stepped_node);
		}

		TEST_METHOD(step_back_node_test)
		{
			String* name2; name2->data = "Ted"; name2->length = sizeof(name2->data);
			String* phone_number2; phone_number2->data = "123"; phone_number2->length = sizeof(phone_number2->data);

			Entry* list_entry2; list_entry2->name = name2; list_entry2->phone_number = phone_number2;

			Node* list_node2; list_node2->next = NULL; list_node2->value = list_entry2;



			String* name1; name1->data = "Ted"; name1->length = sizeof(name1->data);
			String* phone_number1; phone_number1->data = "123"; phone_number1->length = sizeof(phone_number1->data);

			Entry* list_entry1; list_entry1->name = name1; list_entry1->phone_number = phone_number1;

			Node* list_node1; list_node1->next = list_node2; list_node1->value = list_entry1;


			Entry* stepped_node = step_back_node(list_node2, 1);
			Assert::AreEqual(list_node1->value, stepped_node);
		}

		TEST_METHOD(get_entry_at_test)
		{
			//Entry data already in list
			String* name; name->data = "Ted"; name->length = sizeof(name->data);
			String* phone_number; phone_number->data = "123"; phone_number->length = sizeof(phone_number->data);

			//Entry already in list
			Entry* list_entry; list_entry->name = name; list_entry->phone_number = phone_number;

			//Node already in list
			Node* list_node; list_node->next = NULL; list_node->value = list_entry;

			
			List* test_list; test_list->head = list_node; test_list->tail = list_node; test_list->length = 1;

			Entry* searched_entry = get_entry_at(test_list,0);

			Assert::AreEqual(list_entry, searched_entry);
		}

		TEST_METHOD(init_list_test)
		{
			List* test_list;
			init_list(test_list);

			Assert::IsNull(test_list->head);
			Assert::IsNull(test_list->tail);
			Assert::AreEqual(0, (int)test_list->length);
		}

		TEST_METHOD(A_Contains_B_test)
		{
			String* string1; string1->data = "Hello"; string1->length = sizeof(string1->data);
			String* string2; string2->data = "el"; string2->length = sizeof(string2->data);

			bool test_check = A_Contains_B(string1, string2);

			Assert::AreEqual(true, test_check);
		}
	};
}
