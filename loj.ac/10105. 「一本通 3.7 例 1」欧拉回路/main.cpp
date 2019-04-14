#include <cstdio>
#include <vector>

constexpr int N = 1e5 + 10, E = 10 * N;

int type, n, m;

int tot = 1;
int head[N], ver[E], next[E];
inline void addEdge(int v, int u) {
    ver[++tot] = u;
    next[tot] = head[v];
    head[v] = tot;
}

bool flag[E];
std::vector<int> ans;
void dfs(int x) {
    for (int &i = head[x], y; y = ver[i], i; i = next[i]) {
        int eInd = (type == 1 ? i >> 1 : i - 1);
        if (flag[eInd])
            continue;
        flag[eInd] = true;
        dfs(y);
        ans.push_back(type == 1 ? i % 2 ? -eInd : eInd : eInd);
    }
}

bool genAns() {
    for (int i = 1; i <= n; ++i) {
        if (head[i]) {
            dfs(i);
            break;
        }
    }
    return ans.size() == m;
}

int in[N], out[N];
bool checkDegree() {
    if (type == 1) {
        for (int i = 1; i <= n; ++i) {
            if ((in[i] + out[i]) & 1) {
                return false;
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (in[i] != out[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d%d", &type, &n, &m);
    for (int i = 1, v, u; i <= m; ++i) {
        scanf("%d%d", &v, &u);
        addEdge(v, u);
        if (type == 1)
            addEdge(u, v);
        ++out[v];
        ++in[u];
    }
    if (checkDegree() && genAns()) {
        printf("YES\n");
        for (int i = m - 1; i >= 0; --i)
            printf("%d ", ans[i]);
    } else {
        printf("NO\n");
    }
    return 0;
}