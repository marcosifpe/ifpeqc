/*
 * q3.c
 *
 *  Created on: 16/09/2013
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);
	int n, h, c1;
	double c2;

	scanf("%d", &n);

	for (h = 1; h <= n; h++) {
		for (c1 = h - 1; c1 > 0; c1--) {
			c2 = sqrt(h * h - c1 * c1);

			if (c2 == (int) c2) {
				printf("%d %.0lf %d\n", h, c2, c1);
				break;
			}
		}
	}

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}

