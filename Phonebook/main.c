#include "main.h"
#include "color.h"
#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "input.h"


int main() {
	ENABLE_COLORS();

	printf( BLUE BOLD "~~~Welcome to Your Phone Directory!~~~" RESET "\n");
	printf("Enter a number corresponding with the action you wish to take.\n");
	printf(BLUE BOLD "1) " RESET "Add a new entry.\n");
	printf(BLUE BOLD "2) " RESET "Delete an entry.\n");
	printf(BLUE BOLD "3) " RESET "Update an entry.\n");
	printf(BLUE BOLD "4) " RESET "Display entries.\n"); //Will have a sub-menu
	printf(BLUE BOLD "5) " RESET "Search for an entry.\n\n");
	//6) Save and load options? (If we want the user to choose what is saved)

	int menu_input = input_number(1, 5);

	switch (menu_input) {
		case 1: //Add a new entry
			break;

		case 2: //Delete an entry
			break;

		case 3: //Update an entry
			break;

		case 4: //Display entries
			break;

		case 5: //Search
			break;
	}

	return 0;
}