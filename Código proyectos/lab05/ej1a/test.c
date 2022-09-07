#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack pila1 = stack_empty();
    stack pila2 = stack_empty();
    pila1 = stack_push(pila1, 60);
    pila1 = stack_pop(pila1);
    printf("%d\n", stack_is_empty(pila1));
    stack_elem *q = stack_to_array(pila1);
    pila1 = stack_push(pila1, 2);
    pila1 = stack_push(pila1, 3);
    pila1 = stack_push(pila1, 4);
    pila1 = stack_push(pila1, 5);
    pila1 = stack_push(pila1, 6);
    stack_elem *p = stack_to_array(pila1);
    stack_elem *p2 = stack_to_array(pila2);
    printf("%d\n", stack_size(pila1));
    stack_destroy(pila1);
    stack_destroy(pila2);
    free(q);
    free(p);
    free(p2);

    printf("\n\n\n\n");
    stack pila3 = stack_empty();
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,1);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,2);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,3);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,4);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,5);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,6);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,7);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,8);
    printf("%d\n",stack_size(pila3));
    pila3 = stack_push(pila3,9);
    printf("%d\n",stack_size(pila3));
    stack pila4 = stack_push(pila3,4);
    stack_destroy(pila4);
    return 0;
}
