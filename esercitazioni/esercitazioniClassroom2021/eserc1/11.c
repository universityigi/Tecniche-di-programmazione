#include <stdio.h>

int main() {
int numMax;
int n = 1;
int count = 1;
scanf("%d",&numMax);
while (count <= numMax){
	for (int i=0;i<count;i++) {
		printf("%d ",n);
		n++;}
	count += 1;
	printf("\n");
}
return 0;
}
