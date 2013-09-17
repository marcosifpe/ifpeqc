/*
 * q7.c
 *
 *  Created on: 25/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ehPrimo(unsigned int a, bool *resultado) {
	unsigned int i;

	if (a == 1) {
		*resultado = false;
	} else {
		*resultado = true;
		for (i = 2; i < a; i++) {
			if (a % i == 0) {
				*resultado = false;
				break;
			}
		}
	}
}

void fatorial(unsigned int a, double *resultado) {
	unsigned int i;

	for (i = a, *resultado = 1.0; i > 0; --i) {
		*resultado *= i;
	}
}

int main(void) {
	unsigned int n, x, contador;
	double soma, resultado;
	bool primo;
	freopen("e7.txt", "r", stdin);
	freopen("s7.txt", "w", stdout);

	do {
		scanf("%u %u", &n, &x);
		contador = 0;
		soma = 0;
		if (!n && !x) {
			break;
		}

		while (contador != n) {
			ehPrimo(x, &primo);
			if (primo) {
				fatorial(x, &resultado);
				soma += resultado;
				contador++;
			}

			x++;
		}

		printf("%.0lf\n", soma);
	} while (true);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


