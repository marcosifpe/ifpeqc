/*
 * q14.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdbool.h>

bool primo(int x) {
	int i;

	for (i = 2; i < x/2 + 1; ++i) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}


int main(void) {
	int i, n, t, p1, p2;
	freopen("e14.txt", "r", stdin);
	freopen("s14.txt", "w", stdout);
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		p1 = 2;
		p2 = 3;

		while (p2 - p1 != n + 1) {
			p1 = p2;
			++p2;
			while (!primo(p2)) {
				++p2;
			}
		}

		for (i = p1 + 1; i < p2; ++i) {
			printf("%d ", i);
		}

		printf("\n");
	}

	fclose(stdin);
	return 0;
}

