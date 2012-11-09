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


	while (y--) {
		while (1) {
			x += 1;
			if (x % 400 == 0) {
				printf("%d\n", x);
				break;
			} else if (x % 4 == 0 && x % 100 != 0) {
				printf("%d\n", x);
				break;
			}
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
