#include <cstdio>

using namespace std;

bool isPrime(int n) {
//	if (n < 2) return false;
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
	for (int i = 2; i <= n - 4; ++i) {
		for (int j = i; j <= n - 4; ++j) {
			int k = n - i - j;
			if (isPrime(i) && isPrime(j) && isPrime(k)) {
				printf("%d %d %d\n", i, j, k);
				return 0;
			}
		}
	}
	return 0;
}
