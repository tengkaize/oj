#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10005;

int n;
int x, y;

int rmap[N][N];
int hmap[N][N];
bool honly[N];

void floyed(int (&map)[N][N]) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
}

void init() {
	memset(hmap, 0x3F, sizeof(hmap));
	memset(rmap, 0x3F, sizeof(rmap));
	memset(honly, 0, sizeof(honly));

	int m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	int ho;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &ho);
		honly[ho] = true;	
	}
	
	int a, b, c;
	for (int i = 1; i <= n; ++i) {
		hmap[i][i] = rmap[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		hmap[a][b] = hmap[b][a] = c;
		if (!honly[a] && !honly[b])
			rmap[a][b] = rmap[b][a] = c;
	}
	
	scanf("%d%d", &x, &y);
}

int main() {
	init();
	floyed(hmap);
	floyed(rmap);
	int	htg = hmap[1][x],
		htd = hmap[1][y],
		hfgtd = hmap[x][y],
		hfdtg = hmap[y][x],
		rtg = rmap[1][x],
		rtd = rmap[1][y],
		rfgtd = rmap[x][y],
		rfdtg = rmap[y][x];
	printf("%d\n", min(
		htg + rtd, min(
		rtg + htd, min(
		htg + hfgtd, min(
		htd + hfdtg, min(
		rtg + rfgtd,
		rtd + rfdtg
		)))))
	);
	return 0;
}
