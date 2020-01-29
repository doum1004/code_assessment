#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/palindrome-linked-list/

// Solution1. copy vals in vector and two points compare in vector
// time: o(n)
// space: o(n)

// Solution2. Recursion. DSF inorder/postorder compare temp(head) and next
// time: o(n)
// space: o(n)

// Solution3. two points
// 1. find half by slow / fast
// 2. reserve slow->next and slow->next = nullptr
// 3. iterate reserved and head and compare
// time: o(n) : o(1/2) + o(1/2) + o(1/2)
// space: o(1)

1 2 3 2 1
s
f
    s
        f
reverse 

1 2 3 3 2 1
s
f
    s
        f

*/
class Solution {
public:
    bool isPalindrome_copy(ListNode* head) {
        if (head == nullptr) return true;
        
        vector<int> v;
        auto cur = head;
        while (cur != nullptr) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        
        int l=0, r=v.size()-1;
        while (l<r) {
            if (v[l] != v[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    ListNode* temp = nullptr;
    bool isPalindrome_recursion(ListNode* head) {
        if (temp == nullptr) temp = head;
        if (head == nullptr) return true;
        auto r = isPalindrome_recursion(head->next) && head->val == temp->val;
        temp = temp->next;
        return r;
    }
    
    bool isPalindrome_reversehalf(ListNode* head) {
        if (head == nullptr) return true;
        auto slow = head;
        auto fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        auto reverseHead = reverse(slow->next);
        slow->next = nullptr;
        
        while (reverseHead != nullptr) {
            if (reverseHead->val != head->val) return false;
            reverseHead = reverseHead->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        while (node != nullptr) {
            nxt = node->next;
            node->next = pre;
            pre = node;
            node = nxt;
        }
        
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        //return isPalindrome_copy(head);
        //return isPalindrome_recursion(head);
        return isPalindrome_reversehalf(head);
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