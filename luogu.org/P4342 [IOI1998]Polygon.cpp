#include <cstdio>
#include <limits>

#include <tkz/util/max.hpp>
#include <tkz/util/min.hpp>

constexpr int N = 50 + 5;

char op[N * 2];
long long a[N * 2];
long long maxf[N * 2][N * 2], minf[N * 2][N * 2];
int n;

int main() {
    using namespace std;
    using tkz::util::max;
    using tkz::util::min;

    scanf("%d", &n);
    {
        char t[2];
        for (int i = 1; i <= n; ++i) {
            scanf("%1s%lld", t, a + i);
            op[i + n] = op[i] = t[0];
            a[i + n] = a[i];
        }
    }

    for (int i = 1; i <= (n << 1); ++i) {
        for (int j = 1; j <= (n << 1); ++j) {
            maxf[i][j] = numeric_limits<long long>::min();
            minf[i][j] = numeric_limits<long long>::max();
            if (i == j)
                maxf[i][i] = minf[i][i] = a[i];
        }
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1, j = l; j <= (n << 1); ++i, ++j) {
            for (int k = i; k < j; ++k) {
                if (op[k + 1] == 't') {
                    maxf[i][j] = max(maxf[i][j], maxf[i][k] + maxf[k + 1][j]);
                    minf[i][j] = min(minf[i][j], minf[i][k] + minf[k + 1][j]);
                } else {
                    maxf[i][j] = max(maxf[i][j],  //
                                     maxf[i][k] * maxf[k + 1][j],
                                     maxf[i][k] * minf[k + 1][j],
                                     minf[i][k] * maxf[k + 1][j],
                                     minf[i][k] * minf[k + 1][j]);
                    minf[i][j] = min(minf[i][j],  //
                                     maxf[i][k] * maxf[k + 1][j],
                                     maxf[i][k] * minf[k + 1][j],
                                     minf[i][k] * maxf[k + 1][j],
                                     minf[i][k] * minf[k + 1][j]);
                }
            }
        }
    }

    long long ans = numeric_limits<long long>::min();
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, maxf[i][i + n - 1]);
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) {
        if (maxf[i][i + n - 1] == ans) {
            printf("%d ", i);
        }
    }

    return 0;
}