#include "types.h" //Charlie coded this whole file
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

//used to take integer input within a specified range
int input_number(int min, int max) { //Charlie
	int number = min - 1;

	while (number < min || number > max) {
		printf("Enter a number (%d - %d): ", min, max);
		int result = scanf("%d", &number);
		if (result != 1) {
			// Invalid input, clear the input buffer
			clear_input_buffer();
			number = min - 1; // reset number to stay in the loop
		} else {
			// Clear the input buffer after successful read
			clear_input_buffer();
		}
	}

	return number;
}

// used to take string input from user
String* input_string() { //Charlie
	size_t current_length = 0;
	int c = 0;
	
	String* str = (String*)malloc(sizeof(String));
	if (str == NULL) {
		printf("Memory Initialization Failed");
		return NULL;
	} //check if memory is not null

	size_t buffer_size = 16;
	char* buffer = (char*)malloc(buffer_size * sizeof(char));
	if (buffer == NULL) {
		printf("Memory Initialization Failed");
		return NULL;
	} //check if memory is not null

	while ((c = getchar()) != '\n' && c != EOF) {
		//check if our input buffer is full
		if (current_length + 1 >= buffer_size) {
			buffer_size *= 2; //add more space to buffer
			char* temp = (char*)realloc(buffer, buffer_size * sizeof(char)); //reallocate the memory to the doubled buffer size
			if (temp == NULL) {
				printf("Memory Reallocation Failed");
				free(buffer);
				return NULL;
			}
			buffer = temp;
		}
		buffer[current_length++] = (char)c;
	}

	//assign null character to end of string
	buffer[current_length] = '\0';

	//reduce buffer size to length of string for memory efficiency
	char* final_buffer = (char*)realloc(buffer, (current_length + 1) * sizeof(char));
	if (final_buffer == NULL) {
		str->data = buffer;
		str->length = current_length;
		return str; //fall back to normal buffer
	}
	str->data = final_buffer;
	str->length = current_length;
	return str; //returns optimized buffer size
}

// used to clear the input buffer
void clear_input_buffer() { //Charlie
	while (getchar() != '\n');
	return;
}