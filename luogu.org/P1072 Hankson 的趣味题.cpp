#include <cstdio>

namespace {

constexpr int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

}  // namespace

int main() {
    using namespace std;
    int n;
    scanf("%d", &n);
    while (n--) {
        int a0, a1, b0, b1;
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        int x, i = 1;
        int ans = 0;
        for (; i * i < b0; ++i)
            if (b0 % i == 0) {
                x = b1 / b0 * i;
                if (gcd(x, b0) == i && gcd(x, a0) == a1)
                    ++ans;
                x = b1 / i;
                if (gcd(x, b0) == b0 / i && gcd(x, a0) == a1)
                    ++ans;
            }
        if (i * i == b0) {
            x = b1 / b0 * i;
            if (gcd(x, b0) == i && gcd(x, a0) == a1)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}