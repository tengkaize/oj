#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 100005, MaxNum = 1000005;
int n, maxnum = 0;
int a[MaxN];
int b[MaxNum];
int c[MaxNum];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		maxnum = max(maxnum, a[i]);
		++b[a[i]];
	}
	for (int i = 1; i <= maxnum; ++i) {
		if (b[i] == 0) continue;
		for (int j = i; j <= maxnum; j += i) {
			c[j] += b[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", c[a[i]] - 1);
	}
	return 0;
}
