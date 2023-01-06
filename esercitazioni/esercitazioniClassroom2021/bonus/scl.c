#include <stdio.h>
#include <stdlib.h>

void sostituisci_numeri (TipoSCL *list, const char* s);

int main(){

}

void sostituisci_numeri (TipoSCL *list, const char* s){
    if (*list == NULL) return;
    else{
        if ('0' <= (*list)->info <= '9'){
            TipoSCL sost = (TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
            TipoSCL to_del = *list;
            sost -> info = *s;
            sost -> next =  (*list)-> next;
            *list = new;
            free(to_del);
        }
        (TipoSCL (*list)->next, const char* s);
    }
}

