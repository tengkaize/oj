#include <cstdio>

using namespace std;

long long n, m, a;

inline long long divceil(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &a);
	printf("%lld\n", divceil(n, a) * divceil(m, a));
	return 0;
}
