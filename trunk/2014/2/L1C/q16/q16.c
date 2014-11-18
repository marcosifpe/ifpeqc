/*
 * q16.c
 *
 *  Created on: 18/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

double fibonnacci(double n) {
	if (n == 0 || n == 1)
		return n;
	else
		return fibonnacci(n - 1) + fibonnacci(n - 2);
}

int main(void) {
	int i;
	double n, s;
	freopen("e16.txt", "r", stdin);
	freopen("s16.txt", "w", stdout);
	scanf("%lf", &n);

	for (i = 0, s = 0; ; i++) {
		s += fibonnacci(i);
		if (fibonnacci(i) == n)
			break;
	}

	printf("%i %.0lf\n", i + 1, s);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
