#include <cstdio>

using namespace std;

int sub1(int n) {
	return n / 10000 % 10 * 100 + n / 1000 % 10 * 10 + n / 100 % 10;
}
int sub2(int n) {
	return n / 1000 % 10 * 100 + n / 100 % 10 * 10 + n / 10 % 10;
}
int sub3(int n) {
	return n / 100 % 10 * 100 + n / 10 % 10 * 10 + n % 10;
}

int main() {
	int k;
	scanf("%d", &k);
	bool found = false;
	for (int i = 10000; i <= 30000; ++i) {
		if (sub1(i) % k == 0 && sub2(i) % k == 0 && sub3(i) % k == 0) {
			printf("%d\n", i);
			found = true;
		}
	}
	if (!found) printf("No\n");
	return 0;
}

