#include <iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		long int i = 0;
        while(i*i < num) {
            i++;
            if(i*i == num)
                return true;
        }
        return false;
	}
}

int main() {
	cout << isPerfectSquare(16);
	return 0;
}
