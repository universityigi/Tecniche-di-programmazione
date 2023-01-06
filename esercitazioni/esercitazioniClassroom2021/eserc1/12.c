#include <stdio.h>

int main() {
int n1, n2;
scanf("%d%d",&n1,&n2);
int i = 2;
int ris = 0;
while (ris == 0) {
	if (i%n1 == 0 && i%n2 == 0)
		{ris = 1;}
	else
		{i++;}
	}
printf("risultato %d",i);
return 0;
}
