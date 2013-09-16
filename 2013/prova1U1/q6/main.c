/*
 * main.c
 *
 *  Created on: 10/11/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	char c = 'A';

	while (c < 'L') {
		if (!(c % 2))
			c++;
		else
			c += 5;
		printf("%c", c);
	}

	return 0;
}

