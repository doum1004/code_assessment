#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/implement-queue-using-stacks/

// Solution1. one stack
// time: push(n), pop(1), peek(1), empty(1)
// space: o(2n). stack(n). recursion(n) in push

at push, taking all stack, put value on the bottom, and stack values again

*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_helper(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto v = s_.top();
        s_.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        return s_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s_.empty();
    }
    
private: 
    void push_helper(int v) {
        if (s_.size() == 0) {
            s_.push(v);
            return;
        }
        int t = s_.top();
        s_.pop();
        push_helper(v);
        s_.push(t);
    }
    
    stack<int> s_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);

    assert(obj->pop() == 1);
    assert(obj->peek() == 2);
    assert(obj->empty() == false);
    return 0;
}