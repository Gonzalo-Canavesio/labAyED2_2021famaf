#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    bool invariante = true;
    if(tree != NULL){
        if (tree->left != NULL){
            invariante &= elem_less(tree->left->elem,tree->elem);
        }
        if(tree->right != NULL){
            invariante &= elem_less(tree->elem,tree->right->elem);
        }       
        invariante &= invrep(tree->left) && invrep(tree->right);  
    }
    return invariante;
}

abb abb_empty(void) {
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if(tree == NULL){
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if(!elem_eq(e,tree->elem)){
            if(elem_less(e, tree->elem)){
                tree->left = abb_add(tree->left,e);
            } else {
                tree->right = abb_add(tree->right,e);
            }
        }
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = tree == NULL;
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    abb p = tree;
    if(p != NULL){
        exists = tree->elem == e || abb_exists(tree->left, e) || abb_exists(tree->right, e);
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if(! abb_is_empty(tree)){
        length += abb_length(tree->left) + abb_length(tree->right) + 1;
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if(tree != NULL){
        if(elem_less(e,tree->elem)){
            tree->left = abb_remove(tree->left,e);
        } else if(elem_less(tree->elem,e)){
            tree->right = abb_remove(tree->right,e);
        } else {
                abb temp = NULL;
            if (tree->left == NULL) {
                temp = tree;
                tree = tree->right;
                free(temp);
            } else if (tree->right == NULL) {
                temp = tree;
                tree = tree->left;
                free(temp);
            } else {
                temp = tree->right;
                while(temp && temp->left != NULL){
                    temp = temp->left;
                }

                tree->elem = temp->elem;
                tree->right = abb_remove(tree->right,temp->elem);
            }
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb p = tree;
    while(p->right != NULL){
        p = p->right;
    }
    max_e = p->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb p = tree;
    while(p->left != NULL){
        p = p->left;
    }
    min_e = p->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if(! abb_is_empty(tree)){
        abb_destroy(tree->right);
        abb_destroy(tree->left);
        free(tree);
    }
    tree = NULL;
    assert(tree == NULL);
    return tree;
}

