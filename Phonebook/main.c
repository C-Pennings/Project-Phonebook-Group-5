#include "main.h"
#include "color.h"
#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "input.h"


int main() {
	ENABLE_COLORS();

	/*printf(GREEN BOLD "Input Test (1-100)" RESET "\n");
	int test_str = input_number(1, 100);
	if (test_str != NULL) {
		printf("You entered: " CYAN BOLD "%d" RESET "\n", test_str);

	} else {
		printf(RED BOLD "Failed to read input integer." RESET "\n");
	}*/

	printf( BLUE BOLD "~~~Welcome to Your Phone Directory!~~~" RESET "\n");
	printf("Enter a number corresponding with the action you wish to take.\n");
	printf(BLUE "1)" RESET "Add a new entry.\n");
	printf(BLUE "2)" RESET "Delete an entry.\n");
	printf(BLUE "3)" RESET "Update an entry.\n");
	printf(BLUE "4)" RESET "Display entries.\n"); //Will have a sub-menu
	printf(BLUE "5)" RESET "Search for an entry.\n");
	//6) Save and load options? (If we want the user to choose what is saved)



	return 0;
}