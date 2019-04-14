#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 10000 + 5, M = 50000 + 5;

int fir[N], nex[M], to[M];

inline void add(int u, int v) {
    static int tot = 0;
    ++tot;
    to[tot] = v;
    nex[tot] = fir[u];
    fir[u] = tot;
}

int col, dfn[N], low[N], de[N], si[N], co[N];
void Tarjan(int u) {
    static int num = 0;
    static stack<int> st;
    
    dfn[u] = low[u] = ++num;
    st.push(u);
    for (int i = fir[u]; i != 0; i = nex[i]) {
        int v = to[i];
        if (!dfn[v]) {
            Tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (!co[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        co[u] = ++col;
        ++si[col];
        while (st.top() != u) {
            ++si[col];
            co[st.top()] = col;
            st.pop();
        }
        st.pop();
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &a, &b);
        add(b, a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            Tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = fir[i]; j != 0; j = nex[j]) {
            if (co[i] != co[to[j]]) {
                ++de[co[to[j]]];
            }
        }
    }
    int ans;
    bool u = false;
    for (int i = 1; i <= col; ++i) {
        if (de[i] == 0) {
            ans = si[i];
            if (!u) u = true;
            else {
                printf("0\n");
                return 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
