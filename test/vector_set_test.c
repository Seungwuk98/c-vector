#include "vector.h"
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main() {
    vector _vec;
    vector *vec = &_vec;
    init_vector(vec, sizeof(int));

    for (int i=0; i<10; ++i) {
        push_back_vector(vec, &i);
    }

    int data = 80;
    assert(set_vector(vec, 7, &data) == 0);
    data = 79;
    assert(get_vector(vec, 7, &data) == 0);
    assert(data == 80);

    assert(set_vector(vec, 10, &data) == EINVAL);

    close_vector(vec);
}