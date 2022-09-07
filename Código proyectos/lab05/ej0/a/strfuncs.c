#include <stdlib.h>

#include "strfuncs.h"


size_t string_length(const char *str){
    unsigned int i = 0;
    size_t tam = 0;
    while (str[i] != '\0'){
        tam += sizeof(str[i]);
        i++;
    };
    return tam;
}

char *string_filter(const char *str, char c){
    unsigned int i = 0;
    unsigned int j = 0;
    char *new_str = malloc(sizeof(char)*(string_length(str)+1));
    while (str[i] != '\0'){
        if(str[i] != c){
            new_str[j] = str[i];
            j++;
        }
        i++;
    };
    new_str[j] = '\0';
    return new_str;
}