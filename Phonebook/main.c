#include "main.h"
#include "color.h"
#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "input.h"


int main() {
	ENABLE_COLORS();

	printf(GREEN BOLD "Input Test (1-100)" RESET "\n");
	int test_str = input_number(1, 100);
	if (test_str != NULL) {
		printf("You entered: " CYAN BOLD "%d" RESET "\n", test_str);

	} else {
		printf(RED BOLD "Failed to read input integer." RESET "\n");
	}

	return 0;
}