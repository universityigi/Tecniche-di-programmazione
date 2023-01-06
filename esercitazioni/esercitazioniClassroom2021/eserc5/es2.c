#include "f.h"

void sort_strings(char **array){
    int i = 0;
    while (array[i] != NULL){
        if (array[i+1] != NULL && strlen(array[i]) > strlen(array[i+1])){
            char* tmp = array[i+1];
            array[i+1] = array[i];
            array[i] = tmp;
            i = 0;
        }
        else{i++;};
    }
}

void print_array(char** array){
    int i = 0;
    while (array[i] != NULL){
        printf("%s\n",array[i]);
        i++;
    }
}

