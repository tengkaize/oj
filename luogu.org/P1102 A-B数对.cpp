#include <cstdio>
#include <map>

using namespace std;

const int MaxN = 200005;
map<int, int> mp;
int t[MaxN];

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		++mp[t[i]];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += mp[t[i] - c];
	}
	printf("%lld\n", ans);
	return 0;
}
