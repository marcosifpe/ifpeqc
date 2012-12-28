/*
 * q5.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 5
#define MIN 0
#define MAX 10
#define END -1

void calculaMedia(const double *notas, const int *numeroNotas, double *media) {
	int i;
	*media = 0;

	for (i = 0; i < *numeroNotas; ++i) {
		*media += notas[i];
	}

	*media /= *numeroNotas;
}

//Shell Sort
void ordena(double * const notas, const int numeroNotas) {
	int i, j;
	double value;
	int gap = 1;
	do {
		gap = 3 * gap + 1;
	} while (gap < numeroNotas);
	do {
		gap /= 3;
		for (i = gap; i < numeroNotas; i++) {
			value = notas[i];
			j = i - gap;
			while (j >= 0 && value < notas[j]) {
				notas[j + gap] = notas[j];
				j -= gap;
			}
			notas[j + gap] = value;
		}
	} while (gap > 1);
}

int main(void) {
	int i, tam = T, numeroNotas = 0;
	double media, nota, *notas = (double*) calloc(tam, sizeof(double));

	if (notas == NULL)
		exit(EXIT_FAILURE);

	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	do {
		scanf("%lf", &nota);
		if (nota == END)
			break;
		if (nota >= MIN && nota <= MAX) {
			if (numeroNotas == tam) {
				tam *= 2;
				notas = (double*) realloc(notas, tam * sizeof(double));
				if (notas == NULL)
					exit(EXIT_FAILURE);
			}

			notas[numeroNotas++] = nota;
		}
	} while (true);

	calculaMedia(notas, &numeroNotas, &media);
	ordena(notas, numeroNotas);

	printf("%.1lf\n", media);

	for (i = numeroNotas - 1; i >=0; i--) {
		printf("%.1lf ", notas[i]);
	}

	free(notas);
	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
