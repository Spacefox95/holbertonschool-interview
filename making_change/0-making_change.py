#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """ Calculate the coins addition to reach total"""
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    def decount_loop(coins, total):
        count = 0
        remaining_total = total
        for coin in coins:
            coin_number = remaining_total // coin
            count += coin_number
            remaining_total -= coin_number * coin
            if remaining_total == 0:
                return count
        return -1

    initial_count = decount_loop(coins, total)

    if initial_count != -1:

        if len(coins) > 1:
            second_count = decount_loop(coins[1:], total)
            if second_count != -1 and second_count < initial_count:
                return second_count

    return initial_count
