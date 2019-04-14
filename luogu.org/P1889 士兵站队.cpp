#include <cstdio>
#include <algorithm>

using namespace std;

inline int abs(int x) {
	return x < 0 ? -x : x;
}

const int MaxN = 10005;
int n;
int x[MaxN], y[MaxN];

int sum(int xm, int ym) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum = sum + abs(x[i] - xm) + abs(y[i] - ym); 
	}
	return sum;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; ++i) {
		x[i] -= i;
	}
	sort(x + 1, x + n + 1);
	printf("%d\n", n % 2 ? sum(x[n / 2 + 1], y[n / 2 + 1]) : sum((x[n / 2] + x[n / 2 + 1]) / 2, (y[n / 2] + y[n / 2 + 1]) / 2));
	
	return 0;
}
