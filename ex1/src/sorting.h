#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Merge-BinaryInsertion Sort algorithm.
 * 
 * Performs a hybrid sorting algorithm combining Merge Sort and BinaryInsertion Sort.
 *
 * @param base    Pointer to the first element of the array to be sorted.
 * @param nitems  Total number of elements in the array.
 * @param size    Size in bytes of each element.
 * @param k       Threshold for BinaryInsertion Sort usage.
 * @param compar  Comparison function taking two pointers to elements and returning
 *                a negative integer if the first element is smaller, a positive integer
 *                if the second element is smaller, and zero if they are equal.
 */
void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void*, const void*));

/**
 * @brief Merge function for Merge Sort algorithm
 * 
 * @param base Pointer to the first element of the array to be merged.
 * @param size Total number of elements in the array.
 * @param compar Comparison function taking two pointers to elements and returning
 *               a negative integer if the first element is smaller, a positive integer
 *               if the second element is smaller, and zero if they are equal.
 * @param l Left index
 * @param m Middle index
 * @param r Right index
 */
void merge(void *base, size_t size, int (*compar)(const void*, const void*), int l, int m, int r);

/**
 * @brief Merge Sirt Algorithm
 * 
 * @param base Pointer to the first element of the array to be merged.
 * @param size Total number of elements in the array.
 * @param compar Comparison function taking two pointers to elements and returning
 *               a negative integer if the first element is smaller, a positive integer
 *               if the second element is smaller, and zero if they are equal.
 * @param l Left index
 * @param k Threshold for BinaryInsertion Sort usage.
 * @param r Right index
 */
void merge_sort(void *base, size_t size, int (*compar)(const void*, const void*), int l, int r, size_t k);

/**
 * @brief Binary-Insertion sort algorithm.
 * 
 *  Perform Insertion Sort algorithm mixed with binary search for the position of where the item should 
 *  be put.
 * 
 * @param base Pointer to the array.
 * @param nitems Total number of elements in the array.
 * @param size Size in bytes of each element.
 * @param compar Comparison function taking two pointers to elements and returning
 *                a negative integer if the first element is smaller, a positive integer
 *                if the second element is smaller, and zero if they are equal.
 */
void binary_insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
