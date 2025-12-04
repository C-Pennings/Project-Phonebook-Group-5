#pragma once //Charlie
#include <stdbool.h>
#include "types.h"

bool append(List*, Entry*);
bool prepend(List*, Entry*);
int search(List*, String*, String*);
bool delete(List*, int);
bool free_list(List*);
Entry* step_node(Node*, int);
Entry* step_back_node(Node*, int);
Entry* create_entry(String*, String*);