#include "string.h"
#include <stdio.h>

int main(void){
    string palabra = string_create("Hola");
    string palabra2 = string_create("Bebe");
    string copia = string_clone(palabra);
    printf("%d\n",string_length(palabra));
    printf("%d\n",string_eq(copia, palabra));
    printf("%d\n",string_less(copia,palabra2));
    printf("%d\n",string_less(palabra2,copia));
    printf("%s", string_ref(palabra));  
    string_dump(copia,stdout);
    string_dump(palabra2,stdout);    
    palabra = string_destroy(palabra);
    palabra2 = string_destroy(palabra2);
    copia = string_destroy(copia);



    return 0;
}
