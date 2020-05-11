#include "esercizio1.h"
#include <stdlib.h>

int isPalindrome(CharList* src){
	
	int dim = 0;
	CharList* p = src;
	
	while (p != NULL) {
		dim++;
		p = src->next;
	}
	
	char* string = (char*)calloc(dim, sizeof(char));
	p = src;
	
	for (int i = 0; i < dim; i++) {
		string[i] = p->c;
		p = p->next;
	}
	
	int palindrome = 1;
	
	for (int n = 0; n < dim/2; n++) {
		if (string[n] != string[dim-1-n]) {
			palindrome = 0;
			break;
		}
	}
	
	free(string);
	return palindrome;
}
