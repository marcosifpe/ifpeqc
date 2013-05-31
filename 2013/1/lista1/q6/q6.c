/*
 * q6.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <math.h>
#define T 9

int main(void) {
	unsigned numero, n, divisor, cociente, v[T], i = 0;
	freopen("e6.txt", "r", stdin);
	freopen("s6.txt", "w", stdout);

	scanf("%u", &n);

	while (n--) {
		scanf("%u", &numero);
		i = 0;
		divisor = 1000;

		while (divisor) {
			cociente = numero / divisor;
			v[i++] = cociente;
			numero -= cociente * divisor;
			divisor /= 10;
		}

		i = 0;
		while (i < 4) {
			printf("%u ", v[i++]);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

