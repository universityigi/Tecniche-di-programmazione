#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#pragma once


typedef struct {
    char rows;
    char cols;
    float **rows_pt;
    } Mat;

Mat* mat_alloc(int rows, int cols);
void mat_print(Mat* m);
void mat_free(Mat *m);
Mat * mat_clone(Mat *m);
bool mat_is_symmetric(Mat *m);
void mat_normalize_rows(Mat *m);
Mat* mat_sum(Mat *m1, Mat *m2);
Mat* mat_product(Mat *m1, Mat *m2);
Mat* game_of_life(Mat* mat);

void sort_strings(char **array);
void print_array(char** array);
Mat* mat_read(const char *filename);
void mat_write(const char *filename, Mat *m);
