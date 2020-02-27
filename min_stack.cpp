#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
  stack<int> Stack;
  stack<int> MinStack;    
  void push(int x) {
    Stack.push(x);
    if(MinStack.empty() || x <= MinStack.top()) MinStack.push(x);
  }
    
  void pop() {
    if(Stack.top() == MinStack.top()) MinStack.pop();
    Stack.pop();
  }
    
  int top() {
    return Stack.top();
  }
    
  int getMin() {
    return MinStack.top();
  }    
};

int main() {
  MinStack ms;
  ms.push(-2);
  ms.push(0);
  ms.push(-3);
  ms.getMin();
  ms.pop();
  ms.top();
  ms.getMin();
  return 0;
}
