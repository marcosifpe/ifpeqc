/*
 * q20.c
 *
 *  Created on: 08/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {
	if (y == 0)
		return x;
	else
		return mdc(y, x % y);
}

int mmc(int x, int y) {
	return x * y / mdc(x, y);
}

int mmm(int x, int y) {
	return mmc(x, y) + mdc(x, y);
}

int main(void) {
	int x, y;
	freopen("e20.txt", "r", stdin);
	freopen("s20.txt", "w", stdout);

	scanf("%d %d", &x, &y);
	while(x && y) {
		printf("%d\n", mmm(x,y));
		scanf("%d %d", &x, &y);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

