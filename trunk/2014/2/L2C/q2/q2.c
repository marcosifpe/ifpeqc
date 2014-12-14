#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int m[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &m[i][j]);
		}
	}
}

void somarMatrizes(int a[3][3], int b[3][3]) {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d%s", a[i][j] + b[i][j], j != 3 ? " " : "");
		}

		printf("\n");
	}
}

int main(void) {
	int a[3][3], b[3][3];
	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);
	lerMatriz(a);
	lerMatriz(b);
	somarMatrizes(a, b);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
