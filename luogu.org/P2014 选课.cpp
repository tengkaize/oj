#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

constexpr int N = 300 + 1, M = N;

vector<int> ch[N];
int f[N][M];
int s[N];
int n, m;

void dp(int k) {
    f[k][0] = 0;
    for (int c : ch[k]) {
        dp(c);
        for (int t = m; t >= 0; --t) {
            for (int j = t; j >= 0; --j) {
                if (t - j >= 0) {
                    f[k][t] = max(f[k][t], f[k][t - j] + f[c][j]);
                }
            }
        }
    }
    if (k != 0) {
        for (int t = m; t > 0; --t) {
            f[k][t] = f[k][t - 1] + s[k];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &k, &s[i]);
        ch[k].push_back(i);
    }
    memset(f, 0xcf, sizeof(f));
    dp(0);
    printf("%d\n", f[0][m]);
    return 0;
}