#include "mat.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int conditionalSum(Mat* src, int flag);
int next_step(Mat *mat, char direction);

int main(){
  Mat *mm1=mat_alloc(2,3);
	Mat *mm2=mat_alloc(4,4);
	mm1->rows_pt[0][0]=1;
	mm1->rows_pt[0][1]=2;
	mm1->rows_pt[0][2]=3;
  mm1->rows_pt[1][0]=4;
	mm1->rows_pt[1][1]=5;
	mm1->rows_pt[1][2]=6;

	mm2->rows_pt[0][0]='#';
	mm2->rows_pt[0][1]='#';
	mm2->rows_pt[0][2]='#';
	mm2->rows_pt[0][3]='#';
  mm2->rows_pt[1][0]='#';
	mm2->rows_pt[1][1]='X';
	mm2->rows_pt[1][2]='o';
	mm2->rows_pt[1][3]='#';
  mm2->rows_pt[2][0]='#';
  mm2->rows_pt[2][1]=' ';
  mm2->rows_pt[2][2]=' ';
  mm2->rows_pt[2][3]='#';
  mm2->rows_pt[3][0]='#';
  mm2->rows_pt[3][1]='#';
  mm2->rows_pt[3][2]='#';
  mm2->rows_pt[3][3]='#';

  mat_print(mm2);
  printf("CONDITIONAL_SUM=\t%d\n", conditionalSum(mm1, 0));
  printf("NEXT_STEP=\t\t%d\n\n", next_step(mm2, 'd'));
  mat_print(mm2);
}

int conditionalSum(Mat* src, int flag){
  int sum = 0;
  for (int i = 0; i < src->rows; i++){
    for (int j = 0; j < src->cols; j++){
      int toSum = src->rows_pt[i][j];
      if ((flag ==  0 && j%2 != 0) || (flag ==  1 && i%2 != 0))
        toSum *=-1;
      sum += toSum;
    }
  }
  return sum;
}

void snake_pos(Mat *mat, int *x, int *y){
  for (int i = 0; i < mat->rows; i++){
    for (int j = 0; j < mat->cols; j++){
      if (mat->rows_pt[i][j] == 'X'){
        *x = i;
        *y = j;
        return;
      }
    }
  }
}

int next_step(Mat *mat, char direction){
  int curr_x, curr_y;
  snake_pos(mat, &curr_x, &curr_y);
  int next_x, next_y;
  mat->rows_pt[curr_x][curr_y] = ' ';
  if(direction == 'w'){
    next_x = curr_x - 1;
    next_y = curr_y;
  }
  else if(direction == 'a'){
    next_x = curr_x;
    next_y = curr_y - 1;
  }
  else if(direction == 's'){
    next_x = curr_x + 1;
    next_y = curr_y;

  }
  else if(direction == 'd'){
    next_x = curr_x;
    next_y = curr_y + 1;
  }
  char next_pos = mat->rows_pt[next_x][next_y];
  if (next_pos == '#'){
    mat->rows_pt[next_x][next_y] = 'X';
    return -1;
  }
  else if (next_pos== 'o'){
    mat->rows_pt[next_x][next_y] = 'X';
    return 1;
  }
  else{
    mat->rows_pt[next_x][next_y] = 'X';
    return 0;
  }
}
