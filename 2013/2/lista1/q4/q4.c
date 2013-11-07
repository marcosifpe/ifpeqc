/*
 * q4.c
 *
 *  Created on: 06/11/2013
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num, div;
	freopen("e4.txt", "r", stdin);
	freopen("s4.txt", "w", stdout);

	scanf("%d", &num);

	do {
		printf("%d: ", num);
		div = num;
		while (div) {
			if (!(num % div)) {
				printf("%d", div);
				if (div != 1) {
					printf(", ");
				}
			}
			div--;
		}
		printf("\n");
		scanf("%d", &num);
	} while (num);


	fclose(stdin);
	fclose(stdout);
	return 0;
}


