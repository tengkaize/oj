#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

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
    
    AhoCorasick():
        tree{
            {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},0,0},
            {{},0,0}
        }
    {
        tree.reserve(1000001);
    }
    
    void insert(const char* beg, const char* end);
    void insert(const char* str) { insert(str, str + std::strlen(str)); }
    
    bool find(const char* beg, const char* end);
    bool find(const char* str) { return find(str, str + std::strlen(str)); }
    
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

} // namespace str
} // namespace tkz

#include <cstdio>

using namespace std;
using namespace tkz::str;

size_t match(AhoCorasick& ac, const char* s) {
    size_t count = 0;
    size_t len = strlen(s);
    nIndex u = 1;
    for (size_t i = 0; i < len; ++i) {
        nIndex k = ac.tree[u].child[s[i] - 'a'];
        while (k > 1) {
            count += ac.tree[k].count;
            ac.tree[k].count = 0;
            k = ac.tree[k].fail;
        }
        u = ac.tree[u].child[s[i] - 'a'];
    }
    return count;
}

char buf[1000001];

int main() {
    int n;
    scanf("%d", &n);
    AhoCorasick ac;
    while (n--) {
    	scanf("%s", buf);
        ac.insert(buf);
    }
    ac.build();
    scanf("%s", buf);
    printf("%d\n", int(match(ac, buf)));
    return 0;
}
