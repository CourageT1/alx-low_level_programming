#!/usr/bin/python3
"""Defines an island perimeter measuring function."""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    :param grid: A list of list of integers representing the island.
    :return: The perimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0
    
    perimeter = 0
    
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4  # Each land cell contributes 4 to the perimeter
                
                # Check adjacent cells
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Deduct 2 for the shared edge with the upper cell
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Deduct 2 for the shared edge with the left cell
    
    return perimeter
