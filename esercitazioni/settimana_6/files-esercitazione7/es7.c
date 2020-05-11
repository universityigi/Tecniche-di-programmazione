#include <stdio.h>
#include <stdlib.h>

double* vec_read(int *dim, char *filename);
void    vec_print(double *v, int dim);
void    vec_write(char *filename, double *v, int dim);
void    vec_scale(double *v, int dim, double d);
double  vec_dot(double *src1, double *src2, int dim);
double* vec_clone(double *v, int dim);

int main(int argc, char **argv) {
  int dim1 = 0, dim2 = 0, dim3 = 0;
  
  /********************************************************
   *                    TEST vec_read                     *
   ********************************************************/
  // printf("Leggo v1 dal file vec_1.txt...");
  // double *v1 = vec_read(&dim1, "vec_1.txt");
  // printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print                    *
   ********************************************************/
  // printf("v1: ");
  // vec_print(v1, dim1);
  // printf("\n\n");

  /********************************************************
   *                    TEST vec_write                    *
   ********************************************************/
  // printf("Scrivo una copia di v1 in copia_vec_1.txt...");
  // vec_write("copia_vec_1.txt", v1, dim1);
  // printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_scale                    *
   ********************************************************/
  // printf("Leggo v2 dal file vec_2.txt...");
  // double *v2 = vec_read(&dim2, "vec_2.txt");
  // printf(" done.\n");
  // printf("v2: ");
  // vec_print(v2, dim2);
  // printf("Leggo v3 dal file vec_3.txt...");
  // double *v3 = vec_read(&dim3, "vec_3.txt");
  // printf(" done.\n");
  // printf("v3: ");
  // vec_print(v3, dim3);  
  // printf("Scalo v3 di un fattore di 0.5...");
  // vec_scale(v3, dim3, 0.5);
  // printf(" done.\n");
  // printf("v3: ");
  // vec_print(v3, dim3);  
  // printf("\n");

  /********************************************************
   *                    TEST vec_dot                      *
   ********************************************************/
  // printf("Calcolo il prodotto scalare tra v2 e v3...");
  // double dot = vec_dot(v2, v3, dim2);
  // printf(" done.\n");
  // printf("Il profotto scalare tra v2 e v3 e': %lf\n\n", dot);

  /********************************************************
   *                    TEST vec_clone                    *
   ********************************************************/
  // printf("Clono v2...");
  // double *copy_v2 = vec_clone(v2, dim2);
  // printf(" done.\n");
  // printf("Copia v2: ");
  // vec_print(copy_v2, dim3);  

  // free(copy_v2);
  // free(v3);
  // free(v2);
  // free(v1);

  return 0;
}
