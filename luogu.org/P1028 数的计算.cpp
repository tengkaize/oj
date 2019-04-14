#include <cstdio>

using namespace std;

const int MaxN = 1005;
int f[MaxN];

int main() {
	int n;
	scanf("%d", &n);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (i % 2 ? f[i - 1] : f[i - 1] + f[i >> 1]);
	}
	printf("%d\n", f[n]);
	return 0;
}
