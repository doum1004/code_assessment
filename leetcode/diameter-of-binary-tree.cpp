#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/diameter-of-binary-tree/

path: one vertice to another vertice number of edges
node itself left + right
return to parent max(l,r) + 1

          1(3, 3)
    2(2,2)   3(1)
4(1)   5(1)
max = 3

              1(5, 5)
        2(6, 4)   3(1)
    4(3)   5(3)
  6(2)       7(2)
8(1)             10(1)
max = 6

// Solution1. Recursion DFS (postorder)
// time: o(n)
// space: o(n)

int ans = 0;
getDepth(node)
    if (node==NULL) return 0
    
    auto l = getDepth(node->left)
    auto r = getDepth(node->right)
    ans = max(ans, l + r)
    
    return max(l, r) + 1

// Solution2. Iteration DFS (postorder)
// time: o(n)
// space: o(n)
s: 1 2 4 5
map<num, level>

s: 1 2 4 (5)
map: (5, 1 = max(l,r) + 1)
ans = 1 = max(ans, l + r)

s: 1 2 (4)
map: (5, 1), (4, 1)
ans = 1

s: 1 (2)
map: (5, 1), (4, 1), (2, 2)
ans = 2

s: 1 3
map: (5, 1), (4, 1), (2, 2)
ans = 2

s: 1 (3)
map: (5, 1), (4, 1), (2, 2), (3, 1)
ans = 2

s: (1)
map: (5, 1), (4, 1), (2, 2), (3, 1), (1, 3)
ans = 3


*/

class Solution {
public:
    int ans = 0;
    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        auto l = getDepth(node->left);
        auto r = getDepth(node->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree_recursion(TreeNode* root) {
        getDepth(root);
        return ans;
    }
    
    int diameterOfBinaryTree_iteration(TreeNode* root) {
        if (root == nullptr) return 0;
        
        unordered_map<TreeNode*, int> depth;
        int ans = 0;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            auto node = s.top();
            if (node->left && depth.find(node->left) == depth.end()) {
                s.push(node->left);
            }
            else if (node->right && depth.find(node->right) == depth.end()) {
                s.push(node->right);
            }
            else {
                s.pop();
                auto l = depth[node->left];
                auto r = depth[node->right];
                depth[node] = max(l,r) + 1;
                ans = max(ans, l+r);
            }
        }
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //return diameterOfBinaryTree_recursion(root);
        return diameterOfBinaryTree_iteration(root);
    }
};

int main()
{
    auto input1 = new TreeNode(1);
    input1->left = new TreeNode(2);
    input1->left->left = new TreeNode(4);
    input1->left->right = new TreeNode(5);
    input1->right->left = new TreeNode(3);


    assert(Solution().diameterOfBinaryTree(input1) == (3));

    return 0;
}