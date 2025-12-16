#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "File_io.h"

FILE* open_mode(const char* filename, const char* mode);
//bool write_to_data(FILE* file, const char* string, int data);
String* read_x_data(const char* line, int target_index);
//bool rewrite(const char* filename, int head);