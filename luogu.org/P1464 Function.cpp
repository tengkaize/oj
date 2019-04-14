#include <cstdio>

#define ll long long

ll w(ll a, ll b, ll c) {
	static ll table[21][21][21] = {0};
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (table[a][b][c] == 0) {
		table[a][b][c] = (a < b && b < c
		? w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
		: w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
		);
	}
	return table[a][b][c];
}

int main() {
	ll a, b, c;
	while (true) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}
