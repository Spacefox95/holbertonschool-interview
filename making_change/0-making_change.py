#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """ Calculate the coins addition to reach total"""
    if total <= 0:
        return 0
    count = 0
    coins = sorted(coins)
    coins.reverse()
    for coin in coins:
        if (total // coin) > 0:
            count += total // coin
            total -= (total // coin) * coin
        if total == 0:
            return count
    return -1
