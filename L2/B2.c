#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	
#include <conio.h>
#include <stdlib.h>

void citire(int *A, int *N)
{
	int i;
	for (i = 0; i < *N; i++)
	{
		printf("A[%d] = ", i);
		scanf("%d", &A[i]);
	}
}

void afisareDupaVariabilaC(int *A, int N, int C)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (1 & (A[i] >> C))
			printf("%d ", A[i]);
	}
}

int main()
{
	int C, N, *A;

	printf("C = "); scanf("%d", &C);
	while (C < 0 || C>7)
	{
		printf("Variabila C trebuie sa apartina intervalului [0,7]. Introduceti din nou:\n");
		printf("C = "); scanf("%d", &C);
	}
	printf("N = "); scanf("%d", &N);
	A = (int*)malloc(sizeof(int) * N);

	citire(A, &N);
	afisareDupaVariabilaC(A, N, C);
	
	_getch();
	return 0;
}

/*

2. Se citeste de la tastatura un numar C cu valori posibile intre 0-7. Dupa citirea numarului "C"
se vor citi de la tastatura "N" numere iar acele numere care au in reprezentarea lor binara, bitul 
de pe pozitia "C" cu valoare 1, se vor afisa

*/