/*
 * q24.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */
#include <stdio.h>
#define T 3

void somarMatrizes(int a[T][T], int b[T][T]) {
	int i, j;
	for (i = 0; i < T; ++i) {
		for (j = 0; j < T; ++j) {
			printf("%d ", a[i][j]+b[i][j]);
		}
		printf("\n");
	}
}

void lerMatriz(int m[][T]) {
	int i, j;
	for (i = 0; i < T; ++i) {
		for (j = 0; j < T; ++j) {
			scanf("%d ", &m[i][j]);
		}
	}
}

int main(int argc, char **argv) {
	int a[T][T], b[T][T];
	freopen("e24.txt", "r", stdin);
	freopen("s24.txt", "w", stdout);
	lerMatriz(a);
	lerMatriz(b);
	somarMatrizes(a, b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

