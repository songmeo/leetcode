import sys

def get_change(m):
    #write your code here
    c = 0
    while m > 0:
        if m >= 10:
            m = m - 10
        elif m >= 5:
            m = m - 5
        elif m >= 1:
            m = m - 1
        c = c + 1
    return c

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
