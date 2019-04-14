#include <cstdio>

using namespace std;

constexpr int N = 1000000 + 5;

int n, k;
int a[N];

int head, tail;
int qmin[N], qmax[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    head = 1; tail = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[i] < a[qmin[tail]] && head <= tail) --tail;
        qmin[++tail] = i;
        while (i - qmin[head] + 1 > k && head <= tail) ++head;
        if (i >= k) printf("%d ", a[qmin[head]]);
    }
    printf("\n");
    head = 1; tail = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[i] > a[qmax[tail]] && head <= tail) --tail;
        qmax[++tail] = i;
        while (i - qmax[head] + 1 > k && head <= tail) ++head;
        if (i >= k) printf("%d ", a[qmax[head]]);
    }
    printf("\n");
    return 0;
}
