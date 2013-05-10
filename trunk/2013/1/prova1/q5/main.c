/*
 * main.c
 *
 *  Created on: 09/05/2013
 *      Author: masc
 */
#include <stdio.h>
int f(int x) {
	int i = 0, s = 0;
	for (; i <= x; ++i) {
		if (i + 1 == x)
			continue;
		s -= i;
	}
	return s;
}

int main(void) {
	printf("%d", f(7));
	return 0;
}

