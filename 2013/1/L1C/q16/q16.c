/*
 * q16.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int somaRec(int a, int b, int c) {
	if (a == b)
		return (a % c == 0) ? a : 0;
	else
		return (a % c == 0) ? a + somaRec(a - 1, b, c) : somaRec(a - 1, b, c);
}

int main(void) {
	int a, b, c;
	freopen("e16.txt", "r", stdin);
	freopen("s16.txt", "w", stdout);
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", somaRec(a, b, c));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
