#include <cstdio>

using namespace std;

int divcnt(int num) {
	int cnt = 0;
	while (num) {
		if (num % 10 == 2) ++cnt;
		num /= 10;
	}
	return cnt;
}

int main() {
	int l, r;
	scanf("%d%d", &l, &r);
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		cnt += divcnt(i);
	}
	printf("%d\n", cnt);
	return 0;
}
