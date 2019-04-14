#include <cstdio>
#include <string>

using namespace std;

string div(int n, int p = 0, string s = "") {
	if (!n) return "0";
	do {
		if (n & 1) {
			s = (p == 1 ? "2" : "2(" + div(p) + ")") + (s == "" ? "" : "+") + s;
		}
		++p;
	} while(n >>= 1);
	return s;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%s\n", div(n).c_str());
	return 0;
}
