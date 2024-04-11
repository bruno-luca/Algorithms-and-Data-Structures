#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
#include <time.h>

int main(int argc, char *argv[]){
    
    char * recordsPath = argv[1];
    char * sortedRecordsPath = argv[2];
    int k = atoi(argv[3]);
    int field = atoi(argv[4]);

    FILE * input = fopen(recordsPath, "r");
    FILE * output = fopen(sortedRecordsPath, "w");

    printf("Running on:\t\n\t-infile:\t %s\n\t-outfile:\t %s\n\t-k:\t\t %d\n\t-field:\t\t %d\n", recordsPath, sortedRecordsPath, k, field);
    
    clock_t start = clock();
    sort_records(input, output, k, field);
    clock_t end = clock();

    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds", executionTime);


    // printf("Inizio procedura di testing...\n");
    // FILE *time_results = fopen("./data/time_analysis.csv", "w");
    // fprintf(time_results, "INPUT_DIMENSION,K_VALUE,TIME(seconds)");

    // for(int k = 0; k < 150; k++){
    //     clock_t inizio = clock();

    //     FILE * input = fopen(recordsPath, "r");
    //     FILE * output = fopen(sortedRecordsPath, "w");
        
    //     sort_records(input, output, k, 1);

    //     fclose(input);
    //     fclose(output);

    //     clock_t fine = clock();

    //     double tempo_impiegato = (double)(fine - inizio) / CLOCKS_PER_SEC;
    //     fprintf(time_results, "%d,%d,%f\n", INPUT_DIM, k, tempo_impiegato);

    //     printf("\nTest completed: %d/150 , total progress: %.2f%%", k+1, (float)(k*100)/150);
    // }

    // fclose(time_results);

    return 0;
}

