/*
 * main.c
 *
 *  Created on: 11/11/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	int v[] = {2000, 17, 5}, i;

	for (i = 0; i < 3; i++) {
		v[0] %= v[1]++;
		v[2] += --v[0];
	}

	printf("%d", v[0]+v[1]+v[2]);

	return 0;
}
