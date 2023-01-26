#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
from sys import stdin

total_size = 0
status_codes = {code: 0 for code in [
    "200", "301", "400", "401", "403", "404", "405", "500"]}
count = 0

try:
    for line in stdin:
        try:
            args = line.strip().split(" ")
            if len(args) == 9:
                if args[-2] in status_codes:
                    status_codes[args[-2]] += 1
                total_size += int(args[-1])
                count += 1
                if count % 10 == 0:
                    print("File size: {}".format(total_size))
                    for status, count in sorted(status_codes.items()):
                        if count != 0:
                            print("{}: {}".format(status, count))
        except ValueError:
            pass
except KeyboardInterrupt:
    pass

print("File size: {}".format(total_size))
for status, count in sorted(status_codes.items()):
    if count != 0:
        print("{}: {}".format(status, count))
