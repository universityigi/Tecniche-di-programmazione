#include "f.h"

Mat* mat_alloc(int rows, int cols){
    Mat* m = (Mat*) malloc (1*sizeof(Mat));
    m -> rows = rows;
    m -> cols = cols;
    m->rows_pt = (float**)calloc(rows,sizeof(float*));
    for (int i = 0; i < rows; i++){
        m->rows_pt[i] = (float*)calloc(cols,sizeof(float));
    }
    return m;
}

void mat_print(Mat* m){
    int righe = m->rows;
    int colonne = m->cols;
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++){
            printf("%f ",m->rows_pt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mat_free(Mat *m){
    for (int i = 0; i< m->rows; i++){
        free(m->rows_pt[i]);
    }
    free(m->rows_pt);
    free(m);
}

Mat * mat_clone(Mat *m){
    Mat* clone = mat_alloc(m->rows,m->cols);
    clone->rows = m->rows;
    clone->cols = m->cols;
    for (int i = 0; i<m->rows; i++){
        for (int j = 0; j<m->cols; j++){
            clone->rows_pt[i][j] = m->rows_pt[i][j];
        }
    }
    return clone;
}

bool mat_is_symmetric(Mat *m){
    bool symmetric = true;
    for (int i = 0; i<m->rows; i++){
        for (int j = 0; j<m->cols; j++){
            if(m->rows_pt[i][j] != m->rows_pt[j][i]){return false;}
        }
    }
    return symmetric;
}

void mat_normalize_rows(Mat *m){
    for (int i = 0; i < m->rows; i++){
        int sum_row = 0;
        for (int j = 0; j < m->cols; j++){
            sum_row += pow(m->rows_pt[i][j],2);
        }
        sum_row = sqrt(sum_row);
        for (int j = 0; j < m->cols; j++){
            m->rows_pt[i][j] /= sum_row;
        }
    }
}

Mat* mat_sum(Mat *m1, Mat *m2){
    if (m1->rows != m2->rows || m1->cols != m2->cols){
        printf("Impossibile sommare matrici");
        return NULL;
    }
    Mat* sum = mat_alloc(m1->rows, m1->cols);
    for (int i = 0; i<sum->rows; i++){
        for (int j = 0; j<sum->cols; j++){
            sum->rows_pt[i][j] = (m1->rows_pt[i][j] + m2->rows_pt[i][j]);
        }
    }
    return sum;
}

Mat* mat_product(Mat *m1, Mat *m2){
    if (m1->cols != m2->rows){
        printf("Impossibile moltiplicare matrici");
        return NULL;
    }
    Mat* prod = mat_alloc(m1->rows, m2->cols);
    for (int i = 0; i<prod->rows; i++){
        for (int j = 0; j<prod->cols; j++){
            for (int z = 0; z<m1->cols; z++){
                prod->rows_pt[i][j]+= m1->rows_pt[i][z]*m2->rows_pt[z][j];
            }
        }
    }
    return prod;
}

Mat* game_of_life(Mat* mat){
    Mat* result = mat_alloc(mat->rows, mat->cols);
    for (int i = 1; i < mat->rows-1; i++){
        for (int j = 1; j < mat->cols-1; j++){
            int sum = mat->rows_pt[i][j-1] + mat->rows_pt[i][j+1] + mat->rows_pt[i-1][j] + mat->rows_pt[i+1][j] + mat->rows_pt[i-1][j-1] + mat->rows_pt[i+1][j-1] + mat->rows_pt[i-1][j+1] + mat->rows_pt[i+1][j+1];
            if (mat->rows_pt[i][j] != 0){
                if (sum > 3 || sum < 2){
                    result->rows_pt[i][j] = 0;
                }
                else if (sum == 3 || sum == 2){
                    result->rows_pt[i][j] = 1;
                }
            }
            else if (mat->rows_pt[i][j] == 0){
                if (sum == 3){
                    result->rows_pt[i][j] = 1;
                }
                else{
                    result->rows_pt[i][j] = 0;
                }
            }
        }
    }
    return result;
}
