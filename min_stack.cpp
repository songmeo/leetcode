#include <iostream>
#include <deque>
using namespace std;

//deque is short for double ended queue
class MinStack {
public:
  deque<int> myStack{};
  MinStack() {
        
  }
    
  void push(int x) {
    myStack.push_back(x);
  }
    
  void pop() {
    myStack.pop_back();
  }
    
  int top() {
    return myStack.back();
  }
    
  int getMin() {
    return 0;      
  }
};

int main() {
  MinStack ms;
  ms.push(1);
  cout << ms.top();
  return 0;
}
