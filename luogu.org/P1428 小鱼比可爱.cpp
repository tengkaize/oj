#include <cstdio>

using namespace std;

int cute[105], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &cute[i]);
		int cnt = 0;
		for (int j = 1; j < i; ++j) {
			if (cute[j] < cute[i]) {
				++cnt;
			}
		}
		printf("%d ", cnt);
	}
	printf("\n");
	
	return 0;
}
