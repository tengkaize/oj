#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 205;
int n;
bool b[MaxN][MaxN];
bool s[MaxN];
int ans = 0;
bool anss[MaxN];

void Search(int k, int num) {
	if (num + n - k < ans) return;
	if (k == n) {
		if (num > ans) {
			ans = num;
			memcpy(anss, s, sizeof(bool) * (n + 1));
		}
	}
	for (int i = k + 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (s[j] && b[j][i]) {
				Search(i, num);
				return;
			}
		}
		s[i] = true;
		Search(i, num + 1);
		s[i] = false;
	}
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		b[u][v] = b[v][u] = true;
	}
	Search(0, 0);
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", (int)anss[i]);
	}
	return 0;
}

