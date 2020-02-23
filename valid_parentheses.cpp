#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string str) {
    stack<char> s;
    map<char, char> m;
    m['{'] = '}';
    m['('] = ')';
    m['['] = ']';
    for(int i = 0; i < str.length(); ++i) {
      auto it = m.find(str[i]);
      if(it != m.end()) 
        s.push(str[i]);
      else if(!s.empty() && m.find(s.top())->second == str[i]) 
        s.pop(); 
    }
    return s.empty();
  }
};

int main() {
  string str = "}";
  Solution s;
  cout << s.isValid(str);
  return 0;
}
