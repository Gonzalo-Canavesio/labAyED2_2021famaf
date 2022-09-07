#include <stdlib.h>
#include <stdio.h> 
#include <assert.h>
#include "pair.h" 

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t r;
    r = malloc(sizeof(struct s_pair_t));
    r->fst = x;
    r->snd = y;
    assert(r->fst == x && r->snd == y);
    return r; 
}

elem pair_first(pair_t p){
    elem fst = p->fst;
    assert(fst == p->fst);
    return fst;
}

elem pair_second(pair_t p){
    elem snd = p->snd;
    assert(snd == p->snd);
    return snd;
}

pair_t pair_swapped(pair_t p){
    pair_t q;
    q = malloc(sizeof(struct s_pair_t));
    q->fst = p->snd;
    q->snd = p->fst;
    assert(p->fst == q->snd && p->snd == q->fst);   
    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);
    p = NULL;
    return p;
}