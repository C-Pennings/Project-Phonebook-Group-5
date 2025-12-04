#pragma once
#include "types.c"

int input_number(const char* prompt, int min, int max);
String* input_string(const char* prompt);
void clear_input_buffer();

