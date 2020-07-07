# Uses python3
import sys

def get_majority_element(a, left, right):
    if left == right:
        return -1
    if left + 1 == right:
        return a[left]
    #write your code here
    mid = (left + right) // 2
    first = get_majority_element(a, left, mid)
    second = get_majority_element(a, mid, right)
    #print(left, right, first, second)
    if first == second: # or second == -1:
    	return first
#    elif first == -1:
#    	return second
    else:
        sublist = a[left:right]
        f, s = sublist.count(first), sublist.count(second)
        if f > (right - left) / 2:
	        return first
        elif s > (right - left) / 2:
	        return second
        else:
                return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    result = get_majority_element(a, 0, n)
    if result != -1:
        print(1)
    else:
        print(0)
    #print(result)
