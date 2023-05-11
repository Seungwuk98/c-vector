#include "vector.h"
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int main() {
    vector _vec;
    vector *vec = &_vec;
    init_vector(vec, sizeof(int));

    for (int i=0; i<10; ++i) {
        push_back_vector(vec, &i);
    }

    for (int i=0; i<10; ++i) {
        int data;
        get_vector(vec, i, &data);
        assert(data == i);
    }
    int data;
    int err = get_vector(vec, 10, &data);
    assert(err == EINVAL);
    err = get_vector(vec, -1, &data);
    assert(err == EINVAL);

    close_vector(vec);
}