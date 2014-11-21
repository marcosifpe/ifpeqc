/*
 * q10.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int a,  int b) {
	int i, m;
	for (i = 0, m = 0; i < a; i++)
		m += b;

	return m;
}

int  exponenciacao(int  base,  int expoente) {
	int i, e = 1;

	for (i = 1; i <= expoente; i++)
		e = multiplicacao(base, e);

	return e;
}

int main(void) {
	int a, b;
	freopen("e10.txt", "r", stdin);
	freopen("s10.txt", "w", stdout);
	scanf("%d %d", &a, &b);

	while (a && b) {
		printf("%d\n", exponenciacao(a, b));
		scanf("%d %d", &a, &b);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


