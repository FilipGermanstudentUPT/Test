#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void citire(int *A, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("A[%d] = ", i);
		scanf("%d", &A[i]);
	}
	printf("\n");
}

int functiaPutere(int n, int a)
{
	int i, numarFinal = 1;
	for (i = 0; i < a; i++)
		numarFinal = numarFinal * n;
	return numarFinal;
}

int determinareNrBitiNecesari(int x)
{
	if (x <= functiaPutere(2, 4) - 1)
		return 4;
	else if (x <= functiaPutere(2, 8) - 1)
		return 8;
	else if (x <= functiaPutere(2, 12) - 1)
		return 12;
	else if (x <= functiaPutere(2, 16) - 1)
		return 16;
	else if (x <= functiaPutere(2, 20) - 1)
		return 20;
	else if (x <= functiaPutere(2, 24) - 1)
		return 24;
	else if (x <= functiaPutere(2, 28) - 1)
		return 28;
	else if (x <= functiaPutere(2, 32) - 1)
		return 32;
}

void transformareBinar(int x)
{
	int i, nrBiti, k, contorSpatiu = 0;
	nrBiti = determinareNrBitiNecesari(x) - 1;
	for (i = nrBiti; i >= 0; i--)
	{
		k = x >> i;
		if (k & 1)
			printf("1");
		else
			printf("0");
		contorSpatiu++;
		if (contorSpatiu == 4)
		{
			printf(" ");
			contorSpatiu = 0;
		}
	}
}

void inversareBinar(int x)
{
	int i, nrBiti, k, contorSpatiu = 0;
	nrBiti = determinareNrBitiNecesari(x) - 1;
	for (i = nrBiti; i >= 0; i--)
	{
		k = x >> i;
		if (k & 1)
			printf("0");
		else
			printf("1");
		contorSpatiu++;
		if (contorSpatiu == 4)
		{
			printf(" ");
			contorSpatiu = 0;
		}
	}
}

void afisareElementeBinar(int *A, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		transformareBinar(A[i]);
		printf("\n");
	}
	printf("\n");
}

void afisareElementeBinarInversate(int *A, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		inversareBinar(A[i]);
		printf("\n");
	}
	printf("\n");
}

int inversareBinarBiti(int x, int numarBiti)
{
	int i;
	for (i = 0; i < numarBiti; i++)
		x = x ^ (1 << i);               // ChangeFlag
	return x;
}

void afisareNumereInversateBinarBiti(int *A, int n)
{
	int i, numarBiti;
	for (i = 0; i < n; i++)
	{
		numarBiti = determinareNrBitiNecesari(A[i]);
		printf("%d ", inversareBinarBiti(A[i], numarBiti));
	}
}

int main()
{
	int N, *A;
	printf("N = "); scanf("%d", &N);
	A = (int*)malloc(sizeof(int) * N);

	citire(A, N);
	afisareElementeBinar(A, N);
	afisareElementeBinarInversate(A, N);
	afisareNumereInversateBinarBiti(A, N);


	_getch();
	return 0;
}