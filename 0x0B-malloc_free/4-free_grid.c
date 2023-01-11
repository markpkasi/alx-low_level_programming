#include <stdlib.h>

/**
 * free_grid - free the grid
 * @grid: grid of memories
 * @height: int
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int = 0;

	for (; i < height; i++)
		free(grid[i]);
	free(grid);
}
