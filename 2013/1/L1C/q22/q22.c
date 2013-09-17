/*
 * q22.c
 *
 *  Created on: 02/11/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 21

void inverte(char orig[], char inv[]) {
	int i = 0, j, fim;

	while(orig[i] != '\0') {
		++i;
	}

	fim = i;
	inv[fim] = '\0';

	for (i = fim - 1, j = 0; i >= 0; --i, ++j) {
		inv[j] = orig[i];
	}
}

int main(void) {
	char orig[MAX], inv[MAX];
	unsigned int n, i;
	freopen("e22.txt", "r", stdin);
	freopen("s22.txt", "w", stdout);

	scanf("%u", &n);
	getchar();
	for (i = 0; i < n; ++i) {
		scanf("%21s", orig);
		inverte(orig, inv);
		printf("%s\n", inv);
	}

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}



