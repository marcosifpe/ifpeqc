/*
 * main.c
 *
 *  Created on: 02/12/2012
 *      Author: masc
 */
#include <stdio.h>

int main(void) {
	//int total = 0, conta; //original
	int total = -10, conta; //segunda chamada

	for(conta = 2; conta <= 20; conta += 2)
		total += conta;

	printf("%d", total);
	return 0;
}

