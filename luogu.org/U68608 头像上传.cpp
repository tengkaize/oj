#include <cstdio>

using namespace std;

int main() {
    int n, L, G;
    scanf("%d%d%d", &n, &L, &G);
    int W, H;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &W, &H);
        while (W > G || H > G)
            W >>= 1, H >>= 1;
        printf(W < L || H < L ? "Too Young\n"
                              : W != H ? "Too Simple\n" : "Sometimes Naive\n");
    }
    return 0;
}