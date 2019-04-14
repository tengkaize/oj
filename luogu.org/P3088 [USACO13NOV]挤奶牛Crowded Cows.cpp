#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Cow {
    int location;
    int height;
};

constexpr int N = 50000 + 5;
int n, d;

Cow cows[N];

int head, tail;
int q[N];
bool cr[N];

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &cows[i].location, &cows[i].height);
    }
    sort(cows + 1, cows + n + 1, 
         [](const Cow& a, const Cow& b) { return a.location < b.location; });
    head = 1; tail = 0;
    for (int i = 1; i <= n; ++i) {
        while (head <= tail && cows[i].height >= cows[q[tail]].height)
            --tail;
        q[++tail] = i;
        while (head <= tail && cows[i].location - cows[q[head]].location > d)
            ++head;
        cr[i] = cows[q[head]].height >= 2 * cows[i].height;
    }
    memset(q, 0, sizeof(q));
    head = 1; tail = 0;
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        while (head <= tail && cows[i].height <= cows[q[tail]].height)
            --tail;
        q[++tail] = i;
        while (head <= tail && cows[q[head]].location - cows[i].location > d)
            ++head;
        if (cows[q[head]].height >= 2 * cows[i].height && cr[i])
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}