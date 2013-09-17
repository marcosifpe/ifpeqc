/*
 * q9.c
 *
 *  Created on: 25/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 10

void calculaMedia(const double * notas, const int * numeroNotas, double * media) {
	int i;
	for (i = 0, *media = 0; i < *numeroNotas; ++i) {
		*media += notas[i];
	}

	*media /= *numeroNotas;
}

int main(void) {
	int n = 4, i = 0;
	double nota, media;
	double *notas = (double*) malloc(sizeof(double)*n);

	if (notas == NULL)
		exit(EXIT_FAILURE);

	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);

	do {
		scanf("%lf", &nota);
		if (nota == -1)
			break;

		if (nota >= MIN && nota <= MAX) {
			if (i == n) {
				n *= 2;
				notas = (double*) realloc(notas, sizeof(double)*n);
				if (notas == NULL)
					exit(EXIT_FAILURE);
			}

			notas[i++] = nota;
		}
	} while (1);

	calculaMedia(notas, &i, &media);
	printf("%.1lf\n", media);
	free(notas);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


