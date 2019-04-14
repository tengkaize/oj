#include <cstdio>

using namespace std;

int n, m;
int w[10005];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
	}
	
	int time = 0;
	int p = m + 1;
	while (p <= n + m) {
		for (int i = 1; i <= m; ++i) {
			if (--w[i] == 0) w[i] = w[p++];
		}
		++time;
	}
	
	printf("%d\n", time);
	
	return 0;
}
