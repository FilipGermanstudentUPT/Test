#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int determinareBiti_1(int n)
{
	int i, k = 0, contorBiti_1 = 0;
	for (i = 31; i >= 0; i--)
	{
		k = n >> i;
		if (k & 1)
			contorBiti_1++;
	}
	return contorBiti_1;
}

int sumaBiti(int n)
{
	int i, s = 0;
	for (i = 1; i <= n; i++)
		s = s + determinareBiti_1(i);
	return s;
}

int main()
{
	unsigned int n;

	printf("n = "); scanf("%d", &n);
	printf("Suma bitilor fiecarui numar de la 1 la %d este %d", n, sumaBiti(n));

	_getch();
	return 0;
}