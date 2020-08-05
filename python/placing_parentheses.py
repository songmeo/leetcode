# Uses python3
def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def MinMax(i, j, op, m, M):
    min_i = 99999
    max_i = -99999
    for k in range(i, j):
        a = evalt(M[i][k], M[k+1][j], op[k])
        b = evalt(M[i][k], m[k+1][j], op[k])
        c = evalt(m[i][k], M[k+1][j], op[k])
        d = evalt(m[i][k], m[k+1][j], op[k])
        min_i = min(min_i, a, b, c, d)
        max_i = max(max_i, a, b, c, d)
    return (min_i,max_i)

def get_maximum_value(dataset):
    #write your code here
    op = dataset[1:len(dataset):2]
    d = dataset[0:len(dataset)+1:2]
    n = len(d)
    m = [[0 for i in range(n)] for j in range(n)]
    M = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
    	m[i][i] = int(d[i])
    	M[i][i] = int(d[i])
    for s in range(1,n):
        for i in range(n-s):
            j = i + s
            m[i][j], M[i][j] = MinMax(i,j,op,m,M)
    return M[0][n-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
