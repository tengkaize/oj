#include <cstdio>
#include <algorithm>

inline constexpr int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int l[3];
    std::scanf("%d%d%d", &l[0], &l[1], &l[2]);
    std::sort(l, l + 3);
    printf("%d/%d", l[0] / gcd(l[0], l[2]), l[2] / gcd(l[0], l[2]));
    return 0;
}