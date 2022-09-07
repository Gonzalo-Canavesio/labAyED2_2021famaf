#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}


char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        printf("Argumentos invalidos");
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    unsigned int i = 0u;
    FILE *archivo = fopen(path,"r");
    while(!feof(archivo) && i < max_size){
        fscanf(archivo, "%u '%c\'\n", &indexes[i], &letters[i]);
        ++i;
    };
    fclose(archivo);
    return i;
}

void ordenar_palabra(unsigned int indexes[], char letters[],char sorted[],unsigned int length){
    unsigned int j = 0u;
    for(unsigned int i = 0u; i < length; ++i){
        j = 0u;
        while(indexes[j] != i){
            ++j;
            };
        sorted[i] = letters[j];
    };
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = data_from_file(filepath,indexes,letters,MAX_SIZE);
    ordenar_palabra(indexes,letters,sorted,length);  
    dump(sorted, length);

    return EXIT_SUCCESS;
}

