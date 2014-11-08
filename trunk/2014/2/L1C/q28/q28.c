/*
 * q28.c
 *
 *  Created on: 08/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main() {
	int i, j, numero_bota[N], quantidade_botas, pares[N], somaPares = 0;
	char pe_bota[N];

    freopen("e28.txt", "r", stdin);
    freopen("s28.txt", "w", stdout);

	scanf("%d", &quantidade_botas);
	while (quantidade_botas) {
		for (i = 0; i < quantidade_botas; ++i) {
			scanf("%d %c", &numero_bota[i], &pe_bota[i]);
			pares[i] = 0;
		}

		for (i = 0; i < quantidade_botas; ++i) {
			for(j = i + 1; j < quantidade_botas; ++j) {
				if (pares[i]) {
					break;
				}

				if (numero_bota[i] == numero_bota[j] && pe_bota[i] != pe_bota[j]) {
					pares[i] = 1;
					pares[j] = 1;
					break;
				}
			}
		}

		for (somaPares = 0, i = 0; i < quantidade_botas; ++i) {
			somaPares += pares[i];
		}

		printf("%d\n", somaPares/2);
		scanf("%d", &quantidade_botas);
	}

	fclose(stdin);
    fclose(stdout);

	return 0;
}

