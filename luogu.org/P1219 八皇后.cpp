#include <cstdio>

using namespace std;

const int MaxN = 105;
int row[MaxN];
bool col[MaxN], major[MaxN], minor[MaxN];
int n, cnt = 0;

void printans() {
	++cnt;
	if (cnt <= 3) {
		for (int i = 1; i <= n; ++i) {
			printf("%d ", row[i]);
		}
		putchar('\n');
	}
}

void Queen(int i) {
	if (i > n) {
		printans();
		return;
	}
	for (int j = 1; j <= n; ++j) {
		if (!col[j] && !major[i + j] && !minor[i - j + n]) {
			row[i] = j;
			col[j] = true;
			major[i + j] = true;
			minor[i - j + n] = true;
			Queen(i + 1);
			col[j] = false;
			major[i + j] = false;
			minor[i - j + n] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	Queen(1);
	printf("%d\n", cnt);
	return 0;
}

