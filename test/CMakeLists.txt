add_executable(${VECTOR_TEST} 
    vector_test.c
    )
add_executable(${VECTOR_CAPACITY_TEST}
    vector_capacity_test.c
    )
add_executable(${VECTOR_BACK_TEST}
    vector_back_test.c
    )
add_executable(${VECTOR_GET_TEST}
    vector_get_test.c
    )
add_executable(${VECTOR_SET_TEST}
    vector_set_test.c
    )


target_link_libraries(${VECTOR_TEST} PUBLIC ${VECTOR_LIBRARY})
target_link_libraries(${VECTOR_CAPACITY_TEST} PUBLIC ${VECTOR_LIBRARY})
target_link_libraries(${VECTOR_BACK_TEST} PUBLIC ${VECTOR_LIBRARY})
target_link_libraries(${VECTOR_GET_TEST} PUBLIC ${VECTOR_LIBRARY})
target_link_libraries(${VECTOR_SET_TEST} PUBLIC ${VECTOR_LIBRARY})

add_test(NAME ${VECTOR_TEST} COMMAND VectorTest)
add_test(NAME ${VECTOR_CAPACITY_TEST} COMMAND VectorCapacityTest)
add_test(NAME ${VECTOR_BACK_TEST} COMMAND VectorBackTest)
add_test(NAME ${VECTOR_GET_TEST} COMMAND VectorGetTest)
add_test(NAME ${VECTOR_SET_TEST} COMMAND VectorSetTest)