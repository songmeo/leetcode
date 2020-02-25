#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    auto min = min_element(prices.begin(),prices.end());
    auto max = max_element(prices.begin(),prices.end());
    int d1 = *max_element(min, prices.end()) - *min;
    int d2 = *max - *min_element(prices.begin(), max);
    return (d1 > d2)?d1:d2;
  }
};

int main() {
  Solution s; 
  vector<int> v{7,6,4,3,1};
  cout << s.maxProfit(v);
  return 0;
}

