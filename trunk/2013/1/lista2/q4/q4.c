/*
 * q4.c
 *
 *  Created on: 25/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define N 6

void lerMatriz(int m[N][N]) {
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			scanf("%d", &m[i][j]);
		}
	}
}

void lerVetor(int v[N]) {
	int i;

	for (i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
	}
}

void calcularRota(int m[N][N], int v[N]) {
	int i, custo = 0;

	for (i = 0; i < N - 1; ++i) {
		custo += m[v[i]][v[i+1]];
	}

	printf("%d\n", custo);
}

int main(void) {
	int m[N][N], v[N];
	char s[10];
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%s", s); //pula "matriz"
	lerMatriz(m);
	scanf("%s", s); //pula "rota"
	lerVetor(v);
	calcularRota(m, v);

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
