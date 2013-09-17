/*
 * q4.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, n, div, v[] = {100, 50, 20, 10, 5, 2, 1};
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	while (1) {
		scanf("%d", &n);

		if (n < 0)
			break;

		if (n == 0)
			printf("Saque invalidado");
		else
			for (i = 0; i < 7; i++) {
				div = n / v[i];
				n %= v[i];

				if (div) {
					printf("%dx%d", div, v[i]);
					if (n)
						printf("+");
				}
			}


		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
