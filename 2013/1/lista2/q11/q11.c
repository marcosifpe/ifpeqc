#include <stdio.h>
#include <stdlib.h>
//Cria uma matriz de inteiros dinamicamente.
int** criarMatriz(int linha, int coluna) {
	int i, j, **m = (int**) malloc(linha * sizeof(int*));
	if (m == NULL ) {
		printf("Não foi possível alocar memória para a matriz");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < linha; i++) {
		m[i] = (int*) malloc(coluna * sizeof(int));
		if (m[i] == NULL ) {
			printf("Não foi possível alocar memória");
			//Liberando o espaço já alocado
			for (j = 0; j < i; j++) {
				free(m[j]);
			}
			free(m);
			exit(EXIT_FAILURE); //aborta a execução do programa.
		}
	}
	return m;
}
int main(void) {
	int i, j, m, n, **matriz, **transposta;
	freopen("e11.txt", "r", stdin);
	freopen("s11.txt", "w", stdout);

	scanf("%d %d", &m, &n);
	matriz = criarMatriz(m, n);
	transposta = criarMatriz(n, m);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			transposta[i][j] = matriz[j][i];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", transposta[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < m; i++) {
		free(matriz[i]);
	}

	free(matriz);

	for (i = 0; i < n; i++) {
		free(transposta[i]);
	}

	free(transposta);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
