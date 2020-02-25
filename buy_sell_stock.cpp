#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force solution
class Solution {
public:
  int maxProfit(vector<int>& v) {
    int diff;
    for(auto it1 = v.begin(); it1 < v.end(); ++it1) {
      for(auto it2 = it1 + 1; it2 < v.end(); ++it2) {
        if(*it2 - *it1 > diff) diff = *it2 - *it1; 
      }
    }
    return diff;
  }
};

int main() {
  Solution s; 
  vector<int> v{7,2,4,1};
  cout << s.maxProfit(v);
  return 0;
}

