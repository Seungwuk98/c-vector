#include "vector.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void init_with_initial_capacity(vector *vec, int word_size, int capacity) {
    vec->_cap = capacity;
    vec->_word = word_size;
    vec->_size = 0;
    vec->_table = malloc(word_size * capacity);
}

void init_vector(vector *vec, int word_size) {
    init_with_initial_capacity(vec, word_size, INITIAL_CAPCACITY);
}

void close_vector(vector *vec) {
    free(vec->_table);
}

void get_vector(vector *vec, int idx, void *ret) {
    if (idx < 0 || idx >= size_vector(vec)) {
        fprintf(stderr, "[ %d :: %lu ] Invalid Index Used, vector-size : %d, index : %d", __FILE__, __LINE__, size_vector(vec), idx);
        exit(1);
    }    
    int word_size = vec->_word;
    memcpy(ret, vec->_table + (word_size * idx), word_size);
}

void set_vector(vector *vec, int idx, void *ret) {
    if (idx < 0 || idx >= size_vector(vec)) {
        fprintf(stderr, "[ %d :: %lu ] Invalid Index Used, vector-size : %d, index : %d", __FILE__, __LINE__, size_vector(vec), idx);
        exit(1);
    }    
    int word_size = vec->_word;
    memcpy(vec->_table + (word_size + idx), ret, word_size);
}

void overflow_vector(vector *vec) {
    int new_cap = vec->_cap << 1;
    int word_size = vec->_word;
    void *new_table = malloc(new_cap * word_size);

    memcpy(new_table, vec->_table, word_size * vec->_cap);
    free(vec->_table);
    vec->_table = new_table;
    vec->_cap = new_cap;
}

void push_back_vector(vector *vec, void *ret) {
    if (vec->_cap == vec->_size) {
        overflow_vector(vec);
    }
    
    int word_size = vec->_word;
    memcpy(vec->_table + (vec->_size * word_size), ret, word_size);
    vec->_size ++;
}

void *pop_back_vector(vector *vec) {
    if (empty_vector(vec)) {
        fprintf(stderr, "[ %d :: %lu ] Invalid Index Used, vector is empty. Can't find back", __FILE__, __LINE__);
        exit(1);
    }
    return (vec->_table + (vec->_word * (--vec->_size)));
}

void *back_vector(vector *vec) {
    if (empty_vector(vec)) {
        fprintf(stderr, "[ %d :: %lu ] Invalid Index Used, vector is empty. Can't find back", __FILE__, __LINE__);
        exit(1);
    }
    return vec->_table + (vec->_size - 1) * vec->_word;
}

int size_vector(vector *vec) {
    return vec->_size;
}

void clear_vector(vector *vec) {
    free(vec->_table);
}

int empty_vector(vector *vec) {
    return size_vector(vec) == 0;
}







