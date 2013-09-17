/*
 * q15.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int produto(int a, int b) {
	if (b == 1) {
		return a;
	} else {
		return a + produto(a, b - 1);
	}
}

int main(void) {
	int n, a, b;
	freopen("e15.txt", "r", stdin);
	freopen("s15.txt", "w", stdout);
	scanf("%d", &n);

	while(n--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", produto(a, b));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
