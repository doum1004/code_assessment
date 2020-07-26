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
    bool compareDFS(TreeNode* l, TreeNode* r) {
        // o(n) o(n)
        if (l == nullptr && r == nullptr) return true;
        if (!l || !r || l->val != r->val) return false;
        
        return (compareDFS(l->left, r->right) && compareDFS(l->right, r->left));
    }
    
    bool compareBFS(TreeNode* root) {
        // o(n) o(n)
        if (root == nullptr) return true;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        
        while (!q.empty()) {
            auto l = q.front().first;
            auto r = q.front().second;
            q.pop();
            if (l == nullptr && r == nullptr) continue;
            if (!l || !r || l->val != r->val) return false;
            
            q.push({l->left, r->right});
            q.push({l->right, r->left});
        }   
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return compareDFS(root, root);
        //return compareBFS(root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{1,2,2,3,4,4,3});
    assert(Solution().isSymmetric(input1)
        == true);

    return 0;
}
