/*
 * q9.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b, i, empates, pontos;
	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);
	scanf("%d %d", &a, &b);

	while (a && b) {
		empates = 3 * b;

		for (i = 0; i < a; ++i) {
			getchar();
			getchar();
			scanf("%d", &pontos);
			empates -= pontos;
		}

		printf("%d\n", empates);
		scanf("%d %d", &a, &b);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


