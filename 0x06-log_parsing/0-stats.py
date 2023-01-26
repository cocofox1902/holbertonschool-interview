#!/usr/bin/python3
""" 0-stats.py - Log parsing stat """
import sys


stats = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
sizes = [0]


def print_stats():
    print("File size: {}".format(sizes))
    for status, count in sorted(stats.items()):
        if count != 0:
            print("{}: {}".format(status, count))

try:
    for i, line in sys.stdin:
        try:
            args = line.strip().split(" ")
            if len(args) == 9:
                if args[-2] in stats:
                    stats[args[-2]] += 1
                sizes += int(args[-1])
                count += 1
                if count % 10 == 0:
                    print("File size: {}".format(sizes))
                    for status, count in sorted(stats.items()):
                        if count != 0:
                            print("{}: {}".format(status, count))
        except Exception:
            pass
        if i % 10 == 0:
            print_stats()
    print_stats()
except KeyboardInterrupt:
    print_stats()
    raise
