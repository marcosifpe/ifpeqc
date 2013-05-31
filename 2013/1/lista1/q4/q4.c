/*
 * q4.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b, primo, i, s = 0;
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%d %d", &a, &b);

	for (;a <= b; a++) {
		primo = (a == 1) ? 0 : 1;

		for (i = 2; i < a; i++) {
			if (a % i == 0) {
				primo = 0;
				break;
			}
		}

		if (primo) {
			if (s) {
				printf(", ");
			}

			s += a;
			printf("%d", a);
		}
	}

	printf("\nsoma: %d\n", s);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


