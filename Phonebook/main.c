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

	//Begin main program loop.
	bool continue_program = true;
	while (continue_program) {

		//Main menu
		printf(BLUE BOLD "~~~Welcome to Your Phone Directory!~~~" RESET "\n");
		printf("Enter a number corresponding with the action you wish to take.\n");
		printf(BLUE BOLD "1) " RESET "Add a new contact.\n");
		printf(BLUE BOLD "2) " RESET "Delete a contact.\n");
		printf(BLUE BOLD "3) " RESET "Update a contact.\n");
		printf(BLUE BOLD "4) " RESET "Display contact(s).\n"); //Has a sub-menu
		printf(BLUE BOLD "5) " RESET "Search for a contact.\n");
		printf(BLUE BOLD "6) " RESET "Exit program.\n\n");

		//Get user selection for main menu
		int menu_input = input_number(1, 6);

		//Evaluate user input
		switch (menu_input) {
			case 1: //Add a new entry, maybe add an option to add at start or end?

				printf("\nAdding a new contact...\n");

				//Get name and number to add.
				printf("Enter contact name: ");
				String* contact_name = input_string();
				printf("Enter contact phone number: ");
				String* contact_number = input_string();

				//Create an entry with user input, then append it to the main list.
				Entry* new_contact = create_entry(contact_name, contact_number);
				append(contact_list, new_contact);

				//Let the user know it has succeeded.
				printf(GREEN BOLD "Added succesfully.\n\n" RESET);

				//Restart main program loop.
				break;



			case 2: //Delete a contact

				printf("\nDeleting a contact...\n");

				//If there are no entered contacts, then restart the main program loop.
				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				//Initialize the index to delete and the value contained at the index.
				int delete_index;
				String* delete_search_value;
				//Ask the user if they are searching by phone number or name
				String* delete_search_type = get_search_type();

				//If they are searching by name...
				if (delete_search_type->data[0] == 'n' || delete_search_type->data[0] == 'N') {
					//...then ask for the name
					printf("Enter name of contact: ");
					delete_search_value = input_string();
				}
				//... otherwise...
				else {
					//...assume they are searching by phone number.
					printf("Enter phonenumber of contact: ");
					delete_search_value = input_string();
				}

				//Search by name/phone number to find the index of the contact
				delete_index = search(contact_list, delete_search_value, delete_search_type);

				//Try to delete the original contact
				if (delete(contact_list, delete_index)) {
					//If it is deleted.
					printf(GREEN BOLD "Contact successfully deleted.\n\n" RESET);
				}
				else {
					//If it is not deleted.
					printf(RED BOLD "Could not find target index in list.\n\n" RESET);
				}

				//Free the allocated memory for the created String structs
				free(delete_search_value);
				free(delete_search_type);

				//Restart main program loop.
				break;



			case 3: //Update an entry

				printf("\nUpdating a contact...\n");

				//If there are no contacts, then restart main program loop.
				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				//Initialize the index to update and the value contained at the index.
				int update_index;
				String* update_search_value;
				//Ask the user if they are searching by phone number or name
				String* update_search_type = get_search_type();

				//If they are searching by name...
				if (update_search_type->data[0] == 'n' || update_search_type->data[0] == 'N') {
					//...then ask for the name
					printf("Enter name of contact: ");
					update_search_value = input_string();
				}
				//... otherwise...
				else {
					//...assume they are searching by phone number.
					printf("Enter phonenumber of contact: ");
					update_search_value = input_string();
				}

				//Search list by name/phone number to find contact to update.
				update_index = search(contact_list, update_search_value, update_search_type);

				//Try to delete the original contact.
				if (delete(contact_list, update_index)) {
					//If it succeeds, then continue.
					printf(GREEN BOLD "Original contact found and removed.\n\n" RESET);
				}
				else {
					//Deletion failed, tell user
					printf(RED BOLD "Original contact not found. Update failed.\n\n" RESET);
					//Free memory for created String structs
					free(update_search_value);
					free(update_search_type);
					//Restart main program loop.
					break;
				}

				//Get the new name
				printf("Enter updated contact name: ");
				String* new_contact_name = input_string();
				//Get the new number
				printf("Enter updated contact phonenumber: ");
				String* new_contact_number = input_string();

				//Create a new entry with updated data, then append to main list.
				Entry* updated_contact = create_entry(new_contact_name, new_contact_number);
				append(contact_list, updated_contact);

				//Report success
				printf(GREEN BOLD "Contact successfully updated.\n\n" RESET);

				//Restart main program loop.
				break;

			case 4: //Display entries

				//If there are no contacts then restart main program loop.
				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				//Display sub-menu for display options.
				printf(BLUE BOLD "\n~Options for Displaying~\n" RESET);
				printf("1) Display a specific contact.\n");
				printf("2) Display a range of contacts.\n");
				printf("3) Display all contacts.\n\n");

				//Get user selection
				int display_menu_input = input_number(1,3);

				//Initialize needed variables for single index and range of indexes
				int display_index;
				int display_max;

				//Evaluate user selection
				switch (display_menu_input) {
					case 1: //One contact
						//List number of contacts
						printf("You currently have %d contacts.\n", (int)contact_list->length);
						//Get position of contact
						printf("At what position is your desired contact?: ");
						display_index = input_number(1, (int)contact_list->length);
						//Go through list and display the node at inputted index
						Entry* display_node = step_node(contact_list->head, display_index-1);
						printf(GREEN BOLD "Contact %d: %s, %s\n\n" RESET, display_index, display_node->name->data, display_node->phone_number->data);
						//Exit sub-menu
						break;

					case 2: //Range
						//Exit sub-menu if there is only 1 contact to avoid out of range errors
						if (contact_list->length < 2) {
							printf(RED BOLD "You currently only have one contact, not enough for a range.\n\n" RESET);
							break;
						}
						//List number of contacts
						printf("You currently have %d contacts.\n", (int)contact_list->length);
						//Get index of where the range starts
						printf("At what position does your range start?: ");
						display_index = input_number(1, ((int)contact_list->length - 1)); //Last index never available
						//Get index of where the range ends
						printf("At what position does your range end?: ");
						display_max = input_number(display_index + 1, (int)contact_list->length); //Indexes before min not available

						//Go through specified range of indexes and display the data in the node there
						for (int i = display_index; i <= display_max; i++) {
							Entry* display_node = step_node(contact_list->head, i - 1);
							printf(GREEN BOLD "Contact %d: %s, %s\n" RESET, i, display_node->name->data, display_node->phone_number->data);
						}
						printf("\n"); //Semantics for formatting

						//Exit the sub-menu
						break;

					case 3: //Display all
						printf("All contacts:\n");
						//Go through entire list and display data at each node
						for (int i = 1; i <= contact_list->length; i++) {
							Entry* display_node = step_node(contact_list->head, i - 1);
							printf(GREEN BOLD "Contact %d: %s, %s\n" RESET, i, display_node->name->data, display_node->phone_number->data);
						}
						printf("\n"); //Semantics for formatting

						//Exit the sub-menu
						break;
				}
				//Restart the main program loop.
				break;

			case 5: //Search

				printf("\nSearching for a contact...\n");

				//Check if there are no contacts
				if (contact_list->length < 1) {
					printf(RED BOLD "You currently have no contacts.\n\n" RESET);
					break;
				}

				//Display amount of contacts
				printf("You currently have %d contacts.\n", (int)contact_list->length);

				//Initialize the index to search for and the value contained at the index.
				int search_index;
				String* search_value;
				//Ask the user if searching by name or phone number
				String* search_type = get_search_type();

				//If searching by name...
				if (search_type->data[0] == 'n' || search_type->data[0] == 'N') {
					//...ask for name.
					printf("Enter name of contact: ");
					search_value = input_string();
				}
				//...otherwise...
				else {
					//... ask for phone number.
					printf("Enter phonenumber of contact: ");
					search_value = input_string();
				}

				//Use name/phone number to find index 
				search_index = search(contact_list, search_value, search_type);

				//If nothing was found then display error and restart main program loop.
				if (search_index == -1) {
					printf(RED BOLD "No results.\n\n" RESET);
					break;
				}

				//Go through list until at the correct index, then display data at that node
				Entry* search_target_node = step_node(contact_list->head, search_index);
				printf(GREEN BOLD "Contact %d: %s, %s\n\n" RESET, search_index+1, search_target_node->name->data, search_target_node->phone_number->data);

				//Restart main program loop.
				break;

			case 6: //exit

				printf("\nExiting program...\n");
				//Stop main program loop
				continue_program = false;

				//Exit main program.
				break;
		}
	}

	//Go through the contact list and free all allocated memory.
	free_list(contact_list);
	return 0;
}