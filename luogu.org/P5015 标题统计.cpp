#include <cstdio>
#include <cctype>

using namespace std;

int main() {
	int cnt = 0;
	char ch;
	while ((ch = getchar()) != EOF) {
		if (isalnum(ch)) {
			++cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
