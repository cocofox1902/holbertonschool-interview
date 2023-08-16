#!/usr/bin/python3
""" Pascal's Triangle module
"""


def pascal_triangle(n):
    """pascal_triangle function that returns a
    list of lists of integers
    """
    triangle = []

    if n <= 0:
        return triangle

    triangle.append([1])

    for i in range(1, n):
        level = [1]
        for j in range(1, i):
            level.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        level.append(1)
        triangle.append(level)

    return triangle
