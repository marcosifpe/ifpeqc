/*
 * q2.c
 *
 *  Created on: 05/10/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, linhas, inicio, fim, soma, impares;

	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);
	scanf("%i", &linhas);

	for (i = 0; i < linhas; i++) {
		scanf("%i %i", &inicio, &fim);
		soma = 0;
		impares = 0;
		inicio += 1;

		while (inicio != fim) {
			if (inicio % 2) {
				soma += inicio;
				impares += 1;
			}

			inicio += 1;
		}

		if (soma)
			printf("%d %d\n", soma, soma/impares);
		else
			printf("Nao existem impares no intervalo\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

