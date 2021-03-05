#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define cit(a) scanf("%d", &a);

void citireMatrice(char M[20][20], int *n)
{
	int i, j, k = 0;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			k = 0;
			while (!k)
			{
				k = 1;
				M[i][j] = getchar();
				if (M[i][j] >= 'a' && M[i][j] <= 'z')
					k = 0;
			}
		}
	}
}

	

int main()
{
	char M[20][20];
	int n;
	printf("n = "); cit(n);
	citireMatrice(M, &n);

	_getch();
	return 0;
}