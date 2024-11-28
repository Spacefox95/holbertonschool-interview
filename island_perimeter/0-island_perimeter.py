#!/usr/bin/python3

def island_perimeter(grid: list[list[int]]) -> int:

	perimeter = 0
	rows, cols = len(grid), len(grid[0])

	for row in range(rows):
		for col in range(cols):
			if grid[row][col] == 1:
				if grid[row - 1][col] == 0 and row > 0:
					perimeter += 1
				if row == 0:
					perimeter += 1
				if grid[row +1][col] == 0 and row < rows - 1:
					perimeter += 1
				if grid[row][col - 1] == 0 and col > 0:
					perimeter += 1
				if col == 0:
					perimeter += 1
				if grid[row][col + 1] == 0 and col < cols -1:
					perimeter += 1
	return perimeter
