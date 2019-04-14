#include <cstdio>
#include <algorithm>

using namespace std;

const int N3 = 1205;

int n;
char necklace[N3];

int getLeft(int k) {
	int cnt = 0;
	char ch = 0;
	for (int i = k; i > k - n; --i) {
		if (necklace[i] == 'w') ++cnt;
		else if (ch == 0) {
			ch = necklace[i];
			++cnt;
		}
		else if (ch == necklace[i]) ++cnt;
		else return cnt;
	}
	return cnt;
}

int getRight(int k) {
	int cnt = 0;
	char ch = 0;
	for (int i = k + 1; i <= k + n; ++i) {
		if (necklace[i] == 'w') ++cnt;
		else if (ch == 0) {
			ch = necklace[i];
			++cnt;
		}
		else if (ch == necklace[i]) ++cnt;
		else return cnt;
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	scanf("%s", necklace);
	for (int i = 0; i < n; ++i) {
		necklace[i + n + n] = necklace[i + n] = necklace[i]; 
	}
	necklace[3 * n] = 0;
	int ans = 0;
	for (int i = n + 1; i <= n + n; ++i) {
		ans = max(ans, getLeft(i) + getRight(i));
	}
	ans = min(ans, n);
	printf("%d\n", ans);
	return 0;
}
