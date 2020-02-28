#include <iostream>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    return true;
  }
};


int main() {
  Solution s;
  //cout << s.isSymmetric;
  srand(time(NULL));
  return 0;
}
