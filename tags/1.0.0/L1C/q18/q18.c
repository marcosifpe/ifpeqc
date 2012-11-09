/*
 * q18.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */
#include <stdio.h>

int fibonnacci(int n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fibonnacci(n - 1) + fibonnacci(n - 2);
}

int main(void) {
	int i, j, s, fib;
	freopen("e18.txt", "r", stdin);
	freopen("s18.txt", "w", stdout);
	scanf("%d", &i);

	for (j = 0, s = 0; j <= i; ++j) {
		if (j)
			printf("+");

		fib = fibonnacci(j);
		printf("%d", fib);
		s += fib;
	}

	printf("=%d", s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



