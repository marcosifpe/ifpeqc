/*
 * main.c
 *
 *  Created on: 02/12/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	//int a = 0, b, c, n = 5; //original
	int a = 0, b, c, n = 4; //segunda chamada

	for (b = 1; b <= n; b++)
		for (c = b; c <= n; c++) {
			a = a + 1;
		}

	printf("%d", a);
	return 0;
}
