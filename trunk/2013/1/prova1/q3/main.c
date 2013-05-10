/*
 * main.c
 *
 * Prova Branca
 *
 *  Created on: 09/05/2013
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	int v[] = { 1000, 47, 5 }, i;

	for (i = 0; i < 3; i++) {
		v[0] %= v[1]++;
		v[2] += --v[0];
	}

	printf("%d", v[0] + v[1] + v[2]);

	return 0;
}

