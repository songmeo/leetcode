#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// brute force solution
class Solution1 {
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

//algorithm
class Solution {
public:
  int maxProfit(vector<int>& v) {
    int min_buy = INT_MAX;
    int max_profit = INT_MIN;
    for(auto it = v.begin(); it != v.end(); ++it) {
      if(*it < min_buy) min_buy = *it;
      else if(*it - min_buy > max_profit) max_profit = *it - min_buy; 
    }
    return max_profit;    
  }
};

int main() {
  Solution s; 
  vector<int> v{7,2,4,1};
  cout << s.maxProfit(v);
  return 0;
}

