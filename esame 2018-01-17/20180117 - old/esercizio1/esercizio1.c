#include "esercizio1.h"
#include <stdlib.h>

int isPalindrome(CharList* src){
	
	int dim = 0;
	CharList *p = src;
	
	while ( p != NULL) {
		
		dim++;
		p = p -> next;
		
		}
	
	char *str = (char*) malloc(dim*sizeof(char));
	p = src;
	
	for (int i = 0; i < dim; i++) {
		str[i] = p->c;
		p = p->next;
	}
	
	int is_palindrome = 1;
	int j = dim-1;
	
	for (int i = 0; i < dim/2; i++) {
		
		if (str[i] != str[j]) {
			is_palindrome = 0;
			break;
		}
		j--;
	}
	
	free(str);
	
	return is_palindrome;
}
