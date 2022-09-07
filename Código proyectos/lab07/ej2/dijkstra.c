#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

vertex_t elegir(set k,cost_t *d, unsigned int largo){
    assert(! set_is_empty(k));
    vertex_t minimo = set_get(k);
   	for(unsigned int i = 0u; i < largo; ++i){
    	if(set_member(i, k) && cost_lt(d[i], d[minimo])){ 
    		minimo = i;
    	}
    }
    return minimo;
}


cost_t *dijkstra(graph_t graph, vertex_t init) {
    cost_t *d = calloc(graph_max_vertexs(graph), sizeof(cost_t));
    vertex_t c;
    set k = set_empty();
    for(unsigned int i = 0u; i < graph_max_vertexs(graph); ++i){
        k = set_add(k,i);
    }
    k = set_elim(k,init);
    for(unsigned int j = 0u; j < graph_max_vertexs(graph); ++j){
        d[j] = graph_get_cost(graph,init,j);
    }
    while(! set_is_empty(k)){
        c = elegir(k,d,graph_max_vertexs(graph));
        k = set_elim(k,c);
        for(unsigned int j = 0u; j < graph_max_vertexs(graph); ++j){
            if(set_member(j,k) && cost_lt(cost_sum(d[c],graph_get_cost(graph,c,j)), d[j])){
                d[j] = d[c] + graph_get_cost(graph,c,j);
            }
        }
    }
    k = set_destroy(k);
    return d;
}
