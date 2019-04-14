#include <cstdio>
#include <cstring>

using namespace std;

int n;
char num[80];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", num);
		if (num[strlen(num) - 1] % 2 /* equals (num[strlen(num) - 1] - '0') % 2*/)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}
