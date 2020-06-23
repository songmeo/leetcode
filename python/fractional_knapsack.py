# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    value_per_weight = [v/w for v, w in zip(values, weights)]
    value_per_weight, weights, values = zip(*sorted(zip(value_per_weight, weights, values), reverse=True))
    i = 0
    for v in value_per_weight:
        n = 0
        while capacity > 0 and n < weights[i]:
            n = n + 1
            capacity = capacity - 1
    #   print(f'n {n} ')
        value = value + v*n
        i = i + 1
    # for l in [value_per_weight, weights, values]: print(*l)
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
