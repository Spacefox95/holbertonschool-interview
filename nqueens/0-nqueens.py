#!/usr/bin/python3
"""N Queens Puzzle Solver"""

import sys


def print_usage_and_exit(message, status):
    """Print error message and exit"""
    print(message)
    sys.exit(status)


def is_safe(board, row, col, n):
    """Check if a queen can be placed at board[row][col] safely"""
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n):
    """Backtracking algorithm to solve the N queens problem"""

    def backtrack(row, board):
        if row == n:
            result = [[r, board[r]] for r in range(n)]
            solutions.append(result)
            return
        for col in range(n):
            if is_safe(board, row, col, n):
                board[row] = col
                backtrack(row + 1, board)

    solutions = []
    board = [-1] * n
    backtrack(0, board)
    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print_usage_and_exit("Usage: nqueens N", 1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print_usage_and_exit("N must be a number", 1)

    if N < 4:
        print_usage_and_exit("N must be at least 4", 1)

    for solution in solve_nqueens(N):
        print(solution)
