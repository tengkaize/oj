#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxMN = 51;
int mat[MaxMN][MaxMN];
int f[MaxMN][MaxMN][MaxMN][MaxMN];

int max4(int i1, int i2, int i3, int i4) {
	return max(max(i1, i2), max(i3, i4));
}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 1; i <= m; ++i)
	for (int j = 1; j <= n; ++j)
	for (int k = 1; k <= m; ++k)
	for (int l = 1; l <= n; ++l) {
		f[i][j][k][l] = max4(
			f[i - 1][j][k - 1][l],
			f[i - 1][j][k][l - 1],
			f[i][j - 1][k - 1][l],
			f[i][j - 1][k][l - 1]
		) + mat[i][j] + mat[k][l];
		if (i == k && j == l) f[i][j][k][l] -= mat[k][l];
	}
	printf("%d\n", f[m][n][m][n]);
	return 0;
}
