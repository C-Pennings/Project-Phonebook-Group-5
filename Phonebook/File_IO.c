#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

bool open_mode(const char* filename, const char* mode) {
    if (!filename || !mode) {
        return false;
    }
    FILE* file = fopen(filename, mode);
    if (!file) {
        return false;
    }

    return true;
}
//bool write_to_data(FILE* file, const char* string, int data) {}
char* read_x_data(FILE* file, int target_line, int target_index) {
#define MAX_LINE_LENGTH 1024 
    char line_buffer[MAX_LINE_LENGTH];
    char* token;
    char* context;
    int current_index = 0;
    char* result_word = NULL;
    if (!file || target_line <= 0 || target_index <= 0 || target_index >= 5) { //5 pieces of data ie. name,number,food,drink,address
        return NULL;
    }
    //read from front
    if (fseek(file, 0, SEEK_SET) != 0) {
        return NULL;
    }
    int current_line = 0;
    //get to target line
    while (current_line < target_line) {
        if (fgets(line_buffer, MAX_LINE_LENGTH, file) == NULL) {

            return NULL; // Line not found/couldnt read
        }
        current_line++;
    }
    //set line buffer
    size_t len = strlen(line_buffer);
    if (len > 0 && line_buffer[len - 1] == '\n') {
        line_buffer[len - 1] = '\0';
    }
    token = strtok_s(line_buffer, ",", &context);
    while (token != NULL) {
        //is a word at index
        if (current_index == target_index) {
            size_t token_len = strlen(token);
            result_word = (char*)malloc(token_len + 1);

            if (result_word != NULL) {
                strncpy_s(result_word,sizeof(result_word), token, token_len);
                result_word[token_len] = '\0';
            }
            return result_word;
        }
        current_index++;
        if (current_index >= 5) {
            break;
        }
        token = strtok_s(NULL, ",", &context);
    }
    return NULL;
}
//rewrite the log// change int to appropriate data type

//bool rewrite(const char* filename, int head) {}


