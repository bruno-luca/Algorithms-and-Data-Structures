#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/**
 * @brief Compare function for strings
 * 
 * Return <0 if a <b, 0 if a == b, >0 if a>b
 * 
 * @param a First element to be compared
 * @param b Second element to be compared
 */
int compare_string(const void *a, const void *b);

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
 * @brief Find errors inside a text file
 * 
 *  Load dictfile inside a skiplist, then 
 *  read textfile word by word and print the ones that are not contained in the skiplist
 * 
 * @param dictfile Pointer to dictfile to be load in the skiplist
 * @param textfile Pointer to file to correct
 * @param max_height Max height of the skiplist
 */
void find_errors(FILE *dictfile, FILE *textfile, size_t max_height);

/**
 * @brief Read a word from a file
 * 
 * Read a word from the given file. A word is defined as a sequence of characters a-zA-Z 
 * 
 * @param file File from which to read the word
 * @param word Pointer to the variable where to save the word
 */
void get_word(FILE ** file, char ** word);

/**
 * @brief Check if given char is in a-zA-Z bound
 * 
 * Return true if the char is in a-zA-Z bound
 * 
 * @param c Character
 */
bool is_char(char c);
