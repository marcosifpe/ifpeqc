/*
 * q3.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, x;
	double n = 1, d = 2, soma = 0;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);
	scanf("%d", &x);

	for (i = 0; i < x; i++) {
		if (i % 2 == 0)
			soma += n / d;
		else
			soma -= n / d;

		n += 2;
		d += 3;
	}

	printf("%.8lf", soma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
