#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../nodenext.h"

using namespace std;

/**
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Solution1. Recursion with DSF preorder. give next (left, right) (right, next->left)
// time: o(n)
// space: o(1) : o(logn) perfect bin but this doesn't count here

r(node, nextnode)
    node->next = nextnode
    r(node->left, node->right)
    r(node->right, node->next->left)

// Solution2. Iteration inner interate for next
// time: o(n)
// space: o(1)

1. iterate from cur(root)
    2. left.next = right
    3. if it has next, right.next = next.left
    4. move to next and do the same 2~3
    5. cur = cur->left


*/
class Solution {
public:
    void recursive(Node* node, Node* nextnode) {
        if (!node) return;
        node->next = nextnode;
        recursive(node->left, node->right);
        recursive(node->right, (node->next) ? node->next->left : nullptr);
    }
    
    Node* connect_recursive(Node* root) {
        recursive(root, nullptr);
        return root;
    }
    
    Node* connect_iteration(Node* root) {
        if (!root) return nullptr;
        
        auto cur = root;
        while (cur) {
            if (cur->left) {
                auto head = cur;
                while (head) {
                    head->left->next = head->right;
                    if (head->next) {
                        head->right->next = head->next->left;
                    }
                    head = head->next;
                }
            }
            cur = cur->left;
        }
        return root;
    }
    
    Node* connect(Node* root) {
        //return connect_recursive(root);
        return connect_iteration(root);
    }
};

int main()
{
    auto input1 = new Node(1);
    input1->left = new Node(2);
    input1->right = new Node(3);
    input1->left->left = new Node(4);
    input1->left->right = new Node(5);
    input1->right->left = new Node(6);
    input1->right->right = new Node(7);
    auto ans = Solution().connect(input1);
    assert(ans->left->next->val == 3);
    assert(ans->left->right->next->val == 6);
    return 0;
}