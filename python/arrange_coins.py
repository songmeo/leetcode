#!usr/bin/python3
class Solution:
	#naive way
	def arrangeCoins1(self, n: int) -> int:
		i = 0
		while n >= 0:
			i = i + 1
			n -= i
		return i - 1

	#binary search log(n), finding k so that k(k+1)/2 <= n
	def arrangeCoins(self, n: int) -> int:
		left, right = 0, n
		while left <= right:
			mid = (left + right) // 2
			cur = mid*(mid + 1) // 2
			if cur == n:
				return mid
			elif cur > n:
				right = mid - 1
			else:
				left = mid + 1
		return right 
		
if __name__ == '__main__':
	n = int(input())
	s = Solution()
	print(s.arrangeCoins(n))
