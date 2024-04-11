#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unity.h"
#include "sorting.h"
#include "utils.h"


 // Define your test data
int* data[6];
int expected[] = {1, 2, 3, 4, 5, 18};
int ahahah[] = {18, 5, 4,3 ,2 ,1 };
size_t nitems = 6;
size_t size = sizeof(int);
int k = 21;
int true = 1;

void setUp() {
     // Riempi l'array con gli elementi desiderati
    for (size_t i = 0; i < nitems; ++i) {
        data[i] = malloc(sizeof(int));
        *data[i] = ahahah[i];  // Assegna gli elementi desiderati
    }
}

void tearDown() {
    true = 1;
}

void test_merge_binary_insertion_sort() {

    // Call the function
    merge_binary_insertion_sort(data,nitems,size,k,compare_int);

    for (size_t i = 0; i < nitems; ++i) {
        if (*data[i] != expected[i])
        {
            true = 0;
        } 
    }

    TEST_ASSERT_EQUAL_INT(1, true);

}

void test_merge_sort(){

    // Call the function
    merge_sort(data, size, compare_int, 0, nitems - 1, k);

    for (size_t i = 0; i < nitems; ++i) {
        if (*data[i] != expected[i])
        {
            true = 0;
        } 
    }

    TEST_ASSERT_EQUAL_INT(1, true);
}

// Add more test functions for other functions if needed

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_merge_sort);
    RUN_TEST(test_merge_binary_insertion_sort);
    

    return UNITY_END();
}
