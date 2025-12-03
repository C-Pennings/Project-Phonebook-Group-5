#include "functions.h"
#include "types.c"

#include <stdbool.h>
#include <stdlib.h>

bool append(List*, Entry*);
bool prepend(List*, Entry*);
int search(List*, String*, String*);
bool delete(List*, int);
bool free_list(List*);
Entry* step_node(Node*, int);
Entry* step_back_node(Node*, int);
Entry* create_entry(String*, String*);

Entry* create_entry(String* name, String* phone_number) {
	Entry* temp = malloc(sizeof *temp);
	if (!temp) return NULL;
	temp->name = name;
	temp->phone_number = phone_number;

	return temp;
}

bool append(List* list, Entry* entry) {
	// Implementation goes here
	return true;
}

bool prepend(List* list, Entry* entry) {
	// Implementation goes here
	return true;
}

int search(List* list, String* value, String* type) {
	// Implementation goes here
	return -1;
}

bool delete(List* list, int index) {
	// Implementation goes here
	return true;
}

bool free_list(List* list) {
	// Implementation goes here
	return true;
}

Entry* step_node(Node* node, int steps) {
	// Implementation goes here
	return NULL;
}

Entry* step_back_node(Node* node, int steps) {
	// Implementation goes here
	return NULL;
}
