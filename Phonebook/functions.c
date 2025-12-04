#include "functions.h"
#include "types.c"

#include <stdbool.h>
#include <stdlib.h>

Entry* create_entry(String* name, String* phone_number) {
	Entry* temp = malloc(sizeof *temp);
	if (!temp) return NULL;
	temp->name = name;
	temp->phone_number = phone_number;
	return temp;
}

bool append(List* list, Entry* entry) {
	list->tail->next = malloc(sizeof(Node)); // Allocate memory for the new node
	if (!list->tail->next) return false; // Check for allocation failure
	list->tail->next->prev = list->tail; // Set the previous pointer of the new node
	list->tail = list->tail->next; // Move the tail pointer to the new node
	list->tail->value = entry; // Set the value of the new node
	list->tail->next = NULL; // Set the next pointer of the new node to NULL
	list->length++; // Increment the length of the list
	return true;
}

bool prepend(List* list, Entry* entry) {
	Node* new_node = malloc(sizeof(Node)); // Allocate memory for the new node
	if (!new_node) return false; // Check for allocation failure
	new_node->value = entry; // Set the value of the new node
	new_node->next = list->head; // Set the next pointer of the new node to the current head
	new_node->prev = NULL; // Set the previous pointer of the new node to NULL
	list->head->prev = new_node; // Set the previous pointer of the current head to the new node
	list->head = new_node; // Move the head pointer to the new node
	list->length++; // Increment the length of the list
	return true;
}

int search(List* list, String* value, String* type) {
	for (int i = 0; i < list->length; i++) {
		Entry* entry = step_node(list->head, 1);
		if (type->data[0] == 'n') { // Search by name
			if (entry->name->length == value->length &&
				strncmp(entry->name->data, value->data, value->length) == 0) {
				return i;
			}
		} else if (type->data[0] == 'p') { // Search by phone number
			if (entry->phone_number->length == value->length &&
				strncmp(entry->phone_number->data, value->data, value->length) == 0) {
				return i;
			}
		}
	}
	return -1;
}

bool delete(List* list, int index) {
	while (index-- > 0) {
		list->head = list->head->next;
	}
	Node* to_delete = list->head;
	if (to_delete->prev) {
		to_delete->prev->next = to_delete->next;
	} else {
		list->head = to_delete->next;
	}
	if (to_delete->next) {
		to_delete->next->prev = to_delete->prev;
	} else {
		list->tail = to_delete->prev;
	}
	free(to_delete->value);
	free(to_delete);
	list->length--;
	return true;
}

bool free_list(List* list) {
	while (list->head) {
		Node* temp = list->head;
		list->head = list->head->next;
		free(temp->value);
		free(temp);
	}
	return true;
}

Entry* step_node(Node* node, int steps) {
	while (steps-- > 0) {
		node = node->next;
	}
	return node->value;
}

Entry* step_back_node(Node* node, int steps) {
	while (steps-- > 0) {
		node = node->prev;
	}
	return node->value;
}
