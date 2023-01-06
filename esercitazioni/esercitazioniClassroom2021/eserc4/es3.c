#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** read_lines(const char filepath[], int *lines_n);

int main(int argc, char* argv[]){
    int ln;
    char** lines = read_lines(".\\test.txt", &ln);
    for (int i = 0; i < ln; i++){
        printf("%s",lines[i]);
    }
    return 0;
}

char ** read_lines(const char filepath[], int *lines_n){
    FILE* file = fopen(filepath, "r");
    if (file == NULL){
        printf("Errore nell'apertura file (controllare PATH)");
        exit(1);
    }
    fscanf(file,"%d",lines_n);
    fgetc(file);        //svuota stdin dal carattere a capo
    char** lines = (char**)malloc(*lines_n * sizeof(char*));
    for (int index=0;index<*lines_n;++index){
        lines[index] = (char*)malloc(80 * sizeof(char));
    }
    for (int i = 0; i < *lines_n; i++){
        lines[i];
        char* a = fgets(lines[i],80,file);
    }
    fclose(file);
    return lines;
}