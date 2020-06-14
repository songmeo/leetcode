#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
int fibonacci(int n, long long m) {
	int first = 0, second = 1;
	for(int i = 0; i < n; i++) {
		int tmp = (first + second) % m;
		first = second;
		second = tmp;
	}
	return first;
}

int period(long long m) {
	int i = 2;
	while(true) {
		if(fibonacci(i, m) == 0 && fibonacci(i + 1, m) == 1) {
			break;
		}
		i++;
	}
	return i;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	return fibonacci(n % period(m), m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
