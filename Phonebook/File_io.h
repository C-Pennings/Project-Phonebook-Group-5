#pragma once
#include <stdbool.h>
#include "File_io.h"

bool open_mode(const char* filename, const char* mode);
bool write_to_data(FILE* file, const char* string, int data);
char* read_x_data(FILE* file, int target_line, int target_index);
bool rewrite(const char* filename, int head);