#include "menger.h"
#include <stdio.h>

/**
 * menger - Draws a 2D representation of the Menger sponge
 * @level: The level of the Menger sponge to draw
 *
 * Return: Nothing
 */
void menger(int level)
{
	int size;
	int i, j;
	int x, y;
	int print;
	int pow;

	if (level < 0)
		return;

	size = 1;
	for (pow = 0; pow < level; pow++)
		size *= 3;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			print = 1;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					print = 0;
					break;
				}
				x /= 3;
				y /= 3;
			}

			putchar(print ? '#' : ' ');
		}
		putchar('\n');
	}
}
