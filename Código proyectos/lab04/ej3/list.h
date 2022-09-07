#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct _Node * list;

typedef int list_elem;


/* Constructors */
list empty(void);
/*
    Crea una lista vacía.
*/

list addl(list l, list_elem e);
/*
    Agrega el elemento e al comienzo de la lista l. 
*/


/* Operations */
bool is_empty(list l);
/*
    Devuelve True si l es vacía
*/

list_elem head(list l);
/*
    Devuelve el primer elemento de la lista l
    PRECONDICION: !is_empty(l)
*/

list tail(list l);
/*
    Elimina el primer elemento de la lista l
    PRECONDICION: !is_empty(l)    
*/

list addr(list l, list_elem e);
/*
    Agrega el elemento e al final de la lista l.  
*/

unsigned int length(list l);
/*
    Devuelve la cantidad de elementos de la lista l.  
*/

list concat(list l, list l0);
/*
    Agrega al final de l todos los elementos de l0 en el mismo orden.
*/

list_elem index(list l, unsigned int n);
/*
    Devuelve el n-ésimo elemento de la lista l.
    PRECONDICION: length(l) > n  
*/

list take(list l, unsigned int n);
/*
    Deja en l sólo los primeros n elementos, eliminando el resto.
*/

list drop(list l, unsigned int n);
/*
    Elimina los primeros n elementos de l
*/

list copy_list(list l);
/*
    Copia todos los elementos de l en la nueva lista que se devuelve
*/

void destroy(list l);
/*
   Libera memoria en caso que sea necesario.
*/

#endif