/*
 * q9.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int x, y;
	freopen("e9.txt", "r", stdin);
	freopen("s9.txt", "w", stdout);
	scanf("%d %d", &x, &y);
	x += 1;

	while (y--) {
		while (1) {
			if (x % 400 == 0) {
				printf("%d\n", x);
				x += 1;
				break;
			} else if (x % 4 == 0 && x % 100 != 0) {
				printf("%d\n", x);
				x += 1;
				break;
			}

			x += 1;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
