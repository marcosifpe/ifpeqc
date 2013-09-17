/*
 * q2.c
 *
 *  Created on: 16/09/2013
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#define SOMA_ANGULOS 180
#define EQ 60

int main(void) {
	int a, b, c;
	freopen("e2.txt", "r", stdin);
	freopen("s2.txt", "w", stdout);

	do {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a + b + c != SOMA_ANGULOS) {
			printf("Triangulo inexistente\n");
		} else if (a == EQ && b == EQ && c == EQ) {
			printf("Equilatero");
		} else if (a == b || a == c || b == c) {
			printf("Isosceles");
		} else {
			printf("Escaleno");
		}
	} while(1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


