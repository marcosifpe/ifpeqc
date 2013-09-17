/*
 * q19.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

int main(void) {
	int i, j = 1, x1, y1, x2, y2, n, x, y, cont;
	freopen("e19.txt", "r", stdin);
	freopen("s19.txt", "w", stdout);

	while (1) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
			break;
		scanf("%d", &n);
		for (i = 0, cont = 0; i < n; i++) {
			scanf("%d %d", &x, &y);

			if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
				cont += 1;
			}
		}

		printf("Teste %d\n%d\n\n", j++, cont);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
