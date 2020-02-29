#include <iostream>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(int arr[], TreeNode* root, int i, int n) {
  if(i < n) {
	TreeNode* tmp = new TreeNode(arr[i]);
	root = tmp;
	root->left = insert(arr, root->left, i*2 + 1, n);
	root->right = insert(arr, root->right, i*2 + 2, n);
  }
  return root;
}

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
	if(!root) return true;
	return isSymmetric(root->left,root->right);
  }
  
  bool isSymmetric(TreeNode* left, TreeNode* right) {
	if(!left || !right)
	  return left == right;
	if(left->val != right->val) return false;
	return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
  }
};


int main() {
  Solution s;
  int arr[] = {1,2,2,3,4,4};
  TreeNode* root = insert(arr,root,0,sizeof(arr)/sizeof(arr[0]));
  cout << s.isSymmetric(root);
  return 0;
}
