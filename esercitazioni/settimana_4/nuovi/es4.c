#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char **argv) {
	
	printf ("Programma che converte una temperatura in una certa scala (C,K,F) nelle altre due!\n");
	
	float* num = (float*)malloc(sizeof(float));
	printf ("Inserire la temperatura: ");
	scanf ("%f", num);
	
	char* scala = (char*)malloc(sizeof(char));
	printf ("Inserire la scala della temperatura (C,K,F): ");
	scanf (" %c", scala);
	
	switch(*scala) {
		case 'K':
			printf ("La temperatura in Celsius è: %f\n", *num - 273.15f);
			printf ("La temperatura in Fahrenheit è: %f\n", (*num - 273.15f) * 9.0f/5.0f + 32.0f);
			break;
		case 'C':
			printf ("La temperatura in Kelvin è: %f\n", *num + 273.15f);
			printf ("La temperatura in Fahrenheit è: %f\n", *num * 9.0f/5.0f + 32.0f);
			break;
		case 'F':
			printf ("La temperatura in Kelvin è: %f\n", ((*num -32.0f) * 5.0f/9.0f) + 273.15f);
			printf ("La temperatura in Celsius è: %f\n", (*num -32.0f) * 5.0f/9.0f);
			break;
		default:
			break;
		}
	free (num);
	free (scala);
	
	return 0;
	}
