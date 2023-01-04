#!/usr/bin/python3
"""
file creation minOperations
"""


def minOperations(n):
    """
    method minOperations
    """
    if n == 1 or n == 0:
        return 0

    i = 2
    count = 0

    while n > 1:
        if n % i == 0:
            n = n / i
            count += i
        else:
            i += 1
    return count
