#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

namespace tkz {
namespace str {

typedef std::size_t nIndex;

struct AhoCorasick {
    struct Node {
        nIndex child[26];
        nIndex fail;
        std::size_t count;
    };

    std::vector<Node> tree;

    AhoCorasick()
        : tree{{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 0, 0}, {{}, 0, 0}} {}

    void insert(const char* beg, const char* end);
    void insert(const char* str) { insert(str, str + std::strlen(str)); }

    void build();
};

void AhoCorasick::insert(const char* beg, const char* end) {
    nIndex u = 1;
    std::for_each(beg, end, [&u, this](char c) {
        if (!tree[u].child[c - 'a']) {
            tree[u].child[c - 'a'] = tree.size();
            tree.push_back(Node());
        }
        u = tree[u].child[c - 'a'];
    });
    ++tree[u].count;
}

void AhoCorasick::build() {
    std::queue<nIndex> que;
    que.push(1);
    while (!que.empty()) {
        nIndex u = que.front();
        que.pop();
        for (std::size_t i = 0; i < 26; ++i) {
            if (!tree[u].child[i])
                tree[u].child[i] = tree[tree[u].fail].child[i];
            else {
                que.push(tree[u].child[i]);
                tree[tree[u].child[i]].fail = tree[tree[u].fail].child[i];
            }
        }
    }
}

}  // namespace str
}  // namespace tkz

namespace tkz {
namespace util {

template <class T, class U = T>
T exchange(T& obj, U&& new_value) {
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}

}  // namespace util
}  // namespace tkz

#include <cstdio>

using namespace std;
using namespace tkz::str;

size_t match(AhoCorasick& ac, const char* s) {
    size_t count = 0;
    nIndex u = 1;
    for (size_t i = 0, len = strlen(s); i < len; ++i) {
        u = ac.tree[u].child[s[i] - 'a'];
        for (nIndex k = u; k > 1; k = ac.tree[k].fail)
            count += tkz::util::exchange(ac.tree[k].count, 0);
    }
    return count;
}

char wordbuf[51];
char passbuf[1000001];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        AhoCorasick ac;
        while (n--) {
            scanf("%s", wordbuf);
            ac.insert(wordbuf);
        }
        ac.build();
        scanf("%s", passbuf);
        printf("%d\n", int(match(ac, passbuf)));
    }
    return 0;
}
