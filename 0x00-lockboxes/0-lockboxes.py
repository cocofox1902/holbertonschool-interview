#!/usr/bin/python3
"""
Lockboxes
"""


def canUnlockAll(boxes):
    '''canUnlockAll'''
    open = [0]
    for i in open:
        for box in boxes[i]:
            if box not in open:
                if box < len(boxes):
                    open.append(box)
    if len(open) == len(boxes):
        return True
    return False
