#include <cstdio>

using namespace std;

constexpr int N = 2000000 + 5;

int n, m;
int a[N];

int head, tail;
int q[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    head = 1; tail = 0;
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", a[q[head]]);
        while (i - q[head] + 1 > m && head <= tail) ++head;
        while (a[i] < a[q[tail]] && head <= tail) --tail;
        q[++tail] = i;
    }
    return 0;
}
