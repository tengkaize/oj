#include <cstdio>

using namespace std;

long long pow10[] = {
1,
10,
100,
1000,
10000,
100000,
1000000,
10000000,
100000000,
1000000000,
10000000000,
100000000000,
1000000000000
};

inline int len(long long n) {
	int res = 0;
	do {
		++res;
		n /= 10;
	} while (n);
	return res;
}

int main() {
	int Q;
	scanf("%d", &Q);
	long long l, r;
	int ans;
	while (Q--) {
		ans = 0;
		scanf("%lld%lld", &l, &r);
		for (long long i = l; i <= r; ++i) {
			ans += (i % 9) * (pow10[len(i)] % 9);
			ans %= 9;
		}
		printf("%d\n", ans % 9);
	}
	return 0;
}
