/*
 * q29.c
 *
 *  Created on: 07/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

unsigned calcular_numero_digitos(unsigned n) {
	unsigned div = 10, dig = 1;

	while (div <= n) {
		div *= 10;
		dig += 1;
	}

	return dig;
}

int main(void) {
	unsigned a, b, c, i, numero_digitos;
	unsigned digitos[N], divisores[] = { 0, 1, 10, 100,
			1000, 10000, 100000, 1000000, 10000000, 100000000 };
	freopen("e29.txt", "r", stdin);
	freopen("s29.txt", "w", stdout);

	while (true) {
		scanf("%u %u", &a, &b);

		if (!a && !b) {
			break;
		}

		for (i = 0; i < N; ++i) {
			digitos[i] = 0;
		}

		while (a <= b) {
			for (numero_digitos = calcular_numero_digitos(a), i = 0, c = a;
					numero_digitos; numero_digitos--) {
				digitos[c / divisores[numero_digitos]] += 1;
				c %= divisores[numero_digitos];
			}

			a += 1;
		}

		for (i = 0; i < N; ++i) {
			if (i)
				printf(" ");
			printf("%d", digitos[i]);
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}

