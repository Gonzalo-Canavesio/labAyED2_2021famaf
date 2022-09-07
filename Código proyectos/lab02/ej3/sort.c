#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i=izq+1u,j=der;
    while (i <= j){
        if (goes_before(a[i],a[izq])){
            i= i+1u;
        } else if(goes_before(a[izq],a[j])) {
            j= j-1u;
        } else {
            swap(a,i,j);
        };
    };
    swap(a,izq,j);
    return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        unsigned int piv = partition(a, izq, der);
        if(piv > izq){
            quick_sort_rec(a, izq, piv-1u);
        };
        if(piv < der){
            quick_sort_rec(a, piv+1u, der);
        };

    };
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

