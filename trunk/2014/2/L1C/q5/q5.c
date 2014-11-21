/*
 * q5.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main(void) {
	int i, j, secreto, min_dif, min_posicao, num, dif, posicao;
	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	for (scanf("%d", &i); i; --i) {
		scanf("%d %d", &j, &secreto);
		for (min_dif = MAX, posicao = 1; j; --j, ++posicao) {
			scanf("%d", &num);
			dif = abs(num - secreto);

			if (dif < min_dif) {
				min_dif = dif;
				min_posicao = posicao;
			}
		}

		printf("%d\n", min_posicao);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}



