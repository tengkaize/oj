#include <cstdio>

using namespace std;

const int MaxN = 1e7 + 5;
int n, a, b, c, d, x[MaxN];

int countBit(int n) {
    n = (n & 0x55555555) + ((n >> 1)  & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2)  & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4)  & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8)  & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

int main() {
	scanf("%d%d%d%d%d%d", &n, &a, &b, &c, &d, &x[0]);
	for (int i = 1; i <= n; ++i) {
		x[i] = (a * x[i - 1] * x[i - 1] + b * x[i - 1] + c) % d;
	}
	int e = 0;
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= u - 1; ++v) {
			e += countBit(x[u] ^ x[v]) & 1;
		}
	}
	printf("%d\n", e);
    return 0;
}
