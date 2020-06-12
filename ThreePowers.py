#
# ~oisín~ Python3 Template
#

import sys
import math
import statistics
import datetime
import collections

powers = []

def fill_powers():
    powers.append(1)
    for _ in range(50):
        powers.append(powers[len(powers)-1] * 3)

def main():
    fill_powers()
    while True:
        n = int(input())
        if(n == 0):
            return 0
        n -= 1
        n = bin(n)
        bitset = str(n)
        bitset = bitset[2:]
        bitset = bitset[::-1]
        ans = []
        for i in range(len(bitset)):
            if bitset[i] == '1':
                ans.append(powers[i])
        print("{ ", end = '')
        for x in ans:
            if(x == ans[len(ans)-1]):
                print(x, end=" ")
            else:
                print(x, end=", ")
        print("}")

if __name__ == '__main__':
    main()
