/*
 * q26.c
 *
 *  Created on: 03/11/2012
 *      Author: masc
 */
#include <stdio.h>

void criarTabuada(unsigned n) {
	unsigned m[n][n], i, j, s[n];

	for (i = 0; i < n; ++i) {
		for (j = 0, s[i] = 0; j < n; ++j) {
			m[i][j] = (i + 1) * (j + 1);
			s[i] += m[i][j];
		}
	}

	for (i = 0; i < n; ++i)
		printf("%d ", s[i]);
	printf("\n\n");

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

int main(void) {
	unsigned n;
	freopen("e26.txt", "r", stdin);
	freopen("s26.txt", "w", stdout);

	scanf("%u", &n);
	criarTabuada(n);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
