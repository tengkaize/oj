#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;


class TrieNode {
private:
	bool isWord = false;
	TrieNode* children['z' - 'a' + 1] = {nullptr};
public:
	void insert(const char* str);
	bool find(const char* beg, const char* end);
};


const int wordMaxLen = 20;
const int passageMaxLen = 1 << 20;

char word[wordMaxLen + 1];
char passage[passageMaxLen + 1];
bool vis[passageMaxLen + 1];


int main() {
	int n, m;
	TrieNode* root = new TrieNode;
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", word);
		root->insert(word);
	}
	
	for (int i = 1; i <= m; ++i) {
		scanf("%s", passage);
		int plen = strlen(passage);
		
		memset(vis, 0, sizeof(vis));
		vis[0] = true;
		int ans = 0;
		for (int i = 0; i < plen; ++i) {
			if (vis[i]) {
				for (int j = 1; j <= 10 && i + j <= plen; ++j) {
					if (root->find(passage + i, passage + i + j)) {
						vis[i + j] = true;
						ans = max(ans, i + j);
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}
}


#define cov(ch) ((ch) - 'a')

void TrieNode::insert(const char* str) {
	TrieNode* cur = this;
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if (cur->children[cov(str[i])] == nullptr) {
			cur->children[cov(str[i])] = new TrieNode;
		}
		cur = cur->children[cov(str[i])];
	}
	cur->isWord = true;
}

bool TrieNode::find(const char* beg, const char* end) {
	TrieNode* cur = this;
	for (const char* it = beg; it != end; ++it) {
		cur = cur->children[cov(*it)];
		if (cur == nullptr) {
			return false;
		}
	}
	return cur->isWord;
}

#undef cov
