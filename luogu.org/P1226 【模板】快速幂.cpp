#include <cstdio>

using namespace std;

typedef long long tint64;

tint64 PowerMod(tint64 b, tint64 p, tint64 k) {
	tint64 res = 1;
	b %= k;
	while (p) {
		if (p & 1) {
			res = (res * b) % k;
		}
		p >>= 1;
		b = (b * b) % k;
	}
	return res % k;
}

int main() {
	tint64 b, p, k;
	scanf("%lld%lld%lld", &b, &p, &k);
	printf("%lld^%lld mod %lld=%lld", b, p, k, PowerMod(b, p, k));
	return 0;
}
