/*
 * q6.c
 *
 *  Created on: 24/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define L 5

void ler(int v[L]) {
	int i;
	for (i = 0; i < L; ++i) {
		scanf("%d", &v[i]);
	}
}

void ordenar(int v[L]) {
	int i, j, value;
	int gap = 1;
	do {
		gap = 3 * gap + 1;
	} while (gap < L);

	do {
		gap /= 3;
		for (i = gap; i < L; i++) {
			value = v[i];
			j = i - gap;
			while (j >= 0 && value < v[j]) {
				v[j + gap] = v[j];
				j -= gap;
			}
			v[j + gap] = value;
		}
	} while (gap > 1);
}

void popularMatriz(int m[L][L], int v[L], int i) {
	int j;
	for (j = 0; j < L; ++j)
		m[i][j] = v[j];
}

void imprimirMatriz(int m[L][L]) {
	int i, j;
	for (i = 0; i < L; ++i) {
		for (j = 0; j < L; ++j) {
			if (j)
				printf(", ");
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int v[L], m[L][L], i;
	freopen("e6.txt", "r", stdin);
	freopen("s6.txt", "w", stdout);

	for(i = 0; i < L; i++) {
		ler(v);
		ordenar(v);
		popularMatriz(m, v, i);
	}

	imprimirMatriz(m);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

