#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "skiplist.h"

int compare_string(const void *a, const void *b) {
    struct Node nA = *((struct Node*)a);
    struct Node nB = *((struct Node*)b);

    return strcasecmp(nA.item, nB.item);
}

int compare_int(const void *a, const void *b){
    struct Node nA = *((struct Node*)a);
    struct Node nB = *((struct Node*)b);

    if (*(int *)(nA.item) == *(int *)(nB.item)) return 0;
    else if (*(int *)(nA.item) < *(int *)(nB.item)) return -1;
    else return 1;
}

void find_errors(FILE *dictfile, FILE *textfile, size_t max_height){
    FILE * time_analisys = fopen("./data/time_analisys.csv", "a");
    float time_results[] = {0,0};
    clock_t start;
    SkipList *s;
    char *tmp;
    int i = 0;

    fprintf(time_analisys, "MAX_HEIGHT,LOAD_SKIPLIST,CORRECT_SKIPLIST\n");

    new_skiplist(&s,max_height, compare_string);
    start = clock();
    for(get_word(&dictfile, &tmp); tmp != NULL; get_word(&dictfile, &tmp)){
        insert_skiplist(s,tmp);
        if(i%1000 == 0)printf("[%d][%.3f%%]Loading...\n", max_height, (i*100)/661000.0); // i : x = 662000 : 100
        i++;
    }
    time_results[0] = (double)(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    for(get_word(&textfile, &tmp); tmp != NULL; get_word(&textfile, &tmp)){
        if(search_skiplist(s,tmp) == NULL){
            printf("\t- %s\n", tmp);
        }
    }
    time_results[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
    //MAX_HEIGHT,LOAD_SKIP_LIST(seconds),CORRECT_SKIPLIST(seconds)
    fprintf(time_analisys, "%d,%f,%f\n", max_height, time_results[0], time_results[1]);
    clear_skiplist(&s);
    fclose(time_analisys);
}

void get_word(FILE  **file, char  **word){
    char ch;
    int length = 0, found_word = 0;
    
    while(!found_word){
        ch = fgetc(*file);
        length ++;
        if(ch == EOF){
            length--;
                if(length > 0){
                    fseek(*file, -(length), SEEK_CUR);
                    *word = malloc(sizeof(char) * length);
                    fread(*word, sizeof(char), length, *file);

                }else {
                    *word = NULL;
                }
                found_word = 1;
        }else if(!is_char(ch)){
            length--;
                if(length > 0){
                    
                    fseek(*file, -(length+1), SEEK_CUR);
                    *word = malloc(sizeof(char) * length);
                    fread(*word, sizeof(char), length, *file);
                    fseek(*file, 1, SEEK_CUR);

                    found_word = 1;
                }
        }
    }
}

bool is_char(char c){
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
