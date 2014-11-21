/*
 * q3.c
 *
 *  Created on: 20/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#define FRANQUIA 7

int main(void) {
	int n, s, i;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);
	scanf("%d", &n);

	while (n) {
		s = FRANQUIA;

		for (i = 11; i <= 30; ++i) {
			if (i > n)
				break;
			s += 1;
		}

		for (i = 31; i <= 100; ++i) {
			if (i > n)
				break;
			s += 2;
		}

		for (i = 101; ; ++i) {
			if (i > n)
				break;
			s += 5;
		}

		printf("%d.00\n", s);
		scanf("%d", &n);
		s = 0;
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


