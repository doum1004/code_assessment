#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/palindrome-linked-list/

// Solution1. Iteration using stack
// time: o(n) : n + n
// space: o(n)
1. push in stack and compare in next iteration
s: 1 2 false
s: 1 2 2 1 true

// Solution2. Recursion DSF postorder
// time: o(n)
// space: o(n)
t = head
bool r(node)
    if (!t) t = node;
    if (!node) return true;
    auto result = r(node->next);
    result &= temp->val == node->val;
    temp = temp->next;
    return result;

// Solution3. two pointers. find half with slow/faster. and reverse second half and iterate to compare
// time: o(n) : n + n + n
// space: o(1)
1. find half (slow/fast)
1 2 1
  s
    f
1 2 2 1
  s
    f
1 2 3 2 1
    s
        f
        
2. reverse second half using two pointer
1 2 2 1
second half 2 1
  2 1
p c n
c->p
c = n
p = c

result: 1 2 / 1 2

3. iterate to compare


// Sudo code
// find half
auto s = head;
auto f = head;
while (f->next && f->next->next)
    s = s->next;
    f = f->next->next;

// reverse second half
s = s->next
pre = null
while (s)
    auto n = s->next
    s->next = pre
    pre = s
    s = n
    
auto firsthalf = head
auto secondhalf = pre

while (firsthalf && secondhalf)
    if (firsthalf != secondhalf) return false;
    firsthalf = firsthalf->next
    secondhalf = secondhalf->next

return true

*/
class Solution {
public:
    bool isPalindrome_iteration_stack(ListNode* head) {
        if (!head || !head->next) return true;
        
        stack<ListNode*> s;
        auto cur = head;
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            if (cur->val != s.top()->val) return false;
            s.pop();
            cur = cur->next;
        }
        
        return true;
    }
    
    ListNode* temp_head = nullptr;
    bool isPalindrome_recursion(ListNode* head) {
        if (!temp_head) temp_head = head;
        if (!head) return true;
        auto result = isPalindrome_recursion(head->next) && head->val == temp_head->val;
        temp_head = temp_head->next;
        return result;
    }
    
    bool isPalindrome_twopointers(ListNode* head) {
        if (!head || !head->next) return true;
        
        // find half
        auto s = head;
        auto f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }

        // reverse second half
        s = s->next;
        ListNode* pre = nullptr;
        while (s) {
            auto n = s->next;
            s->next = pre;
            pre = s;
            s = n;
        }

        auto firsthalf = head;
        auto secondhalf = pre;

        while (firsthalf && secondhalf) {
            if (firsthalf->val != secondhalf->val) return false;
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }

        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        //return isPalindrome_iteration_stack(head);
        //return isPalindrome_recursion(head);
        return isPalindrome_twopointers(head);
    }
};

int main()
{
    auto input1 = new ListNode(1);
    input1->next = new ListNode(2);
    assert(Solution().isPalindrome(input1)
        == (false));

    auto input2 = new ListNode(1);
    input2->next = new ListNode(2);
    input2->next->next = new ListNode(1);
    assert(Solution().isPalindrome(input2)
        == (true));

    return 0;
}