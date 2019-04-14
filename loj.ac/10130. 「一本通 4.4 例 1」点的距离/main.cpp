#include <algorithm>
#include <cstdio>

using nInd_t = int;
using eInd_t = int;

const int N = 100000 + 5;

nInd_t head[N];
eInd_t next[N * 2];
nInd_t to[N * 2];
nInd_t f[N][21];

eInd_t tot = 0;
inline void addEdge(nInd_t u, nInd_t v) {
    next[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}

unsigned int depth[N];
void dealFirst(nInd_t u, nInd_t father) {
    depth[u] = depth[father] + 1;
    for (int i = 0; i <= 19; ++i) {
        f[u][i + 1] = f[f[u][i]][i];
    }
    for (eInd_t e = head[u]; e; e = next[e]) {
        nInd_t v = to[e];
        if (v == father)
            continue;
        f[v][0] = u;
        dealFirst(v, u);
    }
}

nInd_t lca(nInd_t x, nInd_t y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
        if (x == y)
            return x;
    }
    for (int i = 20; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

inline int pathLen(nInd_t x, nInd_t y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int main() {
    int n, Q;
    std::scanf("%d", &n);

    nInd_t x, y;
    while (--n) {
        std::scanf("%d%d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }

    dealFirst(1, 0);

    std::scanf("%d", &Q);
    nInd_t a, b;
    while (Q--) {
        std::scanf("%d%d", &a, &b);
        std::printf("%d\n", pathLen(a, b));
    }

    return 0;
}