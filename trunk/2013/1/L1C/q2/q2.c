/*
 * q2.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, n;
	float x, r, mult;
	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);
	scanf("%f %f %d", &x, &r, &n);

	printf("(");
	for (i = 0, mult = 1.0; i < n; ++i) {
		if (i)
			printf(",");
		printf("%.2f", x * mult);
		mult *= r;
	}
	printf(")");

	fclose(stdin);
	fclose(stdout);
	return 0;
}
