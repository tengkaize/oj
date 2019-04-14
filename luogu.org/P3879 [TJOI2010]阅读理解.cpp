#include <cstdio>
#include <cstring>
#include <cctype>
#include <set>

using namespace std;

struct TrieNode {
	set<unsigned> pnums;
	TrieNode* child['z' - 'a' + 1];
};

inline size_t cov(char ch) {
	return ch - 'a';
}

TrieNode* find(TrieNode* const root, const char* word) {
	size_t len = strlen(word);
	TrieNode* cur = root;
	for (size_t i = 0; i < len; ++i) {
		if (!isalpha(word[i])) return nullptr;
		cur = cur->child[cov(word[i])];
		if (cur == nullptr) return nullptr;
	}
	return cur;
}

void insert(TrieNode* const root, const char* word, unsigned pnum) {
	size_t len = strlen(word);
	TrieNode* cur = root;
	for (size_t i = 0; i < len; ++i) {
		if (cur->child[cov(word[i])] == nullptr) {
			cur->child[cov(word[i])] = new TrieNode{{}, {nullptr}};
		}
		cur = cur->child[cov(word[i])];
	}
	cur->pnums.insert(pnum);
}

int main() {
	TrieNode* root = new TrieNode{{}, {nullptr}};
	unsigned n, l;
	char word[21];
	scanf("%u", &n);
	for (unsigned i = 1; i <= n; ++i) {
		scanf("%u", &l);
		for (unsigned j = 1; j <= l; ++j) {
			scanf("%s", word);
			insert(root, word, i);
		}
	}
	unsigned m;
	scanf("%u", &m);
	for (unsigned i = 1; i <= m; ++i) {
		scanf("%s", word);
		TrieNode* node = find(root, word);
		if (node != nullptr) {
			for (unsigned p : node->pnums) {
				printf("%u ", p);
			}
		}
		printf("\n");
	}
	return 0;
}

