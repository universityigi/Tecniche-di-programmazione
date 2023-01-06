#include <stdio.h>
#include <math.h>

int main() {
    int somma = 0;
    char c;
    printf("inserisci il tuo nome: ");
    while (c != '\n') {
        scanf("%c", &c);
        if (c == 'a' || c == 'j' || c == 's' ) {somma += 1;}
        else if (c == 'b' || c == 'k' || c == 't' ) {somma += 2;}
        else if (c == 'c' || c == 'l' || c == 'u' ) {somma += 3;}
        else if (c == 'd' || c == 'm' || c == 'v' ) {somma += 4;}
        else if (c == 'e' || c == 'n' || c == 'w' ) {somma += 5;}
        else if (c == 'f' || c == 'o' || c == 'x' ) {somma += 6;}
        else if (c == 'g' || c == 'p' || c == 'y' ) {somma += 7;}
        else if (c == 'h' || c == 'q' || c == 'z' ) {somma += 8;}
        else if (c == 'i' || c == 'r') {somma += 9;}
    }
    int cifre = 0;
    if (somma == 11 || somma == 22) {
    printf("il tuo numero fortunato e' %d\n", somma);
    return 0; 
    }
    for (int i = 1; i >= 0; i--) {
        int numero = somma/pow(10, i);
        cifre += numero;
        somma -= numero * pow(10, i);
    }
    printf("il tuo numero fortunato e' %d\n", cifre);
    return 0;
}