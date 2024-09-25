#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - add to grid.
 * @grid1: first grid
 * @grid2: second grid to add
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
	while ((!stable_grid(grid1)))
	{
		printf("=\n");
		print_topple(grid1);
		topple(grid1);
	}
}

/**
 * topple - Reduce the value of index if > 4
 * @grid1: the grid to topple
 */

void topple(int grid1[3][3])
{
	int x, y;

	int grid_tmp[3][3] = {{0, 0, 0},
						  {0, 0, 0},
						  {0, 0, 0}};

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{

			if (grid1[x][y] >= 4)
			{
				grid_tmp[x][y] -= 4;

				if (x - 1 >= 0)
					grid_tmp[x - 1][y] += 1;

				if (x + 1 < 3)
					grid_tmp[x + 1][y] += 1;

				if (y - 1 >= 0)
					grid_tmp[x][y - 1] += 1;

				if (y + 1 < 3)
					grid_tmp[x][y + 1] += 1;
			}
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid_tmp[x][y];
		}
	}
}

/**
 * stable_grid - check that every element of the grid is < 4
 * @grid1: the grid to check
 * Return: 0 if the grid is unstable, 1 if stable
 */

int stable_grid(int grid1[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] >= 4)
				return (0);
		}
	}
	return (1);
}

/**
 * print_topple - display the grid
 * @grid: the grid to display
 */

void print_topple(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y > 0)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}
