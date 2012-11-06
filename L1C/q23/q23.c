/*
 * q23.c
 *
 *  Created on: 06/11/2012
 *      Author: masc
 */
#include <stdio.h>
#define T 3

void lerMatriz(int m[][T]) {
	int i, j;
	for (i = 0; i < T; ++i) {
		for (j = 0; j < T; ++j) {
			scanf("%d ", &m[i][j]);
		}
	}
}

int main(void) {
	int m[T][T], sdp, sds;
	freopen("e23.txt", "r", stdin);
	freopen("s23.txt", "w", stdout);
	lerMatriz(m);
	sdp = m[0][0] * m[1][1] * m[2][2];
	sdp += m[0][1] * m[1][2] * m[2][0];
	sdp += m[0][2] * m[1][0] * m[2][1];
	sds = m[0][2] * m[1][1] * m[2][0];
	sds += m[0][0] * m[1][2] * m[2][1];
	sds += m[0][1] * m[1][0] * m[2][2];
	printf("%d", sdp - sds);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

