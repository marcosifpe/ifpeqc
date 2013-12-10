/*
 * q12.c
 *
 *  Created on: 25/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define N 48

int** criarMatriz(int linha, int coluna) {
	int i, j, **m = (int**) malloc(linha * sizeof(int*));
	if (m == NULL ) {
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < linha; i++) {
		m[i] = (int*) malloc(coluna * sizeof(int));
		if (m[i] == NULL ) {
			for (j = 0; j < i; j++) {
				free(m[j]);
			}
			free(m);
			exit(EXIT_FAILURE);
		}
	}
	return m;
}

void ler(int** matriz, int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);

	return;
}

void limparMemoria(int** matriz, int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(matriz[i]);
	}

	free(matriz);
}

bool calcularCusto(int** matriz, int n) {
	bool parar = false, cont = 0;
	char c;
	int x = -1, y = -1, custo = 0;

	do {
		c = getchar();
		if (c == '!') {
			parar = true;
			break;
		} else if (c == '.') {
			break;
		} if (isspace(c)) {
			continue;
		}

		if (cont == 0) {
			cont = 1;
			x = (int) (c - N);
		} else {
			cont = 0;
			y = (int) (c - N);
		}

		if (x != -1 && y != -1) {
			if (cont == 0) {
				custo += matriz[x][y];
			} else {
				custo += matriz[y][x];
			}
		}

	} while(true);

	if (custo)
		printf("%d\n", custo);
	return parar;
}

int main(void) {
	int n, **matriz;
	bool parar;
	freopen("e7.txt", "r", stdin);
	freopen("s7.txt", "w", stdout);

	scanf("%d", &n);
	matriz = criarMatriz(n, n);
	ler(matriz, n);

	do {
		parar = calcularCusto(matriz, n);
	} while (!parar);

	limparMemoria(matriz, n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

