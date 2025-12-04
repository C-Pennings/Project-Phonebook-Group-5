/* types.h */
#pragma once
#include <stddef.h>

typedef struct String {
    char* data;
    size_t length;
} String;

typedef struct Entry {
    String* name;
    String* phone_number;
} Entry;

typedef struct Node {
    Entry* value;
    struct Node* next;   
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    size_t length;
} List;