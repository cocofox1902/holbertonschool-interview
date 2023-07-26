#!/usr/bin/python3

def island_perimeter(grid):
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Check left cell
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                # Check above cell
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
