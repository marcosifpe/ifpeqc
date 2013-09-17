/*
 * q1.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	int i, n, count;
	char *v, c;
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);
	scanf("%d", &n);
	v = (char*) malloc(sizeof(char)*n);

	for (i = 0; i < n; i++) {
		do {
			v[i] = getchar();
		} while (isspace(v[i]));
	}

	for (c = 'A'; c <= 'z'; ++c) {
		count = 0;
		for (i = 0; i < n; i++) {
			if (v[i] == c) {
				++count;
			}
		}

		if (count > 1) {
			printf("%c: %d\n", c, count);
		}
	}

	for (i = 0; i < n; i++) {
		printf("%c ", v[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

