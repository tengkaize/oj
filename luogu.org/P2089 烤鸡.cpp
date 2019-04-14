#include <cstdio>

using namespace std;

int anscnt = 0, ans[10001][11];
int n;

void dfs(int k, int s) {
	static int f[11];
	if (k > 10) {
		if (s == n) {
			++anscnt;
			for (int i = 1; i <= 10; ++i) {
				ans[anscnt][i] = f[i];
			}
		}
		return;
	}
	if (s >= n) return;
	for (int i = 1; i <= 3; ++i) {
		f[k] = i;
		dfs(k + 1, s + i);
	}
}

int main() {
	scanf("%d", &n);
	dfs(1, 0);
	printf("%d\n", anscnt);
	for (int i = 1; i <= anscnt; ++i) {
		for (int j = 1; j <= 10; ++j) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
