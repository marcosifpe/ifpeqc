/*
 * q1.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, n, t;
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &t);
		for (i = 0; i < 10; i++) {
			printf("%dx%d = %d\n", t, i, t*i);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
