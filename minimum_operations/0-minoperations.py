#!/usr/bin/python3

""" 
Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    """Calculate the min operations"""
    if n < 2:
        return 0
    f = 2
    while n % f != 0:
        f += 1

    return f + minOperations(n // f)
