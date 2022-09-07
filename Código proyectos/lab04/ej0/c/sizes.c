#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 34, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name),sizeof(messi.age),sizeof(messi.height),sizeof(messi));

    data_t messi2 = {"Lionel Messi", 34, 169};
    print_data(messi2);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi2.name),sizeof(messi2.age),sizeof(messi2.height),sizeof(messi2));

    // La suma de los miembros coincide con el total? No
    // ¿El tamaño del campo name depende del nombre que contiene? No


    return EXIT_SUCCESS;
}

