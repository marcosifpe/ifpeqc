/*
 * q8.c
 *
 *  Created on: 24/04/2013
 *      Author: masc
 */
#include <stdio.h>
#include <math.h>
#define T 9

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
	unsigned digitos, numero, n, divisor, dig, cociente, v[T], i = 0;

	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);

	scanf("%u", &n);

	while (n--) {
		scanf("%u", &numero);
		//realizando cálculo do dígito
		for (i = 1; pow(10, i) <= numero; i++);
		digitos = i;

		//realizando cálculo do divisor
		dig = digitos;
		divisor = 1;

		while (--dig) {
			divisor *= 10;
		}

		i = 0;
		//separando os números
		while (divisor) {
			cociente = numero / divisor;
			v[i++] = cociente;
			numero -= cociente * divisor;
			divisor /= 10;
		}

		//iprimindo invertido
		while(i) {
			printf("%u", v[--i]);
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
