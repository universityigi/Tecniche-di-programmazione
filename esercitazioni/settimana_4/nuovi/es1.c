#include <stdio.h>
#include <stdlib.h>


int main () {
	
	char c   = 'a';
	short s  = 10;
	int i    = 50;
	long l   = 100;
	float f  = 4.5;
	double d = 1000;
	
	printf ("L'indirizzo di memoria di c è %p e la dimensione in byte è %ld\n", &c, sizeof(c));
	printf ("L'indirizzo di memoria di s è %p e la dimensione in byte è %ld\n", &s, sizeof(s));
	printf ("L'indirizzo di memoria di i è %p e la dimensione in byte è %ld\n", &i, sizeof(i));
	printf ("L'indirizzo di memoria di l è %p e la dimensione in byte è %ld\n", &l, sizeof(l));
	printf ("L'indirizzo di memoria di f è %p e la dimensione in byte è %ld\n", &f, sizeof(f));
	printf ("L'indirizzo di memoria di d è %p e la dimensione in byte è %ld\n", &d, sizeof(d));
	}
