#include <cstdio>

using namespace std;

const int MAX_N = 21;
int n, k;
int x[MAX_N];
int ans = 0;

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void selectNumber(int id = 0, int cnt = 0, int sum = 0) {
	if (n - id < k - cnt) return;
	if (cnt == k) {
		if (isPrime(sum)) {
			++ans;
		}
		return;
	}
	if (id == n) return;
	selectNumber(id + 1, cnt, sum);
	selectNumber(id + 1, cnt + 1, sum + x[id + 1]);
}

void init() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
}

int main() {
	init();
	selectNumber();
	printf("%d\n", ans);
	return 0;
}
