#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

  3
9    20
   15  7
   
[3] [9,20] [15 7]

// Iteration BSF with queue 
// time: o(n)
// space: o(n) queue

q: 3        level = 0
new list [3]
q: 9 20     level = 1 (level%2 == 1 add reverse)
new list [20 9]
q: 15 7
new list [15 7]

// Recursion DSF and give level
// time: o(n)
// space: o(h) : H is the height of the tree, i.e. the number of levels in the tree, which would be roughly o(logn)

vector<vector<int>> ans;
levelOrder(node, level)
    if (node == nullptr) return
    
    if (ans.size() < level + 1) ans.push_back(vector<int>())
    if (level % 2 == 0) ans[level].push_back(node->val)
    else ans[level].insert(ans[level].begin(), node->val)
    levelOrder(node->left, level + 1)
    levelOrder(node->right, level + 1)
levelOrder(root, 0)

**/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder_iteration(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
            
        queue<TreeNode*> q;
        q.push(root);
        
        int level = -1;
        vector<vector<int>> ans;
        while (!q.empty()) {
            level++;
            auto n = q.size();
            
            vector<int> vals(n, 0);
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();
                
                auto p = i;
                if (level % 2 == 1) p = n - 1 - i;
                vals[p] = node->val;
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            ans.push_back(vals);
        }
        
        return ans;
    }
    
    vector<vector<int>> ans;
    void zigzagLevelOrder_recursion(TreeNode* root, int level) {
        if (root == nullptr) return;
        
        if (ans.size() < level + 1) ans.push_back(vector<int>());
        if (level % 2 == 0)
            ans[level].push_back(root->val);
        else
            ans[level].insert(ans[level].begin(), root->val);
        
        zigzagLevelOrder_recursion(root->left, level + 1);
        zigzagLevelOrder_recursion(root->right, level + 1);
    }
    
    vector<vector<int>> zigzagLevelOrder_recursion(TreeNode* root) {
        zigzagLevelOrder_recursion(root, 0);
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //return zigzagLevelOrder_iteration(root);
        return zigzagLevelOrder_recursion(root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{3,9,20,-777,-777,15,7});
    assert(Solution().zigzagLevelOrder(input1)
        == (vector<vector<int>> { {3}, {20,9}, {15,7} }));
    return 0;
}