# python3
import sys

def compute_min_refills(distance, tank, stops):
    # write your code here
    ans = 0
    curr = 0
    if tank > distance:
        return 0
    if distance - stops[-1] > tank:
        return -1
    for i in range (2, len(stops)):
        if stops[i] - stops[i - 1] > tank:
            return -1

    while curr + tank < distance:
        curr = max([s for s in stops if s <= tank + curr])
        ans = ans + 1
    return ans

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))
