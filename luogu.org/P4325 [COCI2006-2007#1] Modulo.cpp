#include <set>
#include <cstdio>

using namespace std;

inline int getInt() {
	int v = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		v = v * 10 + ch - '0';
		ch = getchar();
	}
	return v;
}

inline void putInt(int v) {
	if (v < 0) {
		putchar('-');
		v = -v;
	}
	if (v >= 10) putInt(v / 10);
	putchar(v % 10 + '0');
}

int main() {
	set<int> s;
	for (register int i = 0; i < 10; ++i) {
		s.insert(getInt() % 42);
	}
	putInt(s.size());
	return 0;
}
