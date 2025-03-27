#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([20], 20))

print(makeChange([1256, 102, 54, 16, 1], 197))
