#!/usr/bin/python3
"""0x03. Minimum Operations"""


def minOperations(n):
    """
            calc min operations to reach n
    """
    if n <= 1:
        return 0

    index = 2
    count = 0
    while index <= n:
        if n % index == 0:
            count += index
            n /= index
        else:
            index += 1
    return count