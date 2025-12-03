typedef struct String String;
typedef struct Entry  Entry;
typedef struct Node   Node;
typedef struct List   List;

#include <stddef.h>

struct String {
    char* data;
    size_t length;
};

struct Entry {
    String* name;
    String* phone_number;
};

struct Node {
    Entry* value;
    Node* next;
    Node* prev;
};

struct List {
    size_t length;
    Node* head;
    Node* tail;
};