#include <cstdio>
#include <cstdlib>

constexpr int MAX_K = 4 + 1;

int gcda[MAX_K * (MAX_K - 1) / 2], lcma[MAX_K * (MAX_K - 1) / 2];

int main() {
    int T, k;
    scanf("%d%d", &T, &k);
    int n = k * (k - 1) / 2;
    while (T--) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &gcda[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &lcma[i]);
        if (k == 2) {
            printf("%d %d\n", gcda[0], lcma[0]);
        } else {
            for (int i = 0; i < k; ++i)
                printf("%d ", rand());
            printf("\n");
        }
    }
    return 0;
}
