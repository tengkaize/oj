#include <cstdio>
#include <algorithm>

using namespace std;

int t, m;
int v[105], u[105];
int f[10005];

int main() {
	scanf("%d%d", &t, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &v[i], &u[i]);
	}
	
	for (int i = 1; i <= m; ++i) {
		for (int j = t; j >= v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + u[i]);
		}
	}
	
	printf("%d\n", f[t]);
	
	return 0;
}
