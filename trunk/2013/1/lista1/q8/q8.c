/*
 * q8.c
 *
 *  Created on: 24/04/2013
 *      Author: masc
 */
#include <stdio.h>
#include <math.h>
#define T 9

unsigned int calculaDigitos(unsigned int x) {
	unsigned int i;

	for (i = 1; pow(10, i) <= x; i++);

	return i;
}

void imprimirDigitos(unsigned int digitos, unsigned int numero) {
	unsigned int divisor = 1, dig = digitos, cociente, v[T], i = 0;

	while (--dig) {
		divisor *= 10;
	}

	while (divisor) {
		cociente = numero / divisor;
		v[i++] = cociente;
		numero -= cociente * divisor;
		divisor /= 10;
	}

	while(i) {
		printf("%u", v[--i]);
	}
}

int main(void) {
	unsigned int digitos, numero, n;
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);

	scanf("%u", &n);

	while (n--) {
		scanf("%u", &numero);
		digitos = calculaDigitos(numero);
		imprimirDigitos(digitos, numero);
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
