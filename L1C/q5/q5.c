/*
 * q5.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */

#include <stdio.h>

#define PFA 0.0
#define PEA 100.0
#define PFM -38.83
#define PEM 356.73

int main(void) {
	int n;
	float k, c;
	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);
	scanf("%d", &n);

	while (n--) {
		scanf("%f", &k);
		if (k <= 0)
			continue;
		c = k - 273.15;

		printf("%.2f K: %.2f C\nH2O: ", k, c);

		//H2O
		if (c < PFA) {
			printf("solido");
		} else if (c > PEA) {
			printf("gasoso");
		} else {
			printf("liquido");
		}

		printf("\nHg: ");

		//Hg
		if (c < PFM) {
			printf("solido");
		} else if (c > PEM) {
			printf("gasoso");
		} else {
			printf("liquido");
		}

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
