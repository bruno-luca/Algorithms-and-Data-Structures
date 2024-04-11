#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct Node{
    struct Node **next;
    size_t size;
    void *item;
};

typedef struct skipList{
    struct Node **heads;
    size_t max_level;
    size_t max_height;
    int (*compare)(const void *, const void *);
}SkipList;

/**
 * @brief Create a new skiplist
 * 
 * Create a new skiplist into list, with max height = max_heigh and a custom 
 * comparator for the elements stored in the list.
 * 
 * @param list Pointer to the pointer to the skiplist 
 * @param max_height Max height value
 * @param compar Custom comparator
 */
void new_skiplist(SkipList **list, size_t max_height, int (*compar)(const void*, const void*));

/**
 * @brief Clear the skiplist
 * 
 * Deallocate all nodes inside the skiplist
 * 
 * @param list Pointer to the pointer to the skiplist 
 */
void clear_skiplist(SkipList **list);

/**
 * @brief Insert a element in the skiplist
 * 
 * @param list Pointer to the skiplist
 * @param item Pointer to the item to be inserted
 */
void insert_skiplist(SkipList *list, void *item);

/**
 * @brief Search a element inside a skiplist
 * 
 * Return the pointer of the element in the skiplist if its present,
 * NULL otherwise
 * 
 * @param list Pointer to the skiplist
 * @param item Pointer to the item to be seek
 */
const void* search_skiplist(SkipList *list, void *item);

/**
 * @brief Randomize heigh of a skiplist's node
 * 
 * Randomize the height of a node following a bernoullian test
 * 
 * @param max_height Max height value of the skiplist
 */
size_t random_level(size_t max_height);

/**
 * @brief Create a node of a skiplist
 * 
 * Return a pointer to a node of a skiplist containint item and
 * height equal to size.
 * 
 * @param item Generic pointer to the item to be stored in the skiplist
 * @param size Height of the node
 */
struct Node * create_node(void * item, size_t size);

/**
 * @brief Clear a node of the skiplist
 * 
 * @param n Pointer to the node to be cleared
 */
void clear_node(struct Node * n);

/**
 * @brief Print the skiplist
 * 
 * @param list Pointer to the skiplist
 */
void print_skiplist(SkipList *list);