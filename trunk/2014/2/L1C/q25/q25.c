#include <stdio.h>
#include "produto.h"

int main(void) {
	int n, a, b;
	freopen("e25.txt", "r", stdin);
	freopen("s25.txt", "w", stdout);

	scanf("%u", &n);

	while (n--) {
		scanf("%u %u", &a, &b);
		printf("%u\n", produto(a, b));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

