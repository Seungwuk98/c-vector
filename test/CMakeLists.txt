add_executable(${VECTOR_TEST} 
    vector_test.c
    )
add_executable(${VECTOR_CAPACITY_TEST}
    vector_capacity_test.c
    )


target_link_libraries(${VECTOR_TEST} PUBLIC ${VECTOR_LIBRARY})
target_link_libraries(${VECTOR_CAPACITY_TEST} PUBLIC ${VECTOR_LIBRARY})


add_test(NAME ${VECTOR_TEST} COMMAND VectorTest)
add_test(NAME ${VECTOR_CAPACITY_TEST} COMMAND VectorCapacityTest)