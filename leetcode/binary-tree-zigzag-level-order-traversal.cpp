#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// BFS Iteration
// queue for root. vector for children
// time: o(n)
// space: o(n) queue, vector

// q(3)

// q
// v(3)
// q(9, 20)

// q(20)
// v(,9)
// q
// v(20,9)
// q(15, 7)

// q(7)
// v(15,)
// q
// v(15,7)

// DFS (Pre order) Recursion
// vector<vector<int>> by level
// level % 2 == 0 ? add from tail

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            auto level_vector = vector<int>(n);
            for (int i=0; i<n; ++i) {
                auto node = q.front();
                q.pop();
                auto p = (level % 2 == 0) ? n - i - 1 : i;
                level_vector[p] = node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(level_vector);
            level++;
        }

        return ans;
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

// //      3
// //     / \
// //    9  20
// //      /  \
// // 1 2 15   7

// // q (3)
// // s (9 20) l, r (flag)

// // q (20 9)
// // s (7 15 2 1) r, l (!flag)

// // q (1 2 15 7)

// // s (20 9)
// // s (15 7)

// // [
// //   [3],
// //   [20,9],
// //   [15,7]
// // ]

// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//     vector<vector<int>> ans;

//     queue<TreeNode*> q;
//     if (root != nullptr)
//         q.push(root);

//     auto flag = true;
//     while (!q.empty()) {
//         auto end = q.size();
//         vector<int> values(end);
//         for (int i=0; i<end; i++) {
//             root = q.front();
//             q.pop();

//             auto index = (flag) ? i : end - i - 1;
//             values[index] = root->val;
            
//             if (root->left != nullptr) q.push(root->left);
//             if (root->right != nullptr) q.push(root->right);
//         }

//         ans.push_back(values);
        
//         flag = !flag;
//     }

//     return ans;
// }

// vector<vector<int>> zigzagLevelOrder_old(TreeNode* root) {
//     vector<vector<int>> ans;

//     queue<TreeNode*> q;
//     if (root != nullptr)
//         q.push(root);

//     auto flag = true;
//     while (!q.empty()) {
//         vector<int> values;

//         stack<TreeNode*> s;
//         auto end = q.size();
//         for (int i=0; i<end; i++) {
//             root = q.front();
//             q.pop();

//             values.push_back(root->val);

//             if (flag)
//             {
//                 if (root->left != nullptr) s.push(root->left);
//                 if (root->right != nullptr) s.push(root->right);
//             }
//             else
//             {
//                 if (root->right != nullptr) s.push(root->right);
//                 if (root->left != nullptr) s.push(root->left);
//             }
//         }

//         ans.push_back(values);
        
//         while (!s.empty()) {
//             root = s.top();
//             s.pop();
//             q.push(root);
//         }

//         flag = !flag;
//     }

//     return ans;
// }

int main()
{
    auto input1 = vectorToTree(vector<int>{3,9,20,-777,-777,15,7});
    assert(Solution().zigzagLevelOrder(input1)
        == (vector<vector<int>> { {3}, {20,9}, {15,7} }));
    return 0;
}