import sys

def lcs2(a, b):
    #write your code here
    n, m = len(a), len(b)
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    for i in range(1, n + 1):
    	for j in range(1, m + 1):
    	    dp[i][j] = max(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
    	    if a[i-1] == b[j-1]:
    	    	dp[i][j] = dp[i][j] + 1
    return dp[n][m]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
