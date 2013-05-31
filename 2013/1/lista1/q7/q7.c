/*
 * q7.c
 *
 *  Created on: 31/05/2013
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
	unsigned int divisor = 1, dig = digitos, cociente;

	while (--dig) {
		divisor *= 10;
	}

	while (divisor) {
		cociente = numero / divisor;
		printf("%u ", cociente);
		numero -= cociente * divisor;
		divisor /= 10;
	}
}

int main(void) {
	unsigned int digitos, divisor, dig, cociente, numero;
	freopen("e7.txt", "r", stdin);
	freopen("s7.txt", "w", stdout);

	while (1) {
		scanf("%u %u", &digitos, &numero);
		if (!digitos && !numero)
			break;

		divisor = 1;
		dig = digitos;

		while (--dig) {
			divisor *= 10;
		}

		while (divisor) {
			cociente = numero / divisor;
			printf("%u ", cociente);
			numero -= cociente * divisor;
			divisor /= 10;
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
