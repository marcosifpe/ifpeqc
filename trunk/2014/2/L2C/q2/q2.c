#include <stdio.h>
#include <stdlib.h>

FILE * in, *out;

void lerMatriz(int m[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			fscanf(in, "%d", &m[i][j]);
		}
	}
}

void somarMatrizes(int a[3][3], int b[3][3]) {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			fprintf(out, "%d%s", a[i][j] + b[i][j], j != 3 ? " " : "");
		}

		fprintf(out, "\n");
	}

	fprintf(out, "\n");
}

int main(void) {
	int a[3][3], b[3][3];
	in = fopen("e2.txt", "r");
	out = fopen("s2.txt", "w");

	while (!feof(in)) {
		lerMatriz(a);
		lerMatriz(b);
		somarMatrizes(a, b);
	}

	fclose(in);
	fclose(out);
	return 0;
}
