/*
 * q8.c
 *
 *  Created on: 21/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int raio, a, l, p;
	freopen("e8.txt", "r", stdin);
	freopen("s8.txt", "w", stdout);
	scanf("%d", &raio);

	while (raio) {
		scanf("%d %d %d", &a, &l, &p);

		if (a * l * p >= raio * 2)
			printf("S\n");
		else
			printf("N\n");

		scanf("%d", &raio);
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


