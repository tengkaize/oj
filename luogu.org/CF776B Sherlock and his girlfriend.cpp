#include <cstdio>
#include <cstring>

using namespace std;

bool v[100005];
void primes(int n) {
	memset(v, 0, sizeof(v));
	for (int i = 2; i <= n; ++i) {
		if (v[i]) continue;
		for (int j = i; j <= n / i; ++j) v[i * j] = true;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	primes(n + 1);
	printf("%d\n", n <= 2 ? 1 : 2);
	for (int i = 2; i <= n + 1; ++i) {
		printf("%d ", v[i] + 1);
	}
	printf("\n");
	return 0;
}
