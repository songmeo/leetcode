# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    value_per_weight = [w/v for w, v in zip(weights, values)]
    value_per_weight, weights, values = zip(*sorted(zip(value_per_weight, weights, values), reverse=True))
    for v in value_per_weight:
        n = 0
        while capacity > n*v and n < values[value_per_weight.index(v)]:
            n = n + 1
        value = value + v*n
        capacity = capacity - (v/weights[value_per_weight.index(v)])*n
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
