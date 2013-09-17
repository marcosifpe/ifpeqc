#include <stdio.h>

int main(void) {
	double i, a1, q, spg;
	unsigned n;

	freopen("e5.txt", "r", stdin);
	freopen("s5.txt", "w", stdout);

	scanf("%lf %lf", &a1, &q);

	while (a1 && q) {
		scanf("%u", &n);
		spg = 0;

		for (i = 0; i < n; i++) {
			spg += a1;
			a1 *= q;
		}

		printf("%.2lf\n", spg);

		scanf("%lf %lf", &a1, &q);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
