#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * Introsort: quick sort -> heap sort -> insertion sort
 * time: O(nlogn)
 * space: logn
*/
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

/*
 * time: O(n)
 * space: O(1) //space is constant to how large n is 
 */
 
class Solution1 {
public:
    bool isAnagram(std::string s, std::string t) {
		unordered_map<char,int> m1;
		unordered_map<char,int> m2;
		if(s.length() == t.length()) {
			for(char c : s) {
				m1[c]++;
			}
			for(char c : t) {
				m2[c]++;
			}
			return m1 == m2;
		}
        return 0;
    }
};

int main() {
  Solution1 obj;
  std::cout << obj.isAnagram("anagram","nanagram");
  return 0;
}
