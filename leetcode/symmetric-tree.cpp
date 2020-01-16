#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// recursion (DFS, preoreder)
// time: o(n)
// space: o(n) (o(height n) but linear o(n))

//    1
// 2    2
//3  4 4  3
// root root
// root->val == root->val
// root->left, root->right
// root->right, root->left

// iteration (DFS)
// time: o(n)
// space: o(n) queue
// queue<tree> q;
// q: 1, 1
// root_l = q.pop
// root_r = q.pop
// compare
// q: root_l->left, root_r->right, root_l->right, root_r->left

class Solution {
public:
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;

        if (l == nullptr || r == nullptr || l->val != r->val) return false;
        if (!isSymmetric(l->left, r->right)) return false;
        if (!isSymmetric(l->right, r->left)) return false;

        return true;
    }

    bool isSymmetric_I(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();

            if (l == nullptr && r == nullptr) continue;
            if (l == nullptr || r == nullptr || l->val != r->val) return false;

            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetric_I(root);
        //return isSymmetric(root, root);
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


// //       1
// //   2      2
// // 3   4  4   3

// //       1
// //   2      2
// //     3       3

// //          1
// //     2          2
// //  3     4    4     3
// //5   6            6   5

// bool isSymmetric_iteration1(TreeNode* root) {
//     if (root == nullptr) return true;
    
//     queue<TreeNode*> s;
//     s.push(root);
//     s.push(root);
//     while (!s.empty()) {
//         auto l = s.front();
//         s.pop();
//         auto r = s.front();
//         s.pop();
//         if (l == nullptr && r == nullptr) continue;
//         if (l == nullptr || r == nullptr) return false;

//         if (l->val != r->val) return false;

//         s.push(l->left);
//         s.push(r->right);
//         s.push(l->right);
//         s.push(r->left);
//     }
    
//     return true;
// }

// bool isSymmetric_iteration2(TreeNode* root) {
//     if (root == nullptr) return true;
    
//     queue<TreeNode*> s;
//     auto l = root;
//     auto r = root;

//     while (!s.empty() || l != nullptr) {
//         if ((l != nullptr && r == nullptr) || (l == nullptr && r != nullptr)) return false;
        
//         if (l != nullptr)
//         {
//             s.push(l);
//             s.push(r);
//             l = l->left;
//             r = r->right;
//         }
//         else
//         {
//             l = s.front();
//             s.pop();
//             r = s.front();
//             s.pop();

//             if (l->val != r->val) return false;

//             l = l->right;
//             r = r->left;
//         }
//     }

//     return true;
// }

// bool isSymmetric_recursion(TreeNode* s, TreeNode* t) {
//     if (s == nullptr && t == nullptr) return true;
//     if (s == nullptr || t == nullptr) return false;

//     auto ans = s->val == t->val;
//     ans &= isSymmetric_recursion(s->left, t->right); 
//     ans &= isSymmetric_recursion(s->right, t->left);

//     return ans;
// }

// bool isSymmetric(TreeNode* root) {
//     return isSymmetric_iteration1(root);
//     //return isSymmetric_recursion(root, root);
// }

int main()
{
    auto input1 = vectorToTree(vector<int>{1,2,2,3,4,4,3});
    assert(Solution().isSymmetric(input1)
        == true);

    return 0;
}