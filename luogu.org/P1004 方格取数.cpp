#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 10;
int mat[MaxN][MaxN];
int f[MaxN][MaxN][MaxN][MaxN];

int max4(int i1, int i2, int i3, int i4) {
	return max(max(i1, i2), max(i3, i4));
}

int main() {
	int n;
	scanf("%d", &n);
	int x, y, num;
	while (scanf("%d%d%d", &x, &y, &num) && (x != 0 || y != 0 || num != 0)) {
		mat[x][y] = num;
	}
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	for (int k = 1; k <= n; ++k)
	for (int l = 1; l <= n; ++l) {
		f[i][j][k][l] = max4(
			f[i - 1][j][k - 1][l],
			f[i - 1][j][k][l - 1],
			f[i][j - 1][k - 1][l],
			f[i][j - 1][k][l - 1]
		) + mat[i][j] + mat[k][l];
		if (i == k && j == l) f[i][j][k][l] -= mat[k][l];
	}
	printf("%d\n", f[n][n][n][n]);
	return 0;
}
