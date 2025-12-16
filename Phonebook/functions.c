#include "functions.h" //Charlie coded this file
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include <stdio.h>
#include "File_io.h"
#include <ctype.h>

// Use Everytime when creating any Entry for consistency
Entry* create_entry(String* name, String* phone_number) {
    Entry* temp = malloc(sizeof * temp);
    if (!temp) return NULL;
    temp->name = name;
    temp->phone_number = phone_number;
    return temp;
}

// Used to append an Entry to the end of the list
bool append(List* list, Entry* entry) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return false;

    new_node->value = entry;
    new_node->next = NULL;

    if (list->tail == NULL) {
        // Case: list is empty
        new_node->prev = NULL;
        list->head = list->tail = new_node;
    }
    else {
        new_node->prev = list->tail;
        // Case: list has nodes
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->length++;
    return true;
}

// Used to prepend an Entry to the start of the list
bool prepend(List* list, Entry* entry) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return false;

    new_node->value = entry;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head == NULL) {
        // Empty list case
        list->head = list->tail = new_node;
    }
    else {
        // Normal case
        list->head->prev = new_node;
        list->head = new_node;
    }

    list->length++;
    return true;
}

// Used to search the list by any type, just specify 'n' or 'p' or any future value
// In the future, consider using enums for type safety
// In the future, create a compare function for partial matches
int search(List* list, String* value, String* type) {
    Node* current = list->head;
    int index = 0;
    bool contains=false;

    while (current != NULL) {
        Entry* entry = current->value;

        if (type->data[0] == 'n' || type->data[0] == 'N') {
            // Search by name
           
           if (entry->name->length == value->length &&
                strncmp(entry->name->data, value->data, value->length) == 0) {
                return index;
            }
           
         
        }
        else if (type->data[0] == 'p' || type->data[0] == 'P') {
            // Search by phone
            if (entry->phone_number->length == value->length &&
                strncmp(entry->phone_number->data, value->data, value->length) == 0) {
                return index;
            }
        }

        current = current->next;
        index++;
    }
    return -1;  // Not found
}

// delete is a fully functional delete by index
bool delete(List* list, int index) {
    if (index < 0 || index >= list->length || list->head == NULL) {
        return false;  // Invalid index or empty list
    }

    Node* current = list->head;
    int i = 0;

    // Traverse to the target index
    while (i < index) {
        current = current->next;
        i++;
    }

    // Unlink the node from the list
    if (current->prev) {
        current->prev->next = current->next;
    }
    else {
        list->head = current->next;  // Deleting head
    }

    if (current->next) {
        current->next->prev = current->prev;
    }
    else {
        list->tail = current->prev;  // Deleting tail
    }

    if (current->value) {
        if (current->value->name) {
            free(current->value->name->data);     // Free the char* inside String
            free(current->value->name);           // Free the String struct
        }
        if (current->value->phone_number) {
            free(current->value->phone_number->data);
            free(current->value->phone_number);
        }
        free(current->value);  // Free the Entry
    }

    free(current);  // Free the Node
    list->length--;
    return true;
}

// Fully deletes the entire data structure
bool free_list(List* list) {
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;

        // Free Entry + Strings
        if (current->value) {
            if (current->value->name) {
                free(current->value->name->data);
                free(current->value->name);
            }
            if (current->value->phone_number) {
                free(current->value->phone_number->data);
                free(current->value->phone_number);
            }
            free(current->value);
        }
        free(current);
        current = next;
    }

    list->head = list->tail = NULL;
    list->length = 0;
    return true;
}

// used to get an entry by stepping forward n times
Entry* step_node(Node* start, int steps) {
    Node* current = start;
    while (current != NULL && steps-- > 0) {
        current = current->next;
    }
    return current ? current->value : NULL;
}

// used to get an entry by stepping backward n times
Entry* step_back_node(Node* start, int steps) {
    Node* current = start;
    while (current != NULL && steps-- > 0) {
        current = current->prev;
    }
    return current ? current->value : NULL;
}

Entry* get_entry_at(List* list, int index) {
    if (index < 0 || index >= list->length) {
        return NULL;  // Invalid index
    }
    Node* current = list->head;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    return current->value;
}

// used to initialize a list
void init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

//
bool A_Contains_B(String* string_one, String* string_two) {
    char* word = string_one->data;
    char* word_two = string_two->data;
    if (!word|| !word_two) {
       return false;
    }
    return strstr(word, word_two) != NULL;

}
void search_all(List* list,List* temp, String* value, String* type) {
    Node* current = list->head;
    Node* temp_pnt = temp->head;
    int index = 0;
    bool contains = false;

    while (current != NULL) {
        Entry* entry = current->value;

        if (type->data[0] == 'n' || type->data[0] == 'N') {
            // Search by name
       
            if (A_Contains_B(entry->name, value)) {
                append(temp,entry);
            }
        }
        else if (type->data[0] == 'p' || type->data[0] == 'P') {
            // Search by phone
            if (A_Contains_B(entry->phone_number, value)) {
                append(temp, entry);
            }
        
        }

        current = current->next;
        index++;
    }
    //return -1;  // Not found
}
void free_temp_list(List* list) {
   list->head = NULL;
   list->tail = NULL;
   list->length = 0;
}
bool con_run() { //continue to run

    printf("press 1 to continue,press 2 to return to menu\n");
    int input = input_number(1, 2);
    if (input == 1) {
        return true;
    }
    return false;
}
void load_entries(List* list,FILE* file) {
    char line[1024];
        while (fgets(line, sizeof(line), file) != NULL) {
            char *temp_name = read_x_data(line,0);
            char *temp_number= read_x_data(line, 1);
            String *contact_name = create_string(temp_name);
            String *contact_number = create_string(temp_number);

            free(temp_name);
			free(temp_number);

            if (!contact_name || !contact_number) {
                free(contact_name);
                free(contact_number);
                continue;
            }
            Entry* new_contact = create_entry(contact_name, contact_number);
            append(list, new_contact);
        
        }
}
void save_contacts(List*list,FILE* file) {
    for (int i = 1; i <= list->length; i++) {
        Entry* display_node = step_node(list->head, i - 1);
        char* name = display_node->name->data;
        char* number = display_node->phone_number->data;
        fprintf(file, "%s, %s\n",name,number);
    }

}
String* create_string(char* word) {
        if (!word) return NULL;

        String* str = (String*)malloc(sizeof(String));
        if (!str) return NULL;

        str->length = (int)strlen(word);

        str->data = (char*)malloc(str->length + 1);
        if (!str->data) {
            free(str);
            return NULL;
        }

        strcpy_s(str->data, str->length + 1, word);

        return str;
    }

bool checkString(String* str, String* pattern) {
    if (!str || !pattern) {
        return false;
    }
    if (str->length != pattern->length) {
        return false;
    }
    
    for (size_t i = 0; i < str->length; i++) {
		if (pattern->data[i] == '?') {
            continue; // '?' matches any character
        }
		else if (isalpha(pattern->data[i]) != isalpha(str->data[i])) {
            return false;
        }
	}
	return true;
}