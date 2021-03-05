#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int functiaPutere(int n, int a)
{
	int i, numarFinal = 1;
	for (i = 0; i < a; i++)
		numarFinal = numarFinal * n;
	return numarFinal;
}

int main()
{
	int i, k, contorSpatiu = 0, nrBiti_1 = 0, n;

	printf("n = "); scanf("%d", &n);
	while (n < 0 || n>255)
	{
		printf("Numarul zecimal trebuie sa apartina intervalului [0,255]. Introduceti din nou:\n");
		printf("n = "); scanf("%d", &n);
	}

	for (i = 7; i >= 0; i--)
	{
		k = n >> i;
		if (k & 1)
		{
			printf("1");
			nrBiti_1++;
		}
		else
			printf("0");
		contorSpatiu++;
		if (contorSpatiu == 4)
		{
			printf(" ");
			contorSpatiu = 0;
		}
	}
	printf(" %d\n", n);
	
	contorSpatiu = 0;
	for (i = 0; i < 8; i++)
	{
		if (i < nrBiti_1)
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

	int numarInversat = 0;
	for (i = 7; i > 7 - nrBiti_1; i--)
		numarInversat = numarInversat + functiaPutere(2, i);
	printf(" %d", numarInversat);

	_getch();
	return 0;
}

/*

6. Se citeste de la tastatura un numar zecimal pana in 255. Sa se afiseze forma binara a numarului iar apoi din sirul binar sa se genereze valoarea maxima

*/