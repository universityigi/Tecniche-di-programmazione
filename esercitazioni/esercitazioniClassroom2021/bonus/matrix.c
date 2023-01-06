#include "../eserc5/f.h"


void max_row_col(Mat* m, int* max_row, int* max_col){
    *max_row = 0;
    *max_col = 0; 
    int max_col_value = 0;
    int max_row_value = 0;
    for (int i = 0; i < m->rows; i++){
        int sum = 0;
        for (int j = 0; j < m->cols; j++){
            sum += m->rows_pt[i][j];
        }
        if (sum > max_row_value) {
            *max_row = i;
            max_row_value = sum;
        }
    }
    for (int j = 0; j < m->cols; j++){
        int sum = 0;
        for (int i = 0; i < m->rows; i++){
            sum += m->rows_pt[i][j];
        }
        if (sum > max_col_value) {
            *max_col = j;
            max_col_value = sum; 
        }
    }

}

int main(){
    int max_row, max_col;
    Mat* m = mat_alloc(3,5);
    for (int i = 0; i < m->rows; i++){
        for (int j = 0; j < m->cols;j++){
            m->rows_pt[i][j] = i+(j*m->cols);
        }
    }
    mat_print(m);
    max_row_col(m, &max_row, &max_col);
    printf("maxrow = %d\t maxcol = %d\n",max_row, max_col);
    return 0;
}
