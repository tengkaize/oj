#include <cstdio>
#include <functional>

using namespace std;

const int Mod = 10000;

int sigma_mod(int b, int e, function<int(int)> f, int mod) {
	int ret = 0;
	for (int i = b; i <= e; ++i) {
		ret = (ret + f(i) % mod) % mod;
	}
	return ret;
}

int qkpow(int b, int p, int m) {
	int ret = 1;
	while (p) {
		if (p & 1) {
			ret = ret * b % m;
		}
		b = b * b % m;
		p >>= 1;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", sigma_mod(1, a, bind(qkpow, placeholders::_1, b, Mod), Mod));
	}
	return 0;
}
