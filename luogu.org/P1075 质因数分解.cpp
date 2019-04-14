#include <cstdio>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i * i <= n; ++i) {
		if (isPrime(i) && n % i == 0 && isPrime(n / i)) {
			printf("%d\n", n / i);
			return 0;
		}
	}
	return 0;
}
