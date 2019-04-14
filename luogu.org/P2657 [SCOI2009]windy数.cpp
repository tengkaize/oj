#include <cstdio>

constexpr int LOGAB = 10;

int f[LOGAB + 1][10];
constexpr long long pow[LOGAB + 1] = {1,       10,       100,       1000,       10000,      100000,
                                      1000000, 10000000, 100000000, 1000000000, 10000000000};

inline int abs(int x) {
    return x < 0 ? -x : x;
}

inline bool judge(int k, int j) {
    return abs(k - j) >= 2;
}

void pre() {
    for (int j = 0; j < 10; ++j)
        f[1][j] = 1;
    for (int i = 2; i <= LOGAB; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                if (judge(k, j))
                    f[i][j] += f[i - 1][k];
}

int count(int x) {
    int xLen = 0;
    while (pow[xLen] <= x)
        ++xLen;
    int ans = 0;
    for (int i = 1; i < xLen; ++i)
        for (int j = 1; j < 10; ++j)
            ans += f[i][j];
    int y = x / pow[xLen - 1];
    for (int j = 1; j < y; ++j)
        ans += f[xLen][j];
    int preY = y;
    x %= pow[xLen - 1];
    for (int i = xLen - 1; i >= 1; --i) {
        y = x / pow[i - 1];
        for (int j = 0; j < y; ++j)
            if (judge(j, preY))
                ans += f[i][j];
        if (!judge(preY, y))
            break;
        preY = y;
        x %= pow[i - 1];
    }
    return ans;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    pre();
    printf("%d\n", count(b + 1) - count(a));
    return 0;
}