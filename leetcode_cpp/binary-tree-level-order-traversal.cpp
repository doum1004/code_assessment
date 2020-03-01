#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-level-order-traversal/

  3
9    20
   15  7
   
[3] [9,20] [15 7]

// Iteration BSF with queue 
// time: o(n)
// space: o(n) queue

q: 3
new list [3]
q: 9 20
new list [9 20]
q: 15 7
new list [15 7]

// Recursion DSF and give level
// time: o(n)
// space: o(h) : H is the height of the tree, i.e. the number of levels in the tree, which would be roughly o(logn)

vector<vector<int>> ans;
levelOrder(node, level)
    if (node == nullptr) return
    
    if (ans.size() < level + 1) ans.push_back(vector<int>())
    ans[level].push_back(node->val)
    levelOrder(node->left, level + 1)
    levelOrder(node->right, level + 1)
levelOrder(root, 0)

**/

class Solution {
public:
    vector<vector<int>> levelOrder_iteration(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
            
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto n = q.size();
            
            vector<int> vals;
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();
                
                vals.push_back(node->val);
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            ans.push_back(vals);
        }
        
        return ans;
    }
    
    vector<vector<int>> ans;
    void levelOrder_recursion(TreeNode* root, int level) {
        if (root == nullptr) return;
        
        if (ans.size() < level + 1) ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        levelOrder_recursion(root->left, level + 1);
        levelOrder_recursion(root->right, level + 1);
    }
    
    vector<vector<int>> levelOrder_recursion(TreeNode* root) {
        levelOrder_recursion(root, 0);
        return ans;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        //return levelOrder_iteration(root);
        return levelOrder_recursion(root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{3,9,20,-777,-777,15,7});
    assert(Solution().levelOrder(input1)
        == (vector<vector<int>> { {3}, {9,20}, {15,7} }));

    // assert(levelOrder(
    //     new TreeNode(vector<int>{3,9,20,-1,-1,15,7}))
    //     == (vector<vector<int>> { {3}, {9,20}, {15,7} }));
    return 0;
}