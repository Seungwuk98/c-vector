#include "vector.h"
#include <unistd.h>
#include <assert.h>

int main() {
    vector _vec;
    vector *vec = &_vec;
    init_vector(vec, sizeof(int));

    int data = 1;
    push_back_vector(vec, &data);
    
    data = 2;
    push_back_vector(vec, &data);
    
    assert(*(int *)back_vector(vec) == 2);
    assert(pop_back_vector(vec) != NULL);
    assert(*(int *)back_vector(vec) == 1);
    assert(pop_back_vector(vec) != NULL);
    assert(back_vector(vec) == NULL);
    assert(pop_back_vector(vec) == NULL);    

    close_vector(vec);
    return 0;
}