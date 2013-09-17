/*
 * q2.c
 *
 *  Created on: 28/12/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define T 61

void inverte(const char * orig, char * inv) {
	int i, j, len = (int) strlen(orig);
	inv[len] = '\0';

	for (i = 0, j = len - 1; i < len; ++i, --j) {
		inv[i] = orig[j];
	}
}

int main(void) {
	char orig[T], inv[T];
	int i;

	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);

	do {
		for (i = 0; i < T; i++) {
			scanf("%c", orig+i);
			if (orig[i] == '\n') {
				orig[i] = '\0';
				break;
			}
		}

		if (strcmp(orig, "Fim") == 0)
			break;
		inverte(orig, inv);
		printf("%s\n", inv);
	} while(true);

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
