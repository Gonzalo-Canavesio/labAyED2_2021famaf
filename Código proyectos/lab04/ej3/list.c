#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct _Node {
    list_elem elem;
    struct _Node *next;
} Node;

list empty(void){
    list l = NULL;
    return l;
}

list addl(list l, list_elem e){
    list p;
    p = malloc(sizeof(Node));
    p->elem = e;
    p->next = l;
    l = p;   
    return l;
}

bool is_empty(list l){
    return (l == NULL);
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    Node* p;
    p = l;
    l = l->next;
    free(p);
    return l;
}

list addr(list l, list_elem e){
    Node* p,*q;
    q = malloc(sizeof(Node));
    q->elem = e;
    q->next = NULL;
    if (l != NULL){
        p = l;
        while(p->next != NULL){
            p=p->next;
        };
        p->next = q;
    } else {
        l = q;
    }
    return l;
}

unsigned int length(list l){
    Node *p;
    unsigned int n = 0;
    p = l;
    while (p != NULL){
        n++;
        p = p->next;
    };
    return n;
}

list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    Node *p;
    for (unsigned int i = 0; i < n; i++){
       p=p->next; 
    };
    return p->elem;
}

list take(list l, unsigned int n){
    Node *p, *q;
    p = l;
    for (unsigned int i = 0; i < n-1; i++){
        if (p != NULL) {
           p=p->next;
        };
    };
    if (p!= NULL){
        q = p->next;
        p->next = NULL;
        while (q != NULL){
            p=q;
            q=q->next;
            free(p);
        };
    };
    return l;
}

list drop(list l, unsigned int n){
    Node *p;
    for (unsigned int i = 0; i < n; i++){
        if (l != NULL) {
            p = l;
            l = l->next;
            free(p);
        };
    };
    return l;
}

list copy_list(list l){
    list l2 = empty();
    Node *p, *q;
    p = l;
    if(p != NULL){
        l2 = malloc(sizeof(Node));
        l2->elem = l->elem;
        q = l2;
        while(p->next != NULL){
            q->next = malloc(sizeof(Node));
            q = q->next;
            p = p->next;
            q->elem = p->elem;
        }
        q->next = NULL;
    } else {
        l2 = NULL;
    };
    return l2;
}

list concat(list l, list l0){
    list p, l0_copy;
    l0_copy = copy_list(l0);
    if (l == NULL){
        l = l0_copy;
    } else {
        p = l;
        while (p->next != NULL){
            p = p->next;
        };
        p->next = l0_copy;
    };
    return l;
}

void destroy(list l){
    Node *p;
    while (l != NULL) {
        p = l;
        l = l->next;
        free(p);
    };
}