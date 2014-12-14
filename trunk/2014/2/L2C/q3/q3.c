#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);
	int t, n, i, j;
	char ** seqs;

	scanf("%d", &t);
	seqs = (char**) malloc(sizeof(char*) * t);

	if (seqs == NULL) {
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		seqs[i] = (char*) malloc(sizeof(char) * (n + 1));

		if (seqs[i] == NULL) {
			exit(EXIT_FAILURE);
		}

		scanf("%s", seqs[i]);
	}

	for (i = t - 1; i >= 0; i--) {
		for (j = 0; seqs[i][j] != '\0'; j++) {
			switch (toupper(seqs[i][j])) {
				case 'A':
				case 'B':
				case 'C':
					seqs[i][j] = '2';
					break;
				case 'D':
				case 'E':
				case 'F':
					seqs[i][j] = '3';
					break;
				case 'G':
				case 'H':
				case 'I':
					seqs[i][j] = '4';
					break;
				case 'J':
				case 'K':
				case 'L':
					seqs[i][j] = '5';
					break;
				case 'M':
				case 'N':
				case 'O':
					seqs[i][j] = '6';
					break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					seqs[i][j] = '7';
					break;
				case 'T':
				case 'U':
				case 'V':
					seqs[i][j] = '8';
					break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					seqs[i][j] = '9';
					break;
				default:
					break;
			}
		}

		printf("%s", seqs[i]);
		if (i)
			printf(", ");
	}

	printf("\n");

	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}
