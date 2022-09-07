#include <stdlib.h>
#include <stdio.h> 
#include <assert.h>
#include "pair.h" 

pair_t pair_new(int x, int y){
    pair_t r;
    r.fst = x;
    r.snd = y;
    assert(r.fst == x && r.snd == y);
    return r; 
}

int pair_first(pair_t p){
    int fst = p.fst;
    assert(fst == p.fst);
    return fst;
}

int pair_second(pair_t p){
    int snd = p.snd;
    assert(snd == p.snd);
    return snd;
}

pair_t pair_swapped(pair_t p){
    pair_t q;
    q.fst = p.snd;
    q.snd = p.fst;
    assert(q.fst == p.snd && q.snd == p.fst);
    return q;
}

pair_t pair_destroy(pair_t p){
    return p;
}