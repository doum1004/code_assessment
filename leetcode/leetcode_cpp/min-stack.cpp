#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/min-stack/

// push, pop, top, getMin o(1)
// push(-2)
// stack: (-2, -2)
// push(0)
// stack: (-2, -2) (0, -2)
// push(-3)
// stack: (-2, -2) (0, -2) (-3, -3)
// getmin()
// -3

// stack: stack<value, min(value, stack.top().getmin())>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack_.push({x, min(getMin(), x)});
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        return stack_.top().first;
    }
    
    int getMin() {
        return (stack_.size() > 0) ? stack_.top().second : INT_MAX;
    }
    
private:
    stack<pair<int, int>> stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    auto minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    assert(minStack->getMin() == -3); //   --> Returns -3.
    minStack->pop();
    assert(minStack->top() == 0); //     --> Returns 0.
    assert(minStack->getMin() == -2); //   --> Returns -2.

    delete(minStack);
    
    return 0;
}