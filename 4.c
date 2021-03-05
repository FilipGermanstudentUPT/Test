#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void citire(int *A, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			printf("A[%d] = ", i);
			scanf("%d", &A[i]);
		}
		else
			A[i] = A[i - 1] + 1;
	}
}

void afisare(int *A, int n)
{
	int k = 0, i, j;
	for (i = 0; i < n; i++)
	{
		printf("%d in baza 2 este = ",A[i]);
		for (j = 31; j >= 0; j--)
		{
			k = A[i] >> j;
			if (k & 1)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}

void stergerePrimulElement(int *A, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		A[i] = A[i + 1];
	afisare(A, n - 1);
}

void salvareFisier(int *A, int n)
{
	FILE *f = fopen("multime_noua.txt", "wt");
	int i, k = 0;
	
	if (f == NULL)
	{
		printf("Eroare la fisier!");
		exit(0);
	}
	for (i = 0; i < n - 1; i++)
	{
		k = 1;
		fprintf(f, "%d ", A[i]);
	}
	if (k)
		printf("Datele s-au salvat cu succes.");
	else
		printf("Multimea este vida.");
}

int main()
{
	int A[50], n;
	printf("n = "); scanf("%d", &n);
	citire(A, n);
	afisare(A, n);
	printf("\nStergere:\n\n");
	stergerePrimulElement(A, n);
	salvareFisier(A, n);
	_getch();
	return 0;
}