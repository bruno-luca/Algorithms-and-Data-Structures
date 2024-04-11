#include "sorting.h"
#include "utils.h"

int compare_int(const void *a, const void *b) { 
    Record rA = *((Record*)a); 
    Record rB = *((Record*)b);

    if (rA.field3 == rB.field3) return 0;
    else if (rA.field3 > rB.field3) return -1;
    else return 1;
}

int compare_string(const void *a, const void *b) {
    Record rA = *((Record*)a);
    Record rB = *((Record*)b);

    return strcmp(rA.field2, rB.field2);
}

int compare_float(const void *a, const void *b) {
    Record rA = *((Record*)a);
    Record rB = *((Record*)b);

    if (rA.field4 == rB.field4) return 0;
    else if (rA.field4 > rB.field4) return -1;
    else return 1;
}

void load_csv(FILE *input_file, Record *array){
    if (input_file != NULL){
        char *line = NULL;
        char *token;

        int i = 0;
        size_t pFile = 0;

        while ((getline(&line, &pFile, input_file)) != -1 && i < INPUT_DIM){
            token = strtok(line, ",");
            array[i].field1 = atoi(token);

            token = strtok(NULL, ",");
            array[i].field2 = malloc(sizeof(char) * strlen(token));
            strcpy(array[i].field2, token);

            token = strtok(NULL, ",");
            array[i].field3 = atoi(token);

            token = strtok(NULL, ",");
            array[i].field4 = atof(token);

            i++;
        }  
    }
}

void sort_records(FILE *infile, FILE *outfile, size_t k, size_t field){
    if(k<0 || !(field >= 1 && field <= 3)) exit(1);

    Record *array = malloc(sizeof(Record) * INPUT_DIM);    
    load_csv(infile, array);

    switch(field){
        case 1:
            merge_binary_insertion_sort(array, INPUT_DIM, sizeof(Record), k, compare_string);
            break;
        case 2:
            merge_binary_insertion_sort(array, INPUT_DIM, sizeof(Record), k, compare_int);
            break;
        case 3:
            merge_binary_insertion_sort(array, INPUT_DIM, sizeof(Record), k, compare_float);
            break;
        default:
            break;
    }

    for(int i = 0; i < INPUT_DIM; i++){
        fprintf(outfile, "%d,%s,%d,%f\n", array[i].field1, array[i].field2, array[i].field3, array[i].field4);
    }
}


