#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class binaryTree {
public:
	binaryTree();
	~binaryTree();
	void insert(int i);
	TreeNode* search(int i);
	void destroy();
	void preorder_print();
private:
	void insert(int i, TreeNode* &root);
	void preorder_print(TreeNode* n);
	void destroy(TreeNode* n);
	TreeNode* root;
};

binaryTree::binaryTree() {
	root = NULL;
}

binaryTree::~binaryTree() {
	destroy();
}

void binaryTree::insert(int i) {
	insert(i, root);
}

void binaryTree::insertPreorder(int i, TreeNode* &node) {
	TreeNode* tmp = new TreeNode(i);
	if(i == INT_MAX) {
		node->left = null;
	}
	else if(!node)
		node = tmp;
	
	insert(i,node->left);
	insert(i,node->right);
}

void binaryTree::preorder_print() {
	preorder_print(root);
}

void binaryTree::preorder_print(TreeNode* node) {
	TreeNode* tmp = node;
	if(tmp) {
		cout << node->val << " ";
		preorder_print(node->left);
		preorder_print(node->right);
	}
}

void binaryTree::destroy() {
	destroy(root);
}

void binaryTree::destroy(TreeNode* node) {
	if(node) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

/*
int main() {
	int arr[] = {10,6,14,5,8,11,18};
	binaryTree* t = new binaryTree();
	for(int i : arr) t->insert(i);
	t->preorder_print();
	t->destroy();
	return 0;
}
*/
