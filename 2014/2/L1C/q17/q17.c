/*
 * q17.c
 *
 *  Created on: 18/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#define M 101

int main(void) {
	int freq_notas[M], qtd_notas, nota, i, max = 0;
	freopen("e17.txt", "r", stdin);
	freopen("s17.txt", "w", stdout);

	for (i = 0; i < M; ++i) {
		freq_notas[i] = 0;
	}

	scanf("%d", &qtd_notas);

	for (i = 0; i < qtd_notas; ++i) {
		scanf("%d", &nota);
		freq_notas[nota]++;
	}

	for (i = 1; i < M; ++i) {
		if (freq_notas[max] <= freq_notas[i]) {
			max = i;
		}
	}

	printf("%d\n", max);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

