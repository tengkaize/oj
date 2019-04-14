#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int T = 300000;

int m, s, t;
int d[T + 1];

int main() {
    scanf("%d%d%d", &m, &s, &t);
    d[0] = 0;
    for (int i = 1; i <= t; ++i)
        d[i] = d[i - 1] + (m >= 10 ? (m -= 10, 60) : (m += 4, 0));
    for (int i = 1; i <= t; ++i)
        if ((d[i] = max(d[i], d[i - 1] + 17)) >= s) {
            printf("Yes\n%d", i);
            return 0;
        }
    printf("No\n%d", d[t]);
    return 0;
}