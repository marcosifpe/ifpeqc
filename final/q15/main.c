#include <stdio.h>

int main(void) {
	int i, j, s = 0;
	int m[3][3] = {{0,1,0},{1,1,1},{1,0,1}};
	int n[3][3] = {{1,0,1},{1,0,1},{1,1,1}};
	int o[3][3];

	for(i = 0; i < 3; i++) {
		for (j = 0; j < 3; ++j) {
			if (j % 2)
				o[i][j] = m[i][j];
			else
				o[i][j] = n[i][j];
		}
	}

	for(i = 0; i < 3; i++) {
		for (j = 0; j < 3; ++j) {
			s += o[i][j];
		}
	}

	printf("%d", s);
	return 0;
}
