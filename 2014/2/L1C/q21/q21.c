/*
 * q21.c
 *
 *  Created on: 08/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int somaRec(int a, int b, int c) {
	if (a == b) {
		return a % c == 0 ? a : 0;
	} else {
		return a % c == 0 ? a + somaRec(a - 1, b, c) : somaRec(a - 1, b, c);
	}
}

int main(void) {
	int a, b, c;
	freopen("e21.txt", "r", stdin);
	freopen("s21.txt", "w", stdout);
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", somaRec(a, b, c));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

