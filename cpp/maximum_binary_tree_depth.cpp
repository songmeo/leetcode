#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include "binary_tree.h"
using namespace std;

//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
class Solution {
public:
	int maxDepth(TreeNode* root) {
        int result = 0;
        return result;
    }
};

int main() {
	int arr[] = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
	binaryTree* t = new binaryTree();
	for(int i : arr) {
		t->insert(i);
	}
	return 0;
}
