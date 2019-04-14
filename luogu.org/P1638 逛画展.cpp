#include <cstdio>
#include <cstring>

using namespace std;

void readInt(int& a) {
	a = 0;
	int ch;
	while ((ch = getchar()) < '0' && ch > '9')
		;
	while (ch >= '0' && ch <= '9')
		a = (a << 1) + (a << 3) + (ch - '0'), ch = getchar();
}

const int MaxN = 1000005;
const int MaxM = 2005;
int n, m;
int pic[MaxN];
int bucket[MaxM];

inline bool check() {
	bool res = true;
	for (int i = 1; i <= m; ++i) {
		res = res && bucket[i];
	}
	return res;
}

int ans = 0;
bool judge(int r) {
	memset(bucket, 0, sizeof(bucket));
	for (int i = 1; i <= r; ++i) {
		++bucket[pic[i]];
	}
	if (check()) {
		ans = 1;
		return true;
	}
	for (int i = 2; i <= n - r + 1; ++i) {
		--bucket[pic[i - 1]];
		++bucket[pic[i + r - 1]];
		if (check()) {
			ans = i;
			return true;
		}
	}
	return false;
}

int main() {
	readInt(n);
	readInt(m);
	for (int i = 1; i <= n; ++i) {
		readInt(pic[i]);
	}
	int l = m, r = n, mid, len;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (judge(mid)) {
			len = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d %d\n", ans, ans + len - 1);
	return 0;
}
