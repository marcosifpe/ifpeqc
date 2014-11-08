/*
 * q23.c
 *
 *  Created on: 08/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 20

void ler(char palavra[]) {
	int i;
	char c;

	for (i = 0; (c = getchar()) != '\n'; i++) {
		palavra[i] = c;
	}

	palavra[i] = '\0';
}

void inverter(char palavra[]) {
	int i;

	for (i = strlen(palavra) - 1; i >= 0; i--) {
		printf("%c", palavra[i]);
	}

	printf("\n");
}

int main(void) {
	char palavra[T + 1];
	int n;
	freopen("e23.txt", "r", stdin);
	freopen("s23.txt", "w", stdout);

	scanf("%d", &n);
	getchar();

	for (; n; n--) {
		ler(palavra);
		inverter(palavra);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

