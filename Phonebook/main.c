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

				printf(GREEN BOLD "Added succesfully.\n\n" RESET);

				break;

			case 2: //Delete an entry

				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

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
					printf(GREEN BOLD "Contact successfully deleted.\n\n" RESET);
				}
				else {
					printf(RED BOLD "Could not find target index in list.\n\n" RESET);
				}

				free(delete_search_value);
				free(delete_search_type);

				break;

			case 3: //Update an entry

				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

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

				if (delete(contact_list, update_index)) {
					printf(GREEN BOLD "Original contact found and removed.\n\n" RESET);
				}
				else {
					printf(RED BOLD "Original contact not found. Update failed.\n\n" RESET);
					free(update_search_value);
					free(update_search_type);
					break;
				}

				printf("Enter updated contact name: ");
				String* new_contact_name = input_string();
				printf("Enter updated contact phonenumber: ");
				String* new_contact_number = input_string();

				Entry* updated_contact = create_entry(new_contact_name, new_contact_number);
				append(contact_list, updated_contact);

				break;

			case 4: //Display entries

				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				printf(BLUE BOLD "\n~Options for Displaying~\n" RESET);
				printf("1) Display a specific contact.\n");
				printf("2) Display a range of contacts.\n");
				printf("3) Display all contacts.\n\n");

				int display_menu_input = input_number(1,3);
				int display_index;
				int display_max;

				switch (display_menu_input) {
					case 1: //One contact
						printf("You currently have %d contacts.\n", (int)contact_list->length);
						printf("At what position is your desired contact?: ");
						display_index = input_number(1, (int)contact_list->length);
						Entry* display_node = step_node(contact_list->head, display_index-1);
						printf(GREEN BOLD "Contact %d: %s, %s\n\n" RESET, display_index, display_node->name->data, display_node->phone_number->data);
						break;

					case 2: //Range
						if (contact_list->length < 2) {
							printf(RED BOLD "You currently only have one contact, not enough for a range.\n\n" RESET);
							break;
						}
						printf("You currently have %d contacts.\n", (int)contact_list->length);
						printf("At what position does your range start?: ");
						display_index = input_number(1, ((int)contact_list->length - 1));
						printf("At what position does your range end?: ");
						display_max = input_number(display_index + 1, (int)contact_list->length);

						for (int i = display_index; i <= display_max; i++) {
							Entry* display_node = step_node(contact_list->head, i - 1);
							printf(GREEN BOLD "Contact %d: %s, %s\n" RESET, i, display_node->name->data, display_node->phone_number->data);
						}
						printf("\n");

						break;

					case 3: //All
						printf("All contacts:\n");
						for (int i = 1; i <= contact_list->length; i++) {
							Entry* display_node = step_node(contact_list->head, i - 1);
							printf(GREEN BOLD "Contact %d: %s, %s\n" RESET, i, display_node->name->data, display_node->phone_number->data);
						}
						printf("\n");

						break;
				}

				break;

			case 5: //Search

				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				printf("\nSearching for a contact...\n");
				printf("You currently have %d contacts.\n", (int)contact_list->length);

				int search_index;
				String* search_value;
				String* search_type = get_search_type();

				if (search_type->data[0] == 'n' || search_type->data[0] == 'N') {
					printf("Enter name of contact: ");
					search_value = input_string();
				}
				else {
					printf("Enter phonenumber of contact: ");
					search_value = input_string();
				}

				search_index = search(contact_list, search_value, search_type);

				if (search_index == -1) {
					printf(RED BOLD "No results.\n\n" RESET);
					break;
				}

				Entry* search_target_node = step_node(contact_list->head, search_index);
				printf(GREEN BOLD "Contact %d: %s, %s\n\n" RESET, search_index+1, search_target_node->name->data, search_target_node->phone_number->data);

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