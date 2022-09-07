#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    bool invariante = true;
    if(d != NULL){
        if (d->left != NULL){
            invariante &= key_less(d->left->key,d->key);
        }
        if(d->right != NULL){
            invariante &= key_less(d->key,d->right->key);
        }       
        invariante &= invrep(d->left) && invrep(d->right);  
    }
    return invariante;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if(dict == NULL){
        dict = malloc(sizeof(struct _node_t));
        dict->key = string_clone(word);
        dict->value = string_clone(def);
        dict->left = NULL;
        dict->right = NULL;
    } else {
        if(!key_eq(word,dict->key)){
            if(key_less(word,dict->key)){
                dict->left = dict_add(dict->left,word,def);
            } else {
                dict->right = dict_add(dict->right,word,def);
            }
        } else {
            value_t aux = dict->value;
            dict->value = string_clone(def);
            key_destroy(aux);
        }
    }
    assert(invrep(dict) && key_eq(def, dict_search(dict,word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    assert(invrep(dict));
    if( dict != NULL){
        if(key_eq(dict->key,word)){
            def = dict->value;
        } else {
            if(key_less(dict->key,word)){
                def = dict_search(dict->right,word);
            } else {
                def = dict_search(dict->left,word);
            }
        }
    }
    assert((def != NULL) == dict_exists(dict,word));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists=false;
    assert(invrep(dict));
    dict_t aux = dict;
    while(!exists && aux != NULL){
        if(key_less(word, aux->key)){
            aux = aux->left;
        } else if(key_less(aux->key,word)){
            aux = aux->right;
        } else {
            exists = true;
        }
    }
    assert(invrep(dict));
    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0;
    assert(invrep(dict));
    if(dict != NULL){
        length += dict_length(dict->left) + dict_length(dict->right) + 1;
    }
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(invrep(dict));
    if(dict != NULL){
        if(key_less(word,dict->key)){
            dict->left = dict_remove(dict->left,word);
        } else if(key_less(dict->key,word)){
            dict->right = dict_remove(dict->right,word);
        } else {
                dict_t temp = NULL;
            if (dict->left == NULL) {
                temp = dict;
                dict = dict->right;
                free(temp);
            } else if (dict->right == NULL) {
                temp = dict;
                dict = dict->left;
                free(temp);
            } else {
                temp = dict->right;
                while(temp && temp->left != NULL){
                    temp = temp->left;
                }

                dict->key = temp->key;
                dict->right = dict_remove(dict->right,temp->key);
            }
        }
    }
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if( dict != NULL ) {
      dict_remove_all(dict->left);
      dict_remove_all(dict->right);
      value_destroy(dict->value);
      key_destroy(dict->key);
      free(dict);
      dict = NULL;
    }
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict) && file != NULL);
    if (dict != NULL) {
        dict_dump(dict->left, file);
        key_dump(dict->key, file);
        fprintf(file, ":");
        key_dump(dict->value, file);
        fprintf(file, "\n");
        value_dump(dict->value, file);
        dict_dump(dict->right, file);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    if(dict != NULL){
        dict_destroy(dict->right);
        dict_destroy(dict->left);
        key_destroy(dict->key);
        value_destroy(dict->value);
        free(dict);
    }
    dict = NULL;
    assert(dict == NULL);
    return dict;
}

