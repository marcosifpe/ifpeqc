/*
 * q25.c
 *
 *  Created on: 03/11/2012
 *      Author: masc
 */
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
#define T 21

int getLen(char str1[]) {
	int i;
	for (i = 0; i < T; ++i) {
		if (str1[i] == '\0')
			break;
	}

	return i;
}

bool ehSubstring(char str1[], char str2[]) {
	bool result = false;
	int i, j, k, lenStr1, lenStr2;

	lenStr1 = getLen(str1);
	lenStr2 = getLen(str2);

	for (i = 0; i < lenStr2; ++i) {
		for (j = 0, k = i, result = true; j < lenStr1; ++j, ++k) {
			if (str1[j] != str2[k]) {
				result = false;
				break;
			}
		}

		if (result)
			break;
	}

	return result;
}

int main(void) {
	unsigned n;
	char s1[T], s2[T];
	freopen("e25.txt", "r", stdin);
	freopen("s25.txt", "w", stdout);
	scanf("%u", &n);

	while(n--) {
		scanf("%s", s1);
		scanf("%s", s2);

		//if (strstr(s2, s1) != NULL) {
		if (ehSubstring(s1, s2)) {
			printf("%s eh substring de %s\n", s1, s2);
		} else {
			printf("%s nao eh substring de %s\n", s1, s2);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}




