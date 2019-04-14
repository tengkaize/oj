#include <cstdio>
#include <functional>

using namespace std;

char s[1024];

struct TreeNode {
	TreeNode* left; 
	TreeNode* right;
	char type;
};

TreeNode* build(int b, int e, const char* s) {
	TreeNode* root = new TreeNode();
	if (e - b == 1) {
		root->type = s[b] == '0' ? 'B' : 'I';
		root->left = root->right = NULL;
		return root;
	}
	int m = (b + e) >> 1;
	root->left = build(b, m, s);
	root->right = build(m, e, s);
	root->type = root->left->type == root->right->type ? root->left->type : 'F';
	return root;
}

TreeNode* postOrder(TreeNode* root, function<void(const TreeNode&)> visit) {
	if (root == NULL) return root;
	postOrder(root->left, visit);
	postOrder(root->right, visit);
	visit(*root);
	return root;
}

void del(TreeNode* root) {
	if (root == NULL) return;
	del(root->left);
	del(root->right);
	delete root;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	del(postOrder(build(0, 1 << n, s), [](const TreeNode& t) {
		printf("%c", t.type);
	}));
	putchar('\n');
	return 0;
}
