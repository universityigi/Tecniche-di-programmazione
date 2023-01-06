#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef float TipoInfoSCL;

struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void scl_make(TipoSCL* scl, int n, TipoInfoSCL e);
void scl_print(TipoSCL scl);

int scl_len(TipoSCL scl);
float scl_sum(TipoSCL scl);
float scl_media(TipoSCL scl);
float scl_dot(TipoSCL scl1, TipoSCL scl2);
void scl_duplicate_pos(TipoSCL scl, int pos);
TipoSCL scl_positives(TipoSCL scl);

int main(){
    TipoSCL scl1;
    scl_make(&scl1, 5, -2);
    scl_print(scl1);
    printf("LEN = %d\n", scl_len(scl1));
    printf("SUM = %f\n",scl_sum(scl1));
    printf("MED = %f\n",scl_media(scl1));
    TipoSCL scl2; scl_make(&scl2, 5, 10);
    printf("PROD = %f\n", scl_dot(scl1,scl2));
    scl_duplicate_pos(scl2, 3); scl_print(scl2);
    TipoSCL scl3 = scl_positives(scl1); scl_print(scl3);
    return 0;
}

void scl_make (TipoSCL* scl, int n, TipoInfoSCL e){
    if (n == 0) *scl = NULL;
    else {
        *scl = (TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
        (*scl)->info = e;
        scl_make(&((*scl)->next), n-1, e+2);
    }
}

void scl_print(TipoSCL scl){
    if (scl == NULL) printf("\n");
    else{
        printf("%f ", scl->info);
        scl_print(scl->next);
    }
}

int scl_len(TipoSCL scl){
    if (scl == NULL)
        return 0;
    else 
        return 1 + scl_len(scl->next);
}

float scl_sum(TipoSCL scl){
    if (scl == NULL)
        return 0;
    else {
        return scl->info + scl_sum(scl->next);
    }
}

float scl_media(TipoSCL scl){
    if (scl == NULL) return 0;
    else
    {
        float c = scl->info + scl_sum(scl->next);
        return c / scl_len(scl);
    }
}

float scl_dot(TipoSCL scl1, TipoSCL scl2){
    if (scl1 == NULL) return 0;
    else return (scl1->info * scl2->info) + scl_dot(scl1->next, scl2->next);
}

void scl_duplicate_pos(TipoSCL scl, int pos){
    if (pos == 0){
        TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        temp->info = scl->info;
        temp->next = scl->next;
        scl->next = temp;
    }
    else scl_duplicate_pos(scl->next, pos-1);
}

TipoSCL scl_positives(TipoSCL scl){
    if (scl == NULL) return NULL;
    else if (scl->info >= 0){
        TipoSCL new = (TipoSCL)malloc(sizeof(TipoNodoSCL));
        new->info = scl->info;
        new->next = scl_positives(scl->next);
        return new;
    }
    else scl_positives(scl->next);
}

