#include <stdio.h>
#include <stdlib.h>
#define ZERO 48

int** criarMatriz(int linha, int coluna) {
	int i, **m = (int**) malloc(linha * sizeof(int*));
	if (m == NULL) {
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < linha; i++) {
		m[i] = (int*) malloc(coluna * sizeof(int));
		if (m[i] == NULL) {
			exit(EXIT_FAILURE); //aborta a execução do programa.
		}
	}
	return m;
}

void imprimir(int ordem, int **m, FILE * f) {
	int i, j;

	for (i = 0; i < ordem; ++i) {
		for (j = 0; j < ordem; ++j) {
			if (j)
				fprintf(f, " ");
			fprintf(f, "%d", m[i][j]);
		}
		fprintf(f, "\n");
	}
}

int main(void) {
	FILE *in = fopen("e11.txt", "r"), *out = fopen("s11.txt", "w");
	char str[12];
	int ordem, i, j, k, p, q, r, s, x, y;
	int **a, **b, **c;

	if (in == NULL)
		exit(EXIT_FAILURE);

	if (out == NULL)
		exit(EXIT_FAILURE);

	while (fgets(str, 2, in) != NULL) {
		if (str[0] == '\n')
			continue;
		ordem = (int) str[0] - ZERO;
		a = criarMatriz(ordem, ordem);
		b = criarMatriz(ordem, ordem);
		c = criarMatriz(ordem, ordem);
		fgetc(in); //ignorar nova linha
		fgets(str, 12, in);
		p = (int) str[0] - ZERO;
		q = (int) str[2] - ZERO;
		r = (int) str[4] - ZERO;
		s = (int) str[6] - ZERO;
		x = (int) str[8] - ZERO;
		y = (int) str[10] - ZERO;

		for (i = 0; i < ordem; ++i) {
			for (j = 0; j < ordem; ++j) {
				//Aij = (P*i + Q*j)%X
				a[i][j] = (p * i + q * j) % x;
				//Bij = (R*i + S*j)%Y
				b[i][j] = (r * i + s * j) % y;
			}
		}

		for (i = 0; i < ordem; ++i) {
			for (j = 0; j < ordem; ++j) {
				c[i][j] = 0;
				for (k = 0; k < ordem; k++) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		fprintf(out, "Matriz A\n");
		imprimir(ordem, a, out);
		fprintf(out, "Matriz B\n");
		imprimir(ordem, b, out);
		fprintf(out, "Matriz C\n");
		imprimir(ordem, c, out);
		fprintf(out, "\n");

	    for (i = 0; i < ordem; i++) free(a[i]);
	    free(a);
	    for (i = 0; i < ordem; i++) free(b[i]);
	    free(b);
	    for (i = 0; i < ordem; i++) free(c[i]);
	    free(c);
	}

	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
}

