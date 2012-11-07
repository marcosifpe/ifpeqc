/*
 * q11.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
	int i, t, n, somaPontos, pontos;
	char c;
	freopen("e11.txt", "r", stdin);
	freopen("s11.txt", "w", stdout);

	do {
		scanf("%d %d", &t, &n);
		if (t == 0 && n == 0)
			break;

		for (i = 0, somaPontos = 0; i < t; ++i) {
			do {
			 	c = getchar();
			} while (isspace(c));
			scanf("%d", &pontos);
			somaPontos += pontos;
		}

		printf("%d\n", 3*n-somaPontos);

	} while (1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
