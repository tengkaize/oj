#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MaxN = 105;
int n, h;
int f[MaxN], d[MaxN], t[MaxN];

struct Pool {
	int fish;
	int num;
	Pool(int f, int n): fish(f), num(n) { }
};

bool cmp(const Pool& p1, const Pool& p2) {
	return p1.fish < p2.fish;
}

int main() {
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &f[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d", &t[i]);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		priority_queue<Pool, vector<Pool>, bool(*)(const Pool&, const Pool&)> que(cmp);
		int time = 60 * h;
		for (int j = 1; j < i; ++j) {
			time -= 5 * t[j];
		}
		for (int j = 1; j <= i; ++j) {
			que.push(Pool(f[j], j));
		}
		int sum = 0;
		while (!que.empty()) {
			Pool p = que.top();
			time -= 5;
			if (time < 0) break;
			sum += p.fish;
			que.pop();
			if (p.fish - d[p.num] > 0)
				que.push(Pool(p.fish - d[p.num], p.num));
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	
	return 0;
}

