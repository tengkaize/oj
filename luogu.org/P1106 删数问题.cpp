#include <cstdio>
#include <cstring>

using namespace std;

const int MaxNLen = 255;
char num[MaxNLen];

int main() {
	int k;
	scanf("%s%d", num, &k);
	int len = strlen(num);
	while (k--) {
		for (int i = 0; i < len - 1; ++i) {
			if (num[i] > num[i + 1]) {
				for (int j = i; j < len - 1; ++j) {
					num[j] = num[j + 1];
				}
				break;
			}
		}
		--len;
	}
	int p = 0;
	while (p < len && num[p] == '0') ++p;
	if (p == len) printf("0");
	else for (int i = p; i < len; ++i) {
		printf("%c", num[i]);
	}
	printf("\n");
	return 0;
}
