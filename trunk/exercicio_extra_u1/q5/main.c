/*
 * main.c
 *
 *  Created on: 02/12/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	//int cont = 1, r = 0;
	int cont = -4, r = 0;
	do {
		r += cont;
		cont += 4;
	} while (cont <= 5);

	printf("%d e %d", r, cont);
	return 0;
}


