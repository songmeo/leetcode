#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
  Solution obj;
  std::cout << obj.isAnagram("anagram","nanagram");
  return 0;
}
