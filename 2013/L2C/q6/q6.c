/*
 * q6.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define T 6

//Cria uma matriz de inteiros dinamicamente.

int** criarMatriz(int linha, int coluna) {

    int i, j, **m = (int**) malloc(linha * sizeof (int*));

    if (m == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < linha; i++) {
        m[i] = (int*) malloc(coluna * sizeof (int));

        if (m[i] == NULL) {
            //Liberando o espaço já alocado
            for (j = 0; j < i; j++) {
                free(m[j]);
            }
            free(m);
            exit(EXIT_FAILURE);

        }

    }

    return m;

}

void lerMatriz(int n, int** m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
}

void lerRota(int v[]) {
	int i;
	for (i = 0; i < T; i++) {
		scanf("%d", &v[i]);
	}
}

void calcularCusto(int rota[], int **m) {
	int i, custo;

	for (i = 0, custo = 0; i < T - 1; i++) {
		custo += m[rota[i]][rota[i + 1]];
	}

	printf("%d", custo);
}

int main(void) {
	int n, **m, rota[T];
	char s[30];
	freopen("e6.txt", "r", stdin);
	freopen("s6.txt", "w", stdout);
	scanf("%d", &n);
	m = criarMatriz(n, n);
	scanf("%s", s); //apenas para ignorar
	lerMatriz(n, m);
	scanf("%s", s); //apenas para ignorar
	lerRota(rota);
	calcularCusto(rota, m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
