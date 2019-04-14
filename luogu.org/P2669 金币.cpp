#include <cstdio>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	int n, sum = 0;
	for (n = 1; k - n >= 0; k -= n++) {
		sum += n * n;
	}
	printf("%d\n", sum + k * n);
	return 0;
}
