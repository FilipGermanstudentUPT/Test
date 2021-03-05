#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define cit(a) scanf("%s", a);

typedef struct masina
{
	char model[30];
	int anAparitie;
}M;

int comparareAnAparitie(const void *a, const void *b)
{
	struct masina *ia = (struct masina*)a;
	struct masina *ib = (struct masina*)b;
	return (int)(ia->anAparitie - ib->anAparitie);
}

void citire(M *masina, int *n)
{
	(*n)++;
	printf("Model: "); cit((masina + *n)->model);
	int corect;

	do
	{
		corect = 1;
		printf("Anul aparitiei: "); scanf("%d", &(masina + *n)->anAparitie);
		if (!((masina + *n)->anAparitie >= 1950 && (masina + *n)->anAparitie <= 2020))
		{
			corect = 0;
			printf("Cerinte nerespectate.\n");
		}
	} while (!corect);
}

void afisare(M *masina, int *n)
{
	int i;
	for (i = 0; i <= (*n); i++)
		printf("%s %d\n", (masina + i)->model, masina[i].anAparitie);
	printf("\n");
}

void sortare_anAparitie(M *masina, int *n)
{
	qsort(masina, (*n) + 1, sizeof(M), comparareAnAparitie);
}

int main()
{
	M masina[30];
	int n = -1;
	citire(&masina[0], &n);
	citire(&masina[0], &n);
	citire(&masina[0], &n);
	afisare(masina, &n);
	sortare_anAparitie(masina, &n);
	afisare(masina, &n);
	_getch();
	return 0;
}