/*
 * main.c
 *
 *  Created on: 02/12/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	//int n = 10, c, r = 0, s = -1; //original
	int n = 10, c, r = 5, s = -1; //segunda chamada

	for (c = 1; c <= n; c++) {
		if (c % 2 == 0)
			r += c * s;
		else
			r += c;
	}

	printf("%d", r);
	return 0;
}
