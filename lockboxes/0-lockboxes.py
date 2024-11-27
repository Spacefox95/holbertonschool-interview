"""
Algorithm to check if all the boxes can be opened
"""


def canUnlockAll(boxes: list[list]):
    n = len(boxes)
    unlocked = {0}
    to_explore = [0]

    while to_explore:
        i = to_explore.pop(0)

        for key in boxes[i]:
            if key not in unlocked and key < n:
                unlocked.add(key)
                to_explore.append(key)
    
    if n == len(unlocked):
        return True
    
    else:
        return False
