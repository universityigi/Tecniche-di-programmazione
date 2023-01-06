#include "f.h"

Mat* mat_read(const char *filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL){
        printf("ERRORE APERTURA: path sbagliata?");
        exit(1);
    }
    int rows, cols;
    fscanf(file,"%d%d", &rows, &cols);
    fgetc(file);
    printf("rows:%d\tcols:%d\n", rows, cols);
    Mat* m = mat_alloc(rows,cols);
    for (int i = 0; i <rows; i++){
        for (int j = 0; j < cols; j++){
            fscanf(file, "%f", &(m->rows_pt[i][j]));
        }
    }
    fclose(file);
    return m;
}
void mat_write(const char *filename, Mat *m){
    FILE* file = fopen(filename, "w");
    if (file == NULL){
        printf("ERRORE APERTURA: path sbagliata?");
        exit(1);
    }
    fprintf(file,"%d %d\n", m->rows, m->cols);
    for(int i = 0; i<m->rows;i++){
        for (int j = 0; j<m->cols; j++){
            fprintf(file,"%f ", m->rows_pt[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}