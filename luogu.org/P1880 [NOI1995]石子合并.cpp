#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_2N = 101 * 2;
int n;
int a[MAX_2N], sum[MAX_2N];
int fmax[MAX_2N][MAX_2N], fmin[MAX_2N][MAX_2N];

void init() {	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	memset(fmin, 0x3F, sizeof(fmin));
	memset(fmax, 0x00, sizeof(fmax));
	for (int i = 1; i <= n * 2; ++i) {
		sum[i] = sum[i - 1] + a[i];
		fmin[i][i] = fmax[i][i] = 0;
	}
}

void dp() {
	for (int L = 2; L <= n; ++L) {
		for (int s = 1; s <= n * 2 - L + 1; ++s) {
			int e = s + L - 1;
			for (int k = s; k < e; ++k) {
				fmin[s][e] = min(fmin[s][e], fmin[s][k] + fmin[k + 1][e] + sum[e] - sum[s - 1]);
				fmax[s][e] = max(fmax[s][e], fmax[s][k] + fmax[k + 1][e] + sum[e] - sum[s - 1]);
			}
		}
	}
}

void ans() {
	int ansmin = 0x7FFFFFFF, ansmax = 0;
	for (int i = 1; i <= n; ++i) {
		ansmin = min(ansmin, fmin[i][i + n - 1]);
		ansmax = max(ansmax, fmax[i][i + n - 1]);
	}
	printf("%d\n%d\n", ansmin, ansmax);
}

int main() {
	init();
	dp();
	ans();
	
	return 0;
}
