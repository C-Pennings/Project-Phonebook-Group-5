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
			case 1: //Add a new entry

				printf("\nAdding a new contact...\n");

				printf("Enter contact name: ");
				String* contact_name = input_string();
				printf("Enter contact phone number: ");
				String* contact_number = input_string();

				Entry* new_contact = create_entry(contact_name, contact_number);
				append(contact_list, new_contact);

				break;

			case 2: //Delete an entry

				printf("\Deleting a contact...\n");

				break;

			case 3: //Update an entry

				printf("\nUpdating a contact...\n");

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