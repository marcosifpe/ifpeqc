/*
 * q2.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned n, a, b, mult;
	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);

	scanf("%u", &n);

	while(n--) {
		mult = 0;
		scanf("%u %u", &a, &b);

		while (b--)
			mult += a;

		printf("%u\n", mult);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


