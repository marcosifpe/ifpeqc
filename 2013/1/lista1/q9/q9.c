/*
 * q9.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

unsigned int fibonnaci(unsigned int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fibonnaci(n - 1) + fibonnaci(n - 2);
}

int main(void) {
	unsigned int a, b, i;
	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);

	scanf("%u %u", &a, &b);

	for (i = a; i < b; i++) {
		printf("%u ", fibonnaci(i));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

