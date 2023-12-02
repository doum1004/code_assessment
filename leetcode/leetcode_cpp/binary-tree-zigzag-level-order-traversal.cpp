#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

  3
9    20
   15  7
   
[3] [9,20] [15 7]

Solution1. Iteration BSF with queue 
// time: o(n)
// space: o(n) queue

p = i
reverse: p = n - i - 1

q: 3        level = 0
new list [3]
q: 9 20     level = 1 (level%2 == 1 add reverse)
new list [20 9]
q: 15 7
new list [15 7]


Solution2. Recursion DSF and give level (queue)
time: o(n)
space: o(h) : H is the height of the tree, i.e. the number of levels in the tree, which would be roughly o(logn)

vector<vector<int>> ans;
levelOrder(node, level)
    if (node == nullptr) return
    
    if (ans.size() < level + 1) ans.push_back(vector<int>())
    if (level % 2 == 0) ans[level].push_back(node->val)
    else ans[level].insert(ans[level].begin(), node->val)
    levelOrder(node->left, level + 1)
    levelOrder(node->right, level + 1)
levelOrder(root, 0)


Solution3. BSF with deque

3 20 9 1 2 4 5 8 7 6

st: 3 -> !r: pop_front, push_back(left, right)
--
st: 9 20 (3) -> r: pop_back, push_front(right, left)
st: 4 5 | 9 (3 20) -> r: pop_back, push_front(right, left)
st: 1 2 4 5 (3 20 9) -> !r: pop_front, push_back(left, right)
st: 2 4 5 | 6 7 (3 20 9 1) 
--
st: 5 4 2 1 (3 20 9 1 2 4 5)

**/

class Solution {
public:
    void zigzagLevelOrder_dfs(TreeNode* node, int level, vector<vector<int>>& ans) {
        if (node == nullptr) return;
                
        if (ans.size() < level + 1) ans.push_back({});             
        if (level % 2 == 0) ans[level].push_back(node->val);
        else ans[level].insert(ans[level].begin(), node->val);
        
        zigzagLevelOrder_dfs(node->left, level+1, ans);
        zigzagLevelOrder_dfs(node->right, level+1, ans);
    }

    vector<vector<int>> zigzagLevelOrder_1(TreeNode* root) {
        vector<vector<int>> res;
        zigzagLevelOrder_dfs(root, 0, res);
        return res;
    }
    
    vector<vector<int>> zigzagLevelOrder_2(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        
        int level=-1;
        while (!q.empty()) {
            auto n = q.size();
            level++;
            
            vector<int> level_values(n);
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();
                
                int p = i;
                if (level % 2 == 1) p = n - 1 - i;
                level_values[p] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }   
            res.push_back(level_values);
        }
        
        return res;
    }
    
    
    vector<vector<int>> zigzagLevelOrder_3(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);

        bool reverse = false;
        vector<vector<int>> res;
        while (!dq.empty()) {
            int dqSize = dq.size();
            vector<int> values;
            for (int i=0; i<dqSize; ++i) {
                TreeNode* node = nullptr;
                if (!reverse) {
                    node = dq.front(); dq.pop_front();
                }
                else {
                    node = dq.back(); dq.pop_back();
                }
                if (!node) continue;
                
                values.push_back(node->val);
                if (!reverse)
                {
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
                else {              
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);      
                }
            }
            if (values.size())
                res.push_back(values);
            reverse = !reverse;
        }
        return res;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //return zigzagLevelOrder_1(root);
        //return zigzagLevelOrder_2(root);
        return zigzagLevelOrder_3(root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{3,9,20,-777,-777,15,7});
    assert(Solution().zigzagLevelOrder(input1)
        == (vector<vector<int>> { {3}, {20,9}, {15,7} }));
    return 0;
}
