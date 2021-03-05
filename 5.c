#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define cit(a) scanf("%d", &a);

void citireCuvant(char *c, int *n)
{
	int i;
	for (i = 0; i <= (*n); i++)
		c[i] = getchar();
}

void afisare(char *c, int n)
{
	int i;
	for (i = 0; i <= n; i++)
		putchar(c[i]);
}

void sortare(char *c, int *n)
{
	char aux;
	int i, j;
	for (i = 0; i <= (*n) - 1; i++)
	{
		for (j = i + 1; j <= (*n); j++)
		{
			if (c[i] > c[j])
			{
				aux = c[i];
				c[i] = c[j];
				c[j] = aux;
			}
		}
	}
}

void salvareFisierASCII(char *c, int n)
{
	FILE *f = fopen("ASCII_par.txt", "wt");
	if (f == NULL)
	{
		printf("Eroare la crearea fisierului.");
		exit(0);
	}
	int i, k = 0;
	for (i = 0; i <= n; i++)
	{
		if ((int)c[i] % 2 == 0)
		{
			k = 1;
			fprintf(f, "%c", c[i]);
		}
	}
	if (k)
		printf("Date salvate cu succes.");
}

int main()
{
	char *c;
	int n;
	printf("Introduceti dimensiunea cuvantului: "); cit(n);
	c = (char*)calloc(n, sizeof(char));
	citireCuvant(c, &n);
	afisare(c, n);
	printf("\nDupa sortare:");
	sortare(c, &n);
	afisare(c, n);
	salvareFisierASCII(c, n);
	_getch();
	return 0;
}