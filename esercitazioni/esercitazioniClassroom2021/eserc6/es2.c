#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void filter_write(char * message, FILE * file);
bool same_content(FILE *f1, FILE *f2);


int main(){
    FILE* file1 = fopen("./file1.txt","w");
    if (file1 == NULL)
        exit (1);
    FILE* file2 = fopen("./file2.txt","a");
    if (file2 == NULL)
        exit (1);
    char* message = "Ciao! come stai? Io tutto a posto";
    filter_write(message, file1);
    filter_write(message, file2);
    fclose(file1);
    fclose(file2);
    FILE* f1 = fopen("./file1.txt","r");
    if (f1 == NULL)
        exit (1);
    FILE* f2 = fopen("./file2.txt","r");
    if (f2 == NULL)
        exit (1);
    printf("SAME? = %d\n", same_content(f1, f2));
    return 0;

}

void filter_write(char * message, FILE * file){
    if (*message == '\0')
        return;
    else if ((int) *message >= 97 && (int) *message <= 122)
        fprintf(file, "%c", *message);
    return filter_write(message+1, file);
}

bool same_content(FILE *f1, FILE *f2){
    char c1 = fgetc(f1);
    char c2 = fgetc(f2);
    printf("%c uguale a %c\n",c1,c2);
    if (c1 == EOF && c2 == EOF)
        return true;
    else if (c1 == c2)
        return true && same_content(f1, f2);
    else
     return false;
}