#include "main.h"
#include "color.h"
#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "input.h"
#include "functions.h"


int main() {

	ENABLE_COLORS();

	//Initialize main list
	List* contact_list = (List*)malloc(sizeof(List));
	if (!contact_list) {
		return -1; //Memory allocation failure.
	}
	init_list(contact_list);

	bool continue_program = true;

	while (continue_program) {

		printf(BLUE BOLD "~~~Welcome to Your Phone Directory!~~~" RESET "\n");
		printf("Enter a number corresponding with the action you wish to take.\n");
		printf(BLUE BOLD "1) " RESET "Add a new contact.\n");
		printf(BLUE BOLD "2) " RESET "Delete a contact.\n");
		printf(BLUE BOLD "3) " RESET "Update a contact.\n");
		printf(BLUE BOLD "4) " RESET "Display contacts.\n"); //Will have a sub-menu
		printf(BLUE BOLD "5) " RESET "Search for an contact.\n");
		printf(BLUE BOLD "6) " RESET "Exit program.\n\n");

		int menu_input = input_number(1, 6);

		switch (menu_input) {
			case 1: //Add a new entry, maybe add an option to add at start or end?

				printf("\nAdding a new contact...\n");

				printf("Enter contact name: ");
				String* contact_name = input_string();
				printf("Enter contact phone number: ");
				String* contact_number = input_string();

				Entry* new_contact = create_entry(contact_name, contact_number);
				append(contact_list, new_contact);

				printf("Added succesfully.\n\n");

				break;

			case 2: //Delete an entry

				printf("\nDeleting a contact...\n");

				int delete_index;
				String* delete_search_value;
				String* delete_search_type = get_search_type();

				if (delete_search_type->data[0] == 'n' || delete_search_type->data[0] == 'N') {
					printf("Enter name of contact: ");
					delete_search_value = input_string();
				}
				else {
					printf("Enter phonenumber of contact: ");
					delete_search_value = input_string();
				}

				delete_index = search(contact_list, delete_search_value, delete_search_type);

				if (delete(contact_list, delete_index)) {
					printf("Contact successfully deleted.");
				}
				else {
					printf("Could not find target index in list.");
				}

				break;

			case 3: //Update an entry

				printf("\nUpdating a contact...\n");

				int update_index;
				String* update_search_value;
				String* update_search_type = get_search_type();

				if (update_search_type->data[0] == 'n' || update_search_type->data[0] == 'N') {
					printf("Enter name of contact: ");
					update_search_value = input_string();
				}
				else {
					printf("Enter phonenumber of contact: ");
					update_search_value = input_string();
				}

				update_index = search(contact_list, update_search_value, update_search_type);
				delete(contact_list, update_index);

				printf("Enter updated contact name: ");
				String* new_contact_name = input_string();
				printf("Enter updated contact phonenumber: ");
				String* new_contact_number = input_string();

				Entry* updated_contact = create_entry(new_contact_name, new_contact_number);
				append(contact_list, updated_contact);

				break;

			case 4: //Display entries

				printf("\nDisplay a range or a specific entry?\n");
				//More menu
				break;

			case 5: //Search

				printf("\nSearching for a contact...\n");

				break;

			case 6: //exit

				printf("\nExiting program...\n");
				continue_program = false;

				break;
		}
	}

	free_list(contact_list);
	return 0;
}