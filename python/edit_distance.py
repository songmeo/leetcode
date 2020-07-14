# Uses python3
def edit_distance(s, t):
    #write your code here
   dist = [[0 for i in range(len(s))] for j in range(len(t))]
   for i in range(1, len(s) + 1):
   	for j in range(1, len(t) + 1):
   	    ins = dist[0][j - 1]
    return 0

if __name__ == "__main__":
    print(edit_distance(input(), input()))
