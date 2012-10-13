#include <stdio.h>

int main(void) {
	int x, y, i, si = 0, sp = 0;

	freopen("e1.txt", "r", stdin);
	freopen("s1.txt", "w", stdout);

	scanf("%d %d", &x, &y);

	for (i = x; i <= y; i++) {
		if (i % 2) {
			si += i;
		} else {
			sp += i;
		}
	}

	printf("%d %d", si, sp);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
