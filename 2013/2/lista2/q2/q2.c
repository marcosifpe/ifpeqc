/*
 * q2.c
 *
 *  Created on: 25/06/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 4

void lerMatriz(int m[N][N]) {
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			scanf("%d", &m[i][j]);
		}
	}
}

bool inca(int m[N][N]) {
	int i, j;

	for (i = 0, j = 0; j < N - 1; ++j) {
		if (m[i][j] + 1 != m[i][j + 1]) {
			return false;
		}
	}

	for (i = 0, j = N - 1; i < N - 1; ++i) {
		if (m[i][j] + 1 != m[i + 1][j]) {
			return false;
		}
	}

	for (i = N - 1, j = N - 1; j > 0; --j) {
		if (m[i][j] + 1 != m[i][j - 1]) {
			return false;
		}
	}

	for (i = N - 1, j = 0; i > 1; --i) {
		if (m[i][j] + 1 != m[i - 1][j]) {
			return false;
		}
	}

	for (i = 1, j = 0; j < N - 2; ++j) {
		if (m[i][j] + 1 != m[i][j + 1]) {
			return false;
		}
	}

	if (m[1][2] + 1 != m[2][2])
		return false;

	if (m[2][2] + 1 != m[2][1])
		return false;

	return true;
}

int main(void) {
	int m[N][N], n;
	char s[3];
	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);
	scanf("%d", &n);

	while (n--) {
		scanf("%s", s);
		lerMatriz(m);

		if (inca(m)) {
			printf("%s: inca\n", s);
		} else {
			printf("%s: nao inca\n", s);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
