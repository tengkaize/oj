#include <cstdio>

constexpr int primes[] = {
#include "P1217.txt"
};

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); ++i) {
		if (primes[i] < a) continue;
		if (primes[i] > b) break;
		printf("%d\n", primes[i]); 
	}
	return 0;
}
