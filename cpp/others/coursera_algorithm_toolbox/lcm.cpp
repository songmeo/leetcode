#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int GCD(int a, int b) {
	if(a != 0 && b != 0) {
		return GCD(b, a % b);
	}
	return a == 0 ? b : a;
}

long long lcm_fast(int a, int b) { //a = 6, b = 8
	int gcd = GCD(a, b);
	return (long long) a * b / gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
