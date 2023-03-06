#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size = pow(3, level);
	int i, j, k, l;
	char c;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			c = '#';
			for (k = i, l = j; k > 0 || l > 0; k /= 3, l /= 3)
			{
				if (k % 3 == 1 && l % 3 == 1)
				{
					c = ' ';
					break;
				}
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
