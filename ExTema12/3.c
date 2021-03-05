#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define cit(a) scanf("%d", &a);

typedef struct masina
{
	char model[30];
	int anAparitie;
}M;

int cmp_AnAparitie(const void *a, const void *b)
{
	struct masina *ia = (struct masina*)a;
	struct masina *ib = (struct masina*)b;
	return (ia->anAparitie - ib->anAparitie);
}

void citire(M *masina, int *n)
{
	(*n)++;
	printf("Model: "); scanf("%s", (masina + *n)->model);
	int corect = 0;
	while (!corect)
	{
		printf("Anul aparitiei: "); scanf("%d", &(masina + *n)->anAparitie);
		if ((masina + *n)->anAparitie < 1950 || (masina + *n)->anAparitie > 2020)
			printf("Anul aparitiei trebuie sa fie intre 1950 si 2020. Va rog introduceti datele din nou.\n"); 
		else
			corect = 1;
	}
}

void afisare(M *masina, int *n)
{
	int i;
	for (i = 0; i <= (*n); i++)
		printf("%s %d\n", (masina + i)->model, (masina + i)->anAparitie);
}

int main()
{
	M masina[30];
	int n = -1, optiune, continuare = 1;
	
	printf("0. Iesire\n");
	printf("1. Adaugarea unei masini noi(anul de aparitie al masinii trebuie sa fie cuprins in intervalul 1950-2020)\n");
	printf("2. Afisarea masinilor din parcul auto\n");
	printf("3. Afisarea masinilor in ordine crescatoare dupa anul aparitiei\n\n");

	while (continuare)
	{
		printf("Optiunea dvs: "); cit(optiune);
		switch (optiune)
		{
			case 0:
			{
				continuare = 0;
				break;
			}
			case 1:
			{
				citire(&masina[0], &n);
				printf("\n");
				continuare = 1;
				break;
			}
			case 2:
			{
				afisare(masina, &n);
				printf("\n");
				continuare = 1;
				break;
			}
			case 3:
			{
				qsort(masina, n + 1, sizeof(M), cmp_AnAparitie);
				afisare(masina, &n);
				printf("\n");
				continuare = 1;
				break;
			}
			default:
			{
				printf("Optiune invalida\n\n");
				continuare = 1;
				break;
			}
		}
	}
	_getch();
	return 0;
}