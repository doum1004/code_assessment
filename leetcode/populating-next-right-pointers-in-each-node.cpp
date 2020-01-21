#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}

    int operator ==(const Node* r) {
        return 0;
    }
};

/**
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Solution 1. Iteration BSF right to the left
// time: o(n)
// space: o(n) : n/2

   1
 2   3
4 5 6 7

q: 1
q: 2 3
2->3
q: 4 5 6 7
4->5->6->7

// Solution 2. using previously established next pointers
     1
   2    3
 4  5 6  7

1
    2->3
2
    4->5
    5->6
        6->7

l = root
while (l->left != null)
    h = l
    while (h != null)
        h->left->next = h->right // conncetion1
        if (h->next != null) h->right->next = h->next->left // connection2
        h = h->next
    l = l.left

        

**/
class Solution {
public:
    Node* connect_1(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto n = q.size();
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();
                if (i < n-1) node->next = q.front();
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        
        return root;
    }
    
    Node* connect_2(Node* root) {
        if (root == nullptr) return root;
        
        auto l = root;
        while (l->left != nullptr) {
            auto h = l;
            while (h != nullptr) {
                h->left->next = h->right;
                if (h->next != nullptr) h->right->next = h->next->left;
                h = h->next;
            }
            l = l->left;
        }
        
        return root;
    }
    
    Node* connect(Node* root) {
        //return connect_1(root);
        return connect_2(root);
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