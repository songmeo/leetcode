# Uses python3
def edit_distance(s, t):
    #write your code here
   n, m = len(s), len(t)
   dist = [[0 for j in range(m+1)] for i in range(n+1)]
   for i in range(n+1):
   	dist[i][0] = i
   for j in range(m+1):
   	dist[0][j] = j
   for j in range(1,m+1):
   	for i in range(1,n+1):
   	    insert = dist[i][j-1] + 1
   	    delete = dist[i-1][j] + 1
   	    match = dist[i-1][j-1]
   	    mismatch = dist[i-1][j-1] + 1
   	    if s[i-1] == t[j-1]:
   	        dist[i][j] = min(insert, delete, match)
   	    else:
   	        dist[i][j] = min(insert, delete, mismatch)
   return dist[n][m]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
