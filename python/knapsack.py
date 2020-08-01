# Uses python3
import sys

def optimal_weight(W, w):
    # write your code here
    result = 0
    dp = [[0 for weight in range(0, W + 1)] for item in range(0, len(w) + 1)]
    for i in range(1, len(w) + 1):
        for j in range(1, W + 1):
            dp[i][j] = dp[i - 1][j]
            if w[i-1] <= j:
                val = dp[i-1][j-w[i-1]] + w[i-1]
                if val > dp[i][j]:
                    dp[i][j] = val
    return dp[len(w)][W]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
