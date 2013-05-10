#include <stdio.h>
int f(int x) {
	int i = 0, s = 0;
	for (; i <= x; ++i) {
		s += i;
	}
	return s;
}

int main(void) {
	printf("%d", f(8));
	return 0;
}
