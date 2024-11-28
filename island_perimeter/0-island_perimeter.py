#!/usr/bin/python3

""" Algorithm to determine if the perimeter if island"""


def island_perimeter(grid: list[list[int]]) -> int:
    """ Main funciton """

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                print(grid[row][col])
                if row > 0 and grid[row - 1][col] == 0:
                    perimeter += 1
                if row == 0:
                    perimeter += 1
                if row < rows - 1 and grid[row + 1][col] == 0:
                    perimeter += 1
                if col > 0 and grid[row][col - 1] == 0:
                    perimeter += 1
                if col == 0:
                    perimeter += 1
                if col < cols - 1 and grid[row][col + 1] == 0:
                    perimeter += 1
    return perimeter
