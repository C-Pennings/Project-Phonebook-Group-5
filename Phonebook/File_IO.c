#include <stdio.h>
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

FILE* open_mode(const char* filename, const char* mode) {
    if (!filename || !mode) {
        return NULL;
    }
    FILE* file = fopen(filename, mode);
    if (!file) {
        return NULL;
    }

    return  file;
}

char* read_x_data(const char* line, int target_index) {
    #define MAX_LINE_LENGTH 1024
    #define MAX_FIELD 5

    if (!line || target_index < 0 || target_index >= MAX_FIELD) { //5 pieces of data ie. name,number,food,drink,address
        return NULL;
    }

    char line_buffer[MAX_LINE_LENGTH];
 
    strcpy_s(line_buffer, sizeof(line_buffer), line);

    //set line buffer
    size_t len = strlen(line_buffer);
    if (len > 0 && line_buffer[len - 1] == '\n') {
        line_buffer[len - 1] = '\0';
    }

    char* token;
    char* context=NULL;
    char* result_word = NULL;

    token = strtok_s(line_buffer, ",", &context);

    for (int i = 0; (token != NULL) && i < MAX_FIELD ;i++) {
        //is a word at index
        if (i == target_index) {
            size_t token_len = strlen(token);
            result_word = (char*)malloc(token_len + 1);

            if (result_word == NULL) {
                return NULL;
            }
            strcpy_s(result_word, token_len + 1, token);
            return result_word;
        }
     
        token = strtok_s(NULL, ",", &context);
    }
    return NULL;
}
