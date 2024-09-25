#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - add to grid
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
}
