# use coin 1, 3, 4
import sys, math

def get_change(m):
    #write your code here
    min_coins = []
    min_coins.insert(0,0)
    for i in range(1, m + 1):
       min_coins.insert(i,math.inf)
       if i == 1 or i == 3 or i == 4:
           min_coins[i] = 1
           continue
       else:
           for c in [1,3,4]:
               val = min_coins[i - c] + 1
               if min_coins[i] > val:
                   min_coins[i] = val
    return min_coins[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
