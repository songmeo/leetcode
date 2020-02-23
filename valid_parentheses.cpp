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
    unordered_map<char, char> m;
    m['{'] = '}';
    m['('] = ')';
    m['['] = ']';
    int len = str.length();
    for(int i = 0; i < str.length(); ++i) {
      unordered_map<char, char>::iterator it;
      for(it = m.begin(); it != m.end(); ++it) {
        if(it->first == str[i] && s.top() == it->second)
          s.pop(); 
      }
      if(it == m.end())
        s.push(str[i]);
    }
    if(s.empty()) return true;
    return false;  
  }
};

int main() {
  string str = "[[{{}}]]";
  Solution s;
  cout << s.isValid(str);
  return 0;
}
