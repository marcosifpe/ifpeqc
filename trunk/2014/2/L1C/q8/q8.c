/*
 * q8.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int raio, a, l, p, validaTamanho, diametro;
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);
	scanf("%d", &raio);

	while (raio) {
		diametro = 2*raio;
		validaTamanho = 0;

		scanf("%d %d %d", &a, &l, &p);

		validaTamanho += (diametro <= a);
		validaTamanho += (diametro <= l);
		validaTamanho += (diametro <= p);

		if (validaTamanho == 3)
			printf("S\n");
		else
			printf("N\n");

		scanf("%d", &raio);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


