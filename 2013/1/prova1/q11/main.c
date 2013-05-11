/*
 * main.c
 *
 *  Created on: 10/05/2013
 *      Author: masc
 */

#include <stdio.h>
int main(void) {
	int cont = 1, r = 0;
	do {
		r += cont;
		cont += 5;
		if (cont > 6)
			break;
	} while (1);
	printf("%d e %d", r, cont);
	return 0;
}
