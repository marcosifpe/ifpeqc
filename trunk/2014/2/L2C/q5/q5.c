#include <stdio.h>
#include <stdlib.h>
#define N 4

void lerMatriz(int m[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
		}
	}
}

int somaLinha(int i, int m[N][N]) {
	int j, s;

	for (s = 0, j = 0; j < N; j++) {
		s += m[i][j];
	}

	return s;
}

int somaColuna(int j, int m[N][N]) {
	int i, s;

	for (s = 0, i = 0; i < N; i++) {
		s += m[i][j];
	}

	return s;
}

int somaDiagonalPrincipal(int m[N][N]) {
	int i, s;
	for (s = 0, i = 0; i < N; i++) {
		s += m[i][i];
	}

	return s;
}

int somaDiagonalSecundaria(int m[N][N]) {
	int i, s;
	for (s = 0, i = 0; i < N; i++) {
		s += m[i][(N-1)-i];
	}

	return s;
}

int main(void) {
	int i, j, k, m[N][N], s;
	char qm;
	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	scanf("%d", &k);
	do {
		qm = 'S';
		lerMatriz(m);

		s = somaLinha(0, m);
		for (i = 1; i < N; i++) {
			if (s != somaLinha(i, m))
				qm = 'N';
		}

		for (j = 0; j < N; j++) {
			if (s != somaColuna(j, m))
				qm = 'N';
		}

		if (s != somaDiagonalPrincipal(m)) {
			qm = 'N';
		}

		if (s != somaDiagonalSecundaria(m)) {
			qm = 'N';
		}

		printf("%c ", qm);
	} while (--k);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

