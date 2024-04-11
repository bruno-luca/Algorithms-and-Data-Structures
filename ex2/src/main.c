#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "skiplist.h"

int main(int argc, char *argv[]){

    char * dictPath = argv[1];
    char * correctPath = argv[2];
    int maxHeight = atoi(argv[3]);

    FILE * dictFile = fopen(dictPath, "r");
    FILE * correctFile = fopen(correctPath, "r");
    
    clock_t start = clock();
    find_errors(dictFile, correctFile, maxHeight);
    clock_t end = clock();

    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds", executionTime);

    // FILE *time_results = fopen("./data/time_analysis.csv", "w");

    // for(int i = 1; i < 150; i++){
    //     FILE * fin = fopen("./data/correctme.txt", "r");
    //     FILE * dict = fopen("./data/dictionary.txt", "r");
        
    //     find_errors(dict, fin,i);

    //     fclose(fin);
    //     fclose(dict);
    // }

    return 0;
}
