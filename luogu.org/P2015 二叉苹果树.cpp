#include <cstdio>
#include <tkz/util/max.hpp>

constexpr int N = 100 + 1, Q = N;

int n, q;
int f[N][Q];
int g[N][N];
int d[N];
int lch[N], rch[N];

int tot = 0;

int dp(int i, int j) {
    if (j == 0)
        return 0;
    if (!lch[i] && !rch[i])
        return d[i];
    if (f[i][j] != 0)
        return f[i][j];
    for (int k = 0; k <= j - 1; ++k) {
        f[i][j] = tkz::util::max(f[i][j], dp(lch[i], k) + dp(rch[i], j - k - 1) + d[i]);
    }
    return f[i][j];
}

void mkTree(int v) {
    int i = 1;
    for (; i <= n; ++i) {
        if (~g[v][i]) {
            lch[v] = i;
            d[i] = g[v][i];
            g[v][i] = g[i][v] = -1;
            mkTree(i);
            break;
        }
    }
    for (; i <= n; ++i) {
        if (~g[v][i]) {
            rch[v] = i;
            d[i] = g[v][i];
            g[v][i] = g[i][v] = -1;
            mkTree(i);
            break;
        }
    }
}

int main() {
    using namespace std;

    scanf("%d%d", &n, &q);
    int st, en, num;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = -1;
        }
    }
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d%d%d", &st, &en, &num);
        g[st][en] = g[en][st] = num;
    }
    mkTree(1);
    printf("%d\n", dp(1, q + 1));

    return 0;
}