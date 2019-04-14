#include <cmath>
#include <cstdio>

using namespace std;

long long f[49] = {0, 1};

int main() {
	int n;
	scanf("%d", &n);
	for (register int i = 2; i <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	printf("%lld.00\n", f[n]);
	return 0;
}
