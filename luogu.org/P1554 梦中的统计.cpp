#include <cstdio>

using namespace std;

int main() {
    int c[10] = {0};
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; ++i) {
        int k = i;
        do {
            ++c[k % 10];
            k /= 10;
        } while (k);
    }
    for (int i = 0; i < 10; ++i)
        printf("%d ", c[i]);
    return 0;
}