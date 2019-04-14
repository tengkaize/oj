#include <cstdio>

using namespace std;

constexpr int N = 30 + 1;

int n;
int d[N];
long long f[N][N];
int ro[N][N];

void printRoot(int l, int r) {
    if (l > r) return;
    printf("%d ", ro[l][r]);
    if (l == r) return;
    printRoot(l, ro[l][r] - 1);
    printRoot(ro[l][r] + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", d + i);
        f[i][i] = d[i];
        f[i][i - 1] = 1;
        ro[i][i] = i;
    }
    for (int l = 1; l < n; ++l) {
        for (int i = 1; i + l <= n; ++i) {
            int j = i + l;
            for (int k = i; k <= j; ++k) {
                long long v = f[i][k - 1] * f[k + 1][j] + f[k][k];
                if (f[i][j] < v) {
                    f[i][j] = v;
                    ro[i][j] = k;
                }
            }
        }
    }
    printf("%lld\n", f[1][n]);
    printRoot(1, n);
    return 0;
}