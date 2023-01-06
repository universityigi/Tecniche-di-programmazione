#include "f.h"

int main(int argc, char** argv){
    //es1
    printf("\n\nINIZIO ESERCIZIO 1\n\n");
    Mat* m = mat_alloc(2,2);
    for (int i = 0; i < m->rows; i++){
        for (int j = 0; j < m->cols;j++){
            m->rows_pt[i][j] = i+(j*m->cols);
        }
    }
    mat_print(m);
    Mat* m1 = mat_clone(m);
    mat_print(m1);
    printf("simmetrica? %d\n\n",mat_is_symmetric(m1));
    mat_normalize_rows(m1);
    mat_print(m1);
    Mat* sum = mat_sum(m, m);
    if (sum != NULL) mat_print(sum);
    Mat* prod = mat_product(m, m1);
    if (prod != NULL) mat_print(prod);
    Mat* gioco = mat_alloc(4,4);
    for (int i = 0; i < 3; i++){
        gioco->rows_pt[i][1] = 1;
    }
    mat_free(m);
    mat_free(m1);
    mat_free(sum);
    mat_free(prod);
    mat_print(gioco);
    gioco = game_of_life(gioco);
    mat_print(gioco);
    //es2
    // printf("\n\nINIZIO ESERCIZIO 2\n\n");
    // char** array = (char**)realloc(argv, (argc+1)*sizeof(char*));
    // array[argc] = NULL;
    // sort_strings(array);
    // print_array(array);
    // free(array);
    // //es3
    // printf("\n\nINIZIO ESERCIZIO 3\n\n");
    // char* path = ".\\mat.txt";
    // Mat* m_out = mat_read(path);
    // mat_print(m_out);
    // mat_write(".\\out.txt", m_out);
    // mat_print(mat_read(".\\out.txt"));
    // mat_free(m_out);
    return 0;
}