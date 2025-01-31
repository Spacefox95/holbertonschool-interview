#!/usr/bin/python3
""" Algorithm to calculate the retained wated between walls"""


def rain(walls):
    """ Function to calculate the water retained"""
    if not walls:
        return 0

    x = len(walls)
    left_max = [0] * x
    right_max = [0] * x
    count = 0

    left_max[0] = walls[0]
    for i in range(1, x):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[x - 1] = walls[x - 1]
    for i in range(x - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    for i in range(x):
        count += min(left_max[i], right_max[i]) - walls[i]

    return count
