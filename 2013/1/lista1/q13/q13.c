/*
 * q13.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */

#include <stdio.h>
#include <stdbool.h>
#define T 10000

typedef struct {
	int tamanho;
	char pe;
	bool par;
} bota;

int main(void) {
	int n, i, j, pares;
	bota b[T];
	freopen("e13.txt", "r", stdin);
	freopen("s13.txt", "w", stdout);
	scanf("%d", &n);

	while (n) {
		pares = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %c", &b[i].tamanho, &b[i].pe);
			b[i].par = false;
		}

		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (b[i].pe != b[j].pe && b[i].tamanho == b[j].tamanho) {
					b[i].par = b[j].par = true;
					break;
				}
			}
		}

		for (i = 0; i < n; i++) {
			if (b[i].par)
				pares++;
		}

		printf("%d\n", pares / 2);
		scanf("%d", &n);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


