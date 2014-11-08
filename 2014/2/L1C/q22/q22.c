/*
 * q22.c
 *
 *  Created on: 21/10/2014
 *      Author: MASC
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 23

void selection_sort(int num[], int tam)
{
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
   {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j] < num[min]) {
        min = j;
      }
    }
    if (i != min) {
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}

int main(void) {
	freopen("e22.txt", "r", stdin);
	freopen("s22.txt", "w", stdout);
	int v[T], max, n, i, j;
	srand(time(0));

	scanf("%d %d", &max, &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < T; j++) {
			v[j] = rand() % max + 1;
		}

		selection_sort(v, T);

		for (j = 0; j < T; j++)
			printf("%d ", v[j]);

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
