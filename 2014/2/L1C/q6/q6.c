/*
 * q6.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, s;
	freopen("e6.txt", "r", stdin);
	freopen("s6.txt", "w", stdout);
	scanf("%d", &n);

	while (n) {
		s = 0;

		while (n >= 50) {
			n -= 50;
			s += 1;
		}

		printf("%d ", s);
		s = 0;

		while (n >= 10) {
			n -= 10;
			s += 1;
		}

		printf("%d ", s);
		s = 0;

		while (n >= 5) {
			n -= 5;
			s += 1;
		}

		printf("%d ", s);
		s = 0;

		while (n >= 1) {
			n -= 1;
			s += 1;
		}

		printf("%d\n", s);
		scanf("%d", &n);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


