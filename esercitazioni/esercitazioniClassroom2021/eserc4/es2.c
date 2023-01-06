#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dichiarazione delle funzioni
int find_index(const char s[], const char compare);
void print_chars(const char s[], const int idxs[], int dim);
char* select_chars(const char s[], const int idxs[], int dim);
char* invert_string(const char s[]);
char* mocking_spongebob(const char s[], int step);
char* capitalizer(const char s[]);


int main(int argc, char* argv[]){
    int n = 5;
    int indici[] = {12,17,5,1,7};
    char* p = "Non puoi insegnare tdp con i meme";
    printf("STRINGA:\t%s\n",p);
    printf("LEN_STRINGA:\t%d\n", strlen(p));
    printf("STRINGA_PRINT:\t");print_chars(p, indici, n);
    printf("STRINGA_PTR:\t%s\n",select_chars(p,indici,n));
    printf("STRINGA_INV:\t%s\n",invert_string(p));
    printf("SPONGEBOB:\t%s\n",mocking_spongebob(p,2));
    printf("CAPITALIZER:\t%s\n",capitalizer(p));
    return 0;
}


int find_index(const char s[], const char compare){
    int found = -1;
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] == compare) {
            found = i;
            return found;
        }
        i++;
    }
    return found;
}

void print_chars(const char s[], const int idxs[], int dim){
    for (int i = 0;i<dim;i++){
        if (idxs[i] < strlen(s)){
            printf("%c",s[idxs[i]]);
        }
    }
    printf("\n"); 
}

char* select_chars(const char s[], const int idxs[], int dim){
    int n = 1;
    char* string = (char*)malloc(n*sizeof(char));
    for (int i = 0;i<dim;i++){
        if (idxs[i] < strlen(s)){
            string = (char*)realloc(string,(n+1)*sizeof(char));
            string[n-1] = s[idxs[i]];
        }
        n++;
        string[n-1] = '\0';
    }
    return string;
}

char* invert_string(const char s[]){
    size_t n = strlen(s);
    char* char_inv = (char*) malloc(n*sizeof(char));
    char_inv[n] = '\0';
    for (int i = 0; i < n; i++){
        char_inv[i] = s[n-i-1];
    }
    return char_inv;
}

char * mocking_spongebob(const char s[], int step){
    size_t n = strlen(s);
    char* maiusc = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char* minusc = "qwertyuiopasdfghjklzxcvbnm";
    char* memino = (char*) malloc((n+1)*sizeof(char));
    memino[n-1] = '\0';
    for (int i = 0; i < n; i++){
        if (find_index(minusc, s[i]) != -1 && i % step == 0){
            int indice = find_index(minusc, s[i]);
            memino[i] = maiusc[indice];
        }
        else {memino[i] = s[i];}
    }
    return memino;
}

char* capitalizer(const char s[]){
    size_t n = strlen(s);
    char* cap = (char*) malloc(n+1);
    int to_capitalize = 1;
    char* maiusc = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char* minusc = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i<n; i++){
        if (to_capitalize){
            int ind = find_index(maiusc, s[i]) != -1 ? find_index(maiusc, s[i]) : find_index(minusc, s[i]);
            cap[i] = maiusc[ind];
            to_capitalize = 0;
        }
        else if (s[i] == ' '){
            to_capitalize = 1;
            cap[i] = ' ';
        }
        else {
            int ind = find_index(minusc, s[i]) != -1 ? find_index(minusc, s[i]) : find_index(maiusc, s[i]);
            cap[i] = minusc[ind];
        }
    }
    cap[n] = '\0';
    return cap;
}