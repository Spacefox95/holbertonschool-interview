#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 3, 4], 6))

print(makeChange([1256, 54, 48, 16, 102], 1453))
