/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return (x.points <= y.points);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j){
    player_t temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
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


void sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        unsigned int piv = partition(a, izq, der);
        if(piv > izq){
            sort_rec(a, izq, piv-1u);
        };
        if(piv < der){
            sort_rec(a, piv+1u, der);
        };

    };
}

void sort(player_t a[], unsigned int length) {
    sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}