#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_p = *min_element(prices.begin(), prices.end());
    int max_p = *max_element(prices.begin(), prices.end());
    int max_s = *max_element(min_element(prices.begin(),prices.end()), prices.end());
    int min_s = *min_element(prices.begin(), max_element(prices.begin(), prices.end()));
    return (max_s - min_p > max_p - min_s)?(max_s - min_p):(max_p - min_s);
  }
};

int main() {
  Solution s; 
  vector<int> v{7,1,5,3,6,4};
  cout << s.maxProfit(v);
  return 0;
}

