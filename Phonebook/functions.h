#pragma once //Charlie made this file
#include <stdbool.h>
#include "types.h"
#include <stdio.h>

bool append(List*, Entry*);
bool prepend(List*, Entry*);
int search(List*, String*, String*);
void search_all(List*,List*, String*, String*);
bool delete(List*, int);
bool free_list(List*);
Entry* step_node(Node*, int);
Entry* step_back_node(Node*, int);
Entry* create_entry(String*, String*);
void init_list(List* list);
String* get_search_type();
bool A_Contains_B(String*,String*);
void free_temp_list(List*);
void load_entries(List*, FILE*);