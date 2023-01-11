#include "sandpiles.h"
#include <stdio.h>

/**
 * print_sandpile - prints sanpiles
 * @grid: sandpile
 * Return: No
 */
void print_sandpile(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - check stability
 * @firstGrid: first sandpile
 * @secondGrid: second sandpile
 * Return: 1 if stable
 */
int is_stable(int firstGrid[3][3], int secondGrid[3][3])
{
	int i;
	int j;
	int stable;

	stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			secondGrid[i][j] = firstGrid[i][j];
			if (firstGrid[i][j] > 3)
				stable = 0;
		}
	}

	return (stable);
}

/**
 * addition - add secondGrid to firstGrid
 * @firstGrid: first sandpile.
 * @secondGrid: second sandpile.
 * Return: no return.
 */
void addition(int firstGrid[3][3], int secondGrid[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			firstGrid[i][j] += secondGrid[i][j];
		}
	}
}

/**
 * repartitrice - repartitrice the number higher than 3
 * @firstGrid: first sandpile
 * @secondGrid: second sandpile
 * Return: No
 */
void repartitrice(int firstGrid[3][3], int secondGrid[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (secondGrid[i][j] > 3)
			{
				if (i > 0)
					firstGrid[i - 1][j] += 1;
				if (j < (3 - 1))
					firstGrid[i][j + 1] += 1;
				if (i < (3 - 1))
					firstGrid[i + 1][j] += 1;
				if (j > 0)
					firstGrid[i][j - 1] += 1;
				firstGrid[i][j] -= 4;
			}
		}
	}
}

/**
 * sandpiles_sum - add sandpiles and check if good
 * @firstGrid: first sandpile
 * @secondGrid: second sandpile
 * Return: No
 */
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3])
{
	addition(firstGrid, secondGrid);

	while (!is_stable(firstGrid, secondGrid))
	{
		print_sandpile(firstGrid);
		repartitrice(firstGrid, secondGrid);
	}
}
