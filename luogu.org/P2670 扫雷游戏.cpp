#include <cstdio>

using namespace std;

bool b[105][105];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char s[2];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%1s", s);
			b[i][j] = (s[0] == '*');
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			putchar(b[i][j] ? '*' : (
				b[i - 1][j] +
				b[i + 1][j] +
				b[i][j - 1] +
				b[i][j + 1] +
				b[i - 1][j - 1] +
				b[i - 1][j + 1] +
				b[i + 1][j - 1] +
				b[i + 1][j + 1] +
				'0'
			));
		}
		putchar('\n');
	}
	return 0;
}

