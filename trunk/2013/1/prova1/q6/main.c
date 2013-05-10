/*
 * main.c
 *
 *  Created on: 09/05/2013
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	char c = 'D';

	while (c < 'L') {
		if (!(c % 2))
			c++;
		else
			c += 5;
		printf("%c", c);
	}

	return 0;
}
