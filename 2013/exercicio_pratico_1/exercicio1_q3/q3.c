#include <stdio.h>
#include <ctype.h>

#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define KELVIN 'K'
#define RANKINE 'R'

int main(void) {
	char und1, und2;
	double temp;
	freopen("e3.txt", "r", stdin);
	freopen("s3.txt", "w", stdout);

	scanf("%c", &und1);
	und1 = toupper(und1);

	while (und1 != 'E') {
		switch (und1) {
		case FAHRENHEIT:
			scanf("%lf", &temp);
			printf("%.2lf\n", (temp - 32) / 1.8); //F -> C
			break;
		case KELVIN:
			scanf("%lf", &temp);
			printf("%.2lf\n", temp - 273.15); //K -> C
			break;
		case RANKINE:
			scanf("%lf", &temp);
			printf("%.2lf\n", temp / 1.8 - 273.15); //R -> C
			break;
		case CELSIUS:
			do { //ignora espaços em branco
				scanf("%c", &und2);
			} while (isspace(und2));

			und2 = toupper(und2);
			scanf("%lf", &temp);

			if (und2 == FAHRENHEIT) {
				printf("%.2lf\n", temp * 1.8 + 32);
			} else if (und2 == KELVIN) {
				printf("%.2lf\n", temp + 273.15);
			} else if (und2 == RANKINE) {
				printf("%.2lf\n", (temp + 273.15)*1.8);
			}

			/* no break */
		}

		do { //ignora espaços em branco
			scanf("%c", &und1);
		} while (isspace(und1));

		und1 = toupper(und1);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

