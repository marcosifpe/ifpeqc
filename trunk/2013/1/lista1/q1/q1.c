/*
 * q1.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned n, x, p;
	double s = 0, sp = 0;
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);

	scanf("%u", &n);

	while(n--) {
		scanf("%u %u", &x, &p);
		sp += p;
		s += x * p;
	}

	printf("%.5lf", s/sp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

