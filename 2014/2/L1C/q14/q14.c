/*
 * q7.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, n, tn, s;
	freopen("e14.txt", "r", stdin);
	freopen("s14.txt", "w", stdout);

	scanf("%d", &n);

	while (n) {
		tn = n * (n+1) / 2;
		printf("T%d=%d", n, tn);

		for (i = 1, s = 0; i < tn / 2 + 1; i++) {
			if (tn % i == 0)
				s += i;
		}

		if (s == tn) {
			printf(" perfeito\n");
		} else {
			printf(" imperfeito\n");
		}

		scanf("%d", &n);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
