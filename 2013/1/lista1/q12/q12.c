/*
 * q12.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
#define T 21

int main(void) {
	char v[T];
	int n, i;
	freopen("e12.txt", "r", stdin);
	freopen("s12.txt", "w", stdout);

	scanf("%d", &n);
	getchar();
	while (n--) {
		for (i = 0; i < T; i++) {
			v[i] = getchar();
			if (v[i] == '\n') {
				v[i] = '\0';
				break;
			}
		}

		for (i-=1; i >= 0; i--) {
			printf("%c", v[i]);
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
