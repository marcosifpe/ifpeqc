/*
 * q10.c
 *
 *  Created on: 31/05/2013
 *      Author: masc
 */

#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {
	if (y == 0)
		return x;
	else
		return mdc(y, x % y);
}

int main(void) {
	int a, b;
	freopen("e10.txt", "r", stdin);
	freopen("s10.txt", "w", stdout);

	do {
		scanf("%d %d", &a, &b);

		if (a || b) {
			printf("mdc(%d, %d): %d\n", a, b, mdc(a, b));
		}
	} while (a || b);


	fclose(stdin);
	fclose(stdout);
	return 0;
}

