/*
 * main.c
 *
 *  Created on: 10/11/2012
 *      Author: masc
 */

#include <stdio.h>
int f(int x) {
	if (x >= 2)
		return x - f(x - 1) / 2 + f(x - 2);
	else
		return x + 1;
}

int main(void) {
	int i;
	for (i = 6; i >= 2; i-=2)
		printf("%d", f(i));
	return 0;
}
