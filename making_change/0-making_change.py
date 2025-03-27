#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """ Calculate the coins addition to reach total"""
    if total <= 0:
        return 0
    count = 0
    coins = sorted(coins, reverse=True)
    for coin in coins:
        if (total // coin) > 0:
            coin_number = total // coin
            count += coin_number
            total -= coin_number * coin
            print(f"Using {coin_number} coins of {coin}, remaining total: {total}, coins used: {count}")
        if total == 0:
            print(f"Final count: {count}")
            return count
    return -1
