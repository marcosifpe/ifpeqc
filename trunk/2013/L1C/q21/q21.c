/*
 * q21.c
 *
 *  Created on: 02/11/2012
 *      Author: masc
 */
#include <stdio.h>
#define T 20

void bolha(int v[]) {
	int i, j, k = T - 1, aux;

	for (i = 0; i < T; ++i) {
		j = 0;
		while (j <= k) {
			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
			++j;
		}
		--k;
	}
}

int main(void) {
	int i, v[T];
	freopen("e21.txt", "r", stdin);
	freopen("s21.txt", "w", stdout);

	for (i = 0; i < T; ++i) {
		scanf("%d", &v[i]);
	}

	bolha(v);

	for (i = 0; i < T; ++i) {
		printf("%d ", v[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


