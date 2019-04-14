#include <cstdio>

using namespace std;

int x0, y0, ans = 0;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	scanf("%d%d", &x0, &y0);
	for (int P = x0; P * P <= x0 * y0; P += x0) {
		if (x0 * y0 % P == 0 && gcd(P, x0 * y0 / P) == x0) {
			++ans;
		}
	}
	printf("%d\n", ans * 2);
	return 0;
}
