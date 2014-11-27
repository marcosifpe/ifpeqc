/*
 * q24.c
 *
 *  Created on: 08/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <string.h>
#define T 21

int main() {
	int n;
	char str[T], sub_str[T];
	freopen("e24.txt", "r", stdin);
	freopen("s24.txt", "w", stdout);
	scanf("%d" , &n);
	getchar();
	while (n--) {
		scanf("%s", sub_str);
		scanf("%s", str);
		if (strstr(str, sub_str) != NULL)
			printf("%s eh substring de %s\n", sub_str, str);
		else
			printf("%s nao eh substring de %s\n", sub_str, str);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

