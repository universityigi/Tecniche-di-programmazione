#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


double product(float vec[], int n){
    if (n == 0)
        return 1;
    else
        return vec[0] * product(vec+1, n-1);
}

void vec_integral(float* v, int n){
    if (n == 1)
        *v += *(v-1);
    else{
        *v += *(v-1);
        vec_integral(v+1, n-1);
    }
        
}

int length(char * s){
    if (*s == '\0'){
        return 0;
    }
    else{
        return 1+length(s+1);
    }
}

int char_position1(char* s, char ch, int pos){
    if (s[pos] == '\0')
        return -1;
    else if (s[pos] == ch)
        return pos;
    else{
        return char_position1(s, ch, pos+1);
    }
}

int char_position(char* s, char ch){
    return char_position1(s, ch, 0);
}

void print_array(float* v, int n){
    if (n != 0) {
        printf("%lf ",v[0]);
        return print_array(v+1,n-1);
    }
}

bool is_lowercase(char *s){
    if (*s == '\0')
        return true;
    else if (*s >= 'a' && *s <= 'z')
        return is_lowercase(s+1);
    else
        return false;
}

void to_uppercase(char *s){
    if (*s == '\0')
        return;
    else if (*s >= 'a' && *s <= 'z'){
        *s = *s - 32;
        to_uppercase(s+1);
    }
    else
        to_uppercase(s+1);
}

void copy(char * dest, char * src){
    if (*src == '\0')   
        *dest = '\0';
    else{
        dest[0] = src[0];
        return copy(dest+1, src+1);
    }
}

void concat(char * dest, const char * src){
    if (*src == '\0')
        *dest  = '\0';
    else if (*dest == '\0'){
        *dest = *src;
        *(dest+1) = '\0';
        concat(dest+1, src+1);
    }
    else
        concat(dest+1, src);
}

int main(int argc, char** argv){
    float array[] = {1,10,3,4};
    char a[] = {'c','i','a','o','\0'};
    printf("PRODUCT = %lf\n",product(array, 4));
    printf("INTEGRAL = "); vec_integral(array, 4); print_array(array,4); printf("\n");
    printf("LENGHT = %d\n",length(a));
    printf("POSITION = %d\n",char_position(a,'!'));
    printf("LOWERCASE? = %d\n", is_lowercase(a));
    printf("TO_UPPER = ");to_uppercase(a);printf("%s\n",a);
    char* copia = (char*)malloc(256*sizeof(char));
    copy(copia, a);
    printf("copia = %s\n", copia);
    printf("lunghezza copia = %d\n", length(copia));
    concat(copia, a);
    printf("nuova copia = %s\n", copia);
    printf("lunghezza nuova copia = %d\n", length(copia));
    printf("Fine esercizio 1\n");
    return 0;
}
