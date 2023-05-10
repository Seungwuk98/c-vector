#ifndef __VECTOR_H__
#define __VECTOR_H__
#define INITIAL_CAPCACITY 10

typedef struct _vector {
    int _cap;
    int _size;
    int _word;
    void *_table;
} vector;

void init_vector(vector *vec, int word_size);
void init_with_initial_capacity(vector *vec, int word_size, int capacity);
void close_vector(vector *vec);
void get_vector(vector *vec, int idx, void *ret);
void set_vector(vector *vec, int idx, void *data);
void push_back_vector(vector *vec, void *data);
void *pop_back_vector(vector *vec);
void *back_vector(vector *vec);
int size_vector(vector *vec);
void clear_vector(vector *vec);
int empty_vector(vector *vec);

#endif