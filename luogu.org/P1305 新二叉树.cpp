#include <cstdio>

using namespace std;

struct Node {
	char left;
	char right;
};

Node tree[1 << sizeof(char)];

void preorder(char ch) {
	if (ch == '*') return;
	putchar(ch);
	preorder(tree[ch].left);
	preorder(tree[ch].right);
}

int main() {
	int n;
	scanf("%d", &n);
	char s[4];
	scanf("%s", s);
	tree[s[0]].left = s[1];
	tree[s[0]].right = s[2];
	char root = s[0];
	n--;
	while (n--) {
		scanf("%s", s);
		tree[s[0]].left = s[1];
		tree[s[0]].right = s[2];
	}
	preorder(root);
	putchar('\n');
	return 0;
}
