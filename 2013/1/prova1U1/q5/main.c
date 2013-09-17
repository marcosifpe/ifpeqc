/*
 * main.c
 *
 *  Created on: 10/11/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>

rec(int a, int b) {
	if (a == b)
		return a;
	else
		return b + rec(a, b - 1);
}

int main(void) {
	int i, v1[] = {0, 1, 2, 3, 4, 5}, v2[] = {7, 6, 4, 3, 2, 1};


	for (i = 0; i < 5; ++i) {
		printf("%d ", rec(v1[4-i], v2[i]++));
	}

	return EXIT_SUCCESS;
}



