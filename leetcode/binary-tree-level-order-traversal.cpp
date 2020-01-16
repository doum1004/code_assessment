#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

//     3
//  9   20
//    15  17
//

// Recursion (DFS Pre order)
// time: o(n)
// space: o(n) vector
// vector<vector<int>> ans_;
// levelOrder(root, level)
// ans_[level].push(root->val)

// Iteration (BFS)
// time: o(n)
// space: o(n) queue
// q: 3
// q: 9 20
// q: 15 17

// queue(tree) q
// q: root
// while (!q.empty())
//  for (in size(q))
//      c = q.pop()
//      level_v.push(q.v)
//      q.push(q->left)
//      q.push(q->right)
// ans.push(level_v)

class Solution {
private:
    // Recursion
    vector<vector<int>> ans_;
    
public:
    void levelOrder(TreeNode* root, int level) {
        if (root == nullptr) return;
        if (ans_.size() < level + 1) ans_.push_back(vector<int>());

        ans_[level].push_back(root->val);
        levelOrder(root->left, level + 1);
        levelOrder(root->right, level + 1);
    }

    vector<vector<int>> levelOrder_R(TreeNode* root) {
        levelOrder(root, 0);
        return ans_;
    }

    vector<vector<int>> levelOrder_I(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);

        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> level;
            auto n = q.size();
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(level);
        }

        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrder_I(root);
        //return levelOrder_R(root);
    }
};

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode (int v)
//     : val(v)
//     , left(nullptr)
//     , right(nullptr)
//     {
        
//     }
//     TreeNode (vector<int> vals)
//     : val(-1)
//     , left(nullptr)
//     , right(nullptr)
//     {
//         auto h = false;
//         auto l = false;
//         queue<TreeNode*> q;
//         for (auto v : vals) {
            
//             if (!h)
//             {
//                 val = v;
//                 h = true;
//                 q.push(this);
//             }
//             else
//             {
//                 auto nxt = (v != -1) ? new TreeNode(v) : nullptr;
//                 l = !l;
                
//                 auto cur = q.front();
//                 if (!l)
//                 {
//                     if (cur != nullptr)
//                         cur->right = nxt;
//                     q.pop();
//                 }
//                 else
//                 {
//                     if (cur != nullptr)
//                         cur->left = nxt;
//                 }
                
//                 q.push(nxt);
//             }
//         }
//     }

//     bool operator==(const TreeNode& r) const
//     {
//         auto result = val == r.val;
//         result &= (left != nullptr) ? r.left != nullptr : r.left == nullptr;
//         result &= (right != nullptr) ? r.right != nullptr : r.right == nullptr;
//         if (result)
//         {
//             if (left != nullptr)
//             {
//                 result &= *left == *r.left;
//             }
//             if (right != nullptr)
//             {
//                 result &= *right == *r.right;
//             }
//         }
//         return result;
//     }
// };

// // input
// //       3
// //     
// //   9      20
// //       
// // 1   2  15   7

// // s (3)
// // s (9, 20)
// // s (1, 2, 15, 7)

// // output
// // [
// //   [3],
// //   [9,20],
// //   [15,7]
// // ]

// vector<vector<int>> ans_;

// void levelOrder_recursion(TreeNode* root, int level) {
//     if (ans_.size() == level) ans_.push_back(vector<int>());

//     auto &cur_ans = ans_.at(level);
//     cur_ans.push_back(root->val);

//     if (root->left != nullptr) levelOrder_recursion(root->left, level + 1);
//     if (root->right != nullptr) levelOrder_recursion(root->right, level + 1);
// }

// vector<vector<int>> levelOrder_recursion(TreeNode* root) {
//     if (root == nullptr) return ans_;
//     levelOrder_recursion(root, 0);
//     return ans_;
// }

// vector<vector<int>> levelOrder_iteration_stack(TreeNode* root) {
//     vector<vector<int>> ans;

//     stack<TreeNode*> s;
//     s.push(root);

//     stack<TreeNode*> s_level;

//     vector<int> v_level;
//     while (!s.empty())
//     {
//         auto top = s.top();
//         s.pop();
//         if (top == nullptr) continue;

//         v_level.push_back(top->val);

//         if (top->left != nullptr) s_level.push(top->left);
//         if (top->right != nullptr) s_level.push(top->right);

//         if (s.empty())
//         {
//             ans.push_back(v_level);
//             v_level.clear();
//             while (!s_level.empty())
//             {
//                 s.push(s_level.top());
//                 s_level.pop();
//             }
//         }
//     }

//     return ans;
// }

// vector<vector<int>> levelOrder_iteration_queue(TreeNode* root) {
//     vector<vector<int>> ans;
    
//     queue<TreeNode*> q;
//     if (root != nullptr)
//         q.push(root);

//     int level = 1;
//     while (!q.empty()) {

//         vector<int> vels;
//         auto end = q.size();
//         for (int i=0; i<end; i++) {
//             root = q.front();
//             q.pop();

//             vels.push_back(root->val);

//             if (root->left != nullptr) q.push(root->left);
//             if (root->right != nullptr) q.push(root->right);
//         }
//         ans.push_back(vels);

//         level++;
//     }

//     return ans;
// }

// vector<vector<int>> levelOrder(TreeNode* root) {
//     return levelOrder_recursion(root);
//     //return levelOrder_iteration_stack(root);
//     //return levelOrder_iteration_queue(root);
// }

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