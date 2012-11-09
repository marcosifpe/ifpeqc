/*
 * q17.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int mdc(int x, int y) {
	if (y == 0)
		return x;
	else
		return mdc(y, x%y);
}

int main(void) {
	int x, y;
	freopen("e17.txt", "r", stdin);
	freopen("s17.txt", "w", stdout);

	scanf("%d %d", &x, &y);
	printf("%d", mdc(x, y));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
