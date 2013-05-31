/*
 * q11.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 10

void bolha(int vetor[], int tamanho) {
	int aux, i, j;

	for (j = tamanho - 1; j >= 1; j--) {
		for (i = 0; i < j; i++) {
			if (vetor[i] > vetor[i + 1]) {
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
			}
		}
	}
}

int main(void) {
	int v[T], i, n, s;

	freopen("e11.txt", "r", stdin);
	freopen("s11.txt", "w", stdout);

	srand(time(0));
	scanf("%d", &n);

	while (n--) {
		for (s = 0, i = 0; i < T; ++i) {
			v[i] = rand() % 100 + 1;
			s += v[i];
		}

		bolha(v, T);
		printf("%d = ", s);

		for (i = 0; i < T; ++i) {
			if (i)
				printf(" + ");
			printf("%d", v[i]);
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

