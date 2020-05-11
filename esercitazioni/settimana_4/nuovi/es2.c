#include <stdio.h>
#include <stdlib.h>


int main () {
	int i = 10; 

	int j = 20; 

	char *p, *q;

	p = (char*)&i;
	q = (char*)&j;
	
	for (int k=0; k < sizeof(i); ++k) {
		*(q+k) = *(p+k);
		
		}
	
	
	printf("varibile i: %d, variabile j: %d\n", i, j); 

	
	return 0;
	}
