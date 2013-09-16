/*
 * main.c
 *
 *  Created on: 10/11/2012
 *      Author: masc
 */
#include <stdio.h>

int f(int x) {
	int i = 0, s = 0;

	for (; i <= x; ++i) {
		s += i;
	}

	return s;
}

int main(void) {
	printf("%d", f(5));
	return 0;
}

