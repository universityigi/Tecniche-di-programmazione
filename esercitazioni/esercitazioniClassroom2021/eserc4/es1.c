#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

void print_array (int v[], int dim);
void print_array_lf (double v[], int dim);

void random_array(int v[], int dim, int max_value);
double* vec_clone(const double v[], int dim);
void vec_scale(double v[], int dim, double scale);
int * numeri_unici(const int array[], int dim, int *output_dim);

int main(){
    int n = 5;
    int v[] = {0,0,0,0,0};
    random_array(v, n, 100);
    print_array(v, n);

    double vf[] = {1,2,3,4,5};
    vec_clone(vf,n);
    vec_scale(vf,n,3.5);
    print_array_lf(vf, n);

    int out = 0;
    n = 11;
    int array[] = {1,2,2,1,3,6,4,4,5,7,8};
    print_array(array, n);
    int* p = numeri_unici(array, n, &out);
    printf("numeri unici! "); print_array(p, out);
    return 0;
}

void print_array (int v[], int dim){
    for (int i = 0; i < dim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void print_array_lf (double v[], int dim){
    for (int i = 0; i < dim; i++){
        printf("%0.3lf ", v[i]);
    }
    printf("\n");
}

void random_array(int v[], int dim, int max_value){
    srand(time(0));
    for (int i = 0; i < dim; i++){
        v[i] = rand() % max_value;
    }
}

double* vec_clone(const double v[], int dim){
    double* clone = (double*)malloc(dim*sizeof(double));
    for (int i = 0; i < dim; i++){
        clone[i] = (double)v[i];
    }
    return clone;
}

void vec_scale(double v[], int dim, double scale){
    for (int i = 0; i < dim; i++){
        v[i]*= scale;
    }
}

int * numeri_unici(const int array[], int dim, int *output_dim) {
    int n = 1;
    int* unici = (int*) malloc(n*sizeof(int)); unici[0] = array[0];
    for (int i = 1; i < dim; i++){
        int nuovo_numero = 1;
        for (int j = 0; j<n; j++) {
            if (array[i] == unici[j]){
                nuovo_numero = 0;
                break;
            }
        }
        if(nuovo_numero){
            n++;
            unici = (int*)realloc(unici,(n)*sizeof(int)); unici[n-1] = array[i];
        }
    }
    *output_dim = n;
    return unici;
}