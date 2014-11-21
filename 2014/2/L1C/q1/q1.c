/*
 * q1.c
 *
 *  Created on: 20/11/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	double x, y, z;
	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);
	scanf("%d", &n);

	while (n--) {
		scanf("%lf %lf %lf", &x, &y, &z);
		x *= z;
		y *= z;
		printf("%.2lf %.2lf\n", x, y);
		printf("%.2lf%%\n", x > y ? 100* (1.0 - y / x) : 100* (1.0 - x / y));
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}


