#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/symmetric-tree/

   1
 2   2
3 4 4 3

// Recursion BFS inorder
// time: o(n)
// space: o(n) recursion
isSymeetric_recursion(TreeNode* n1, TreeNode* n2)
    if (n1 == nullptr && n2 == nullptr) return true;
    if (n1 == nullptr || n2 == nullptr) return false;
    
    if (!isSymeetric(n1->left, n2->right)) return false;
    if (n1->val != n2->val) return false;
    if (!isSymeetric(n1->right, n2->left)) return false;

    return true;
    
isSymeetric(root, root)


// Iterative DFS (stack)
// time: o(n)
// space: o(n)
s: 1, 1
s: 2,3 3,2
stack<TreeNode*> s;
s.push(root)
s.push(root)
while (!s.empty()) {
    auto n1 = s.top()
    s.pop()
    auto n2 = s.top()
    s.pop()
    
    if (n1 == nullptr && n2 == nullptr) continue;
    if (n1 == nullptr || n2 == nullptr) return false;
    if (n1->val != n2->val) return false;
    
    s.push(n1->left);
    s.push(n2->Right);
    s.push(n1->right);
    s.push(n2->left);
}

return true

**/

class Solution {
public:
    bool isSymeetric_recursion(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;

        if (!isSymeetric_recursion(n1->left, n2->right)) return false;
        if (n1->val != n2->val) return false;
        if (!isSymeetric_recursion(n1->right, n2->left)) return false;

        return true;
    }
    
    bool isSymeetric_iterative(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        s.push(root);
        while (!s.empty()) {
            auto n1 = s.top();
            s.pop();
            auto n2 = s.top();
            s.pop();

            if (n1 == nullptr && n2 == nullptr) continue;
            if (n1 == nullptr || n2 == nullptr) return false;
            if (n1->val != n2->val) return false;

            s.push(n1->left);
            s.push(n2->right);
            s.push(n1->right);
            s.push(n2->left);
        }

        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymeetric_recursion(root, root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{1,2,2,3,4,4,3});
    assert(Solution().isSymmetric(input1)
        == true);

    return 0;
}