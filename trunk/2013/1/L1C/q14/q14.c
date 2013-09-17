/*
 * q14.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int multiplicacao(int x, int y) {
	int m = 0;
	while (y--) {
		m += x;
	}

	return m;
}

int exponenciacao(int base, int expoente) {
	int exp = 1;

	while (expoente--) {
		exp = multiplicacao(base, exp);
	}

	return exp;
}

int main(void) {
	int a, b;
	freopen("e14.txt", "r", stdin);
	freopen("s14.txt", "w", stdout);

	do {
		scanf("%d %d", &a, &b);
		if (!a && !b)
			break;
		printf("%d\n", exponenciacao(a, b));
	} while (1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
