/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if(!root) return {0,0};
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        int diameter = max({left.first, right.first, left.second + right.second});
        return pair<int,int>{diameter, max(left.second, right.second) + 1};
    }
    int diameterOfBinaryTree(TreeNode* root) {
       return dfs(root).first;  
    }
};
