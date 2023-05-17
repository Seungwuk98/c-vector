#include <assert.h>
#include <stdio.h>
#include "vector.h"
#define TEST_SIZE 200

int main() {
    vector _vec;
    void *vec = (void *)&_vec;
    init_vector(vec, sizeof(int));

    printf("vector size : %d\n", sizeof(vector));

    for (int i=0; i<TEST_SIZE; ++i) {
        push_back_vector(vec, &i);
    }    

    for (int i=0; i<TEST_SIZE; ++i) {
        int data;
        get_vector(vec, i, &data);
        printf("%d\n", data);
    }
    
    close_vector(vec);
}