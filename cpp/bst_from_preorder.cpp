/*
 * Return the root node of a binary search tree that matches the given preorder traversal.
 * 
 * a binary search tree is a binary tree where for every node, any descendant of node.left 
 * has a value < node.val, and any descendant of node.right has a value > node.val
 * 
 * a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right
 */
#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(root == NULL)
            root = new TreeNode(i);
        else if(root->val > i)
            root->left = construct(root->left, i);
        else
            root->right = construct(root->right, i);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i : preorder) {
           root = construct(root, i);
        }
        return root;
    }
};
