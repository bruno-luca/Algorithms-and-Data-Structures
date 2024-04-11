#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INPUT_DIM 10000000
/**
 * @brief Struct representing a csv recod
 * 
 * Represent a csv recordwith the followinf format (int, string, int, float)
 *
 */
typedef struct record{
    int field1;
    char *field2;
    int field3;
    float field4;
} Record;

/**
 * @brief Load csv file into array
 * 
 * Load all csv lines into array
 * 
 * @param input_file Pointer to input file
 * @param array Pointer to Record array
 *
 */
void csv_to_array(FILE *input_file, Record *array);

/**
 * @brief Sort array
 * 
 * Sort all elements inside ordering by specified param
 * 
 * @param infile Pointer to input file
 * @param outfile Pointer to Record array
 * @param k Threshold for BinaryInsertion Sort usage.
 * @param field Wich field use to sort records
 *
 */
void sort_records(FILE *infile, FILE *outfile, size_t k, size_t field);

/**
 * @brief Compare function for integers
 * 
 * Return <0 if a <b, 0 if a == b, >0 if a>b
 * 
 * @param a First element to be compared
 * @param b Second element to be compared
 */
int compare_int(const void *a, const void *b);

/**
 * @brief Compare function for floats
 * 
 * Return <0 if a <b, 0 if a == b, >0 if a>b
 * 
 * @param a First element to be compared
 * @param b Second element to be compared
 */
int compare_float(const void *a, const void *b);

/**
 * @brief Compare function for strings
 * 
 * Return <0 if a <b, 0 if a == b, >0 if a>b
 * 
 * @param a First element to be compared
 * @param b Second element to be compared
 */
int compare_string(const void *a, const void *b);
