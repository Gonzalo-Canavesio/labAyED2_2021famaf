#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */
#include <limits.h>   /* Para tener +inf y -inf */

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = INT_MIN;
    result.min_value = INT_MAX;

    for(int i = 0; i < ARRAY_SIZE; i++){
        if(result.max_value < array[i]){
            result.max_value = array[i];
            result.max_position = i;
        }
        if(result.min_value > array[i]){
            result.min_value = array[i];
            result.min_position = i;
        }        
    }

    return result;
}

int main(void)
{
    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };

    printf("Escribe los %d elementos del arreglo, separados por espacios\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++){
        scanf("%d", &array[i]);
    }

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Maximo: %d\n", result.max_value);
    printf("Posicion del maximo: %u\n", result.max_position);
    printf("Minimo: %d\n", result.min_value);
    printf("Posicion del minimo: %u\n", result.min_position);
    return 0;
}

