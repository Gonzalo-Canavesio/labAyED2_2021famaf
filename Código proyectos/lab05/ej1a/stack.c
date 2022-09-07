#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack next;
    stack_elem elem;
};

stack stack_empty(){
    stack ret = NULL;
    return ret;
}

stack stack_push(stack s, stack_elem e){
    stack new = malloc(sizeof(struct _s_stack));
    new->elem = e;
    new->next = s;
    s = new;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack p;
    p = s;
    s = s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    stack p = s;
    unsigned int cant = 0u;
    while (p != NULL){
        p = p->next;
        cant++;
    }
    return cant;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}


bool stack_is_empty(stack s){
    return s == NULL;
}


stack_elem *stack_to_array(stack s){
    stack_elem *arreglo = NULL;
    if(stack_size(s)>0){
    size_t i = stack_size(s)-1;
    arreglo = calloc(stack_size(s),sizeof(stack_elem));
    stack p = s;
    while(p != NULL){
        arreglo[i] = p->elem;
        i--;
        p=p->next;
    } 
    }
    return arreglo;
}


stack stack_destroy(stack s){
    stack p;
    while (s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}