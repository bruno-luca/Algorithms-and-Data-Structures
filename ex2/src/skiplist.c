#include "skiplist.h";

void new_skiplist(SkipList **list, size_t max_height, int (*compar)(const void *, const void *)){
    max_height = ((int)max_height <= 0) ? 1 : max_height;

    *list = malloc(sizeof(SkipList));
    (*list)->heads = malloc(max_height * sizeof(struct Node *));
    (*list)->compare = compar;
    (*list)->max_height = max_height;
    (*list)->max_level = 0;

    srand(time(NULL));
}

void clear_skiplist(SkipList **list){
    if(*list != NULL && *((*list)->heads) != NULL) clear_node(*((*list)->heads));
}

void clear_node(struct Node * n){
    if(n->next[0] != NULL) clear_node(n->next[0]);

    free(n->next);
    free(n);
}

void insert_skiplist(SkipList *list, void *item){
    struct Node* new = create_node(item, random_level(list->max_height));
    if(new->size > list->max_level) list->max_level = new->size;
    
    struct Node **hs = list->heads;
    for (int k = list->max_level-1; k >= 0; k--) {
        if (hs[k] == NULL || list->compare(new, hs[k]) < 0) {
            if (k < new->size) {
                new->next[k] = hs[k];
                hs[k] = new;
            }
        } else {
            hs = hs[k]->next;
            k++;
        }
    }
}

const void *search_skiplist(SkipList *list, void *item){
    struct Node ** heads = list->heads;
    struct Node *to_search = create_node(item, 0);
    
    for(int i = list->max_level -1; i >= 0; i--){
        while(heads[i]->next[i] != NULL && list->compare(heads[i]->next[i], to_search) <= 0){
            heads = heads[i]->next;
        }
    }

    if(list->compare(to_search, heads[0])==0) return heads[0]->item;
    else return NULL;
}

size_t random_level(size_t max_height){
    size_t lvl = 1;

    while((double)rand() / RAND_MAX < 0.5 && lvl < max_height) lvl++;

    return lvl;
}

struct Node * create_node(void * item, size_t size){
    struct Node * ret = malloc(sizeof(struct Node));

    ret->size = size;
    ret->next = malloc(sizeof(struct Node *) * size);
    ret->item = item;

    return ret;
}

void print_skiplist(SkipList *list) {
    struct Node **x = list->heads;
    while (x[0] != NULL) {
        printf("(%s, %d) \t ->  \t", (x[0]->item), x[0]->size);
        x = x[0]->next;
    }
    printf("\n\n");
}
