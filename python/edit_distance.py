# Uses python3
def edit_distance(s, t):
    #write your code here
   n, m = len(s), len(t)
   dist = [[0 for j in range(m)] for i in range(n)]
   for i in range(n):
   	dist[i][0] = i
   for j in range(m):
   	dist[0][j] = j
   for j in range(1,m):
   	for i in range(1,n):
   	    insert = dist[i][j-1] + 1
   	    delete = dist[i-1][j] + 1
   	    match = dist[i-1][j-1]
   	    mismatch = dist[i-1][j-1] + 1
   	    if s[i] == t[j]:
   	        dist[i][j] = min(insert, delete, match)
   	    else:
   	        dist[i][j] = min(insert, delete, mismatch)
   return dist[n-1][m-1]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
