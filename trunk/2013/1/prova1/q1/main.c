/*
 * main.c
 *
 *  Created on: 09/05/2013
 *      Author: masc
 */
#include <stdio.h>

int f(int x) {
	if (x > 2)
		return x - f(x - 1) + f(x - 2) / 2;
	else
		return x + 1;
}

int main(void) {
	int i;
	for (i = 7; i > 4; i--)
		printf("%d", f(i));
	return 0;
}

