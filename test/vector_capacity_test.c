#include <assert.h>
#include "vector.h"

int main() {
    vector _vec;
    void *vec = (void *)&_vec;
    init_with_initial_capacity(vec, sizeof(int), 2);

    for (int i=0; i<200; ++i) {
        push_back_vector(vec, &i);
    }

    assert(((vector *)vec)->_cap == 256);
    close_vector(vec);
}