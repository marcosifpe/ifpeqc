/*
 * q7.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

int main(void) {
	char c, texto[MAX];
	int i, sa = 0, s = 0, palavras = 0;
	freopen("e7.txt", "r", stdin);
	freopen("s7.txt", "w", stdout);
	c = getchar();
	getchar();
	gets(texto);

	for (i = 0; i < strlen(texto); ++i) {
		if (texto[i] == c) {
			s = sa + 1;
		}

		if (texto[i] == ' ') {
			palavras += 1;
			sa += s;
		}
	}

	palavras += 1;

	printf("%.1lf%%", 100.0 * s / palavras);
	fclose(stdin);
    fclose(stdout);
    return 0;
}

