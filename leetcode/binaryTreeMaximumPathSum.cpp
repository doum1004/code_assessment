#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int v)
    : val(v)
    , left(nullptr)
    , right(nullptr)
    {
        
    }
    TreeNode (vector<int> vals)
    : val(-1)
    , left(nullptr)
    , right(nullptr)
    {
        auto h = false;
        auto l = false;
        queue<TreeNode*> q;
        for (auto v : vals) {
            
            if (!h)
            {
                val = v;
                h = true;
                q.push(this);
            }
            else
            {
                auto nxt = (v != -1) ? new TreeNode(v) : nullptr;
                l = !l;
                
                auto cur = q.front();
                if (!l)
                {
                    if (cur != nullptr)
                        cur->right = nxt;
                    q.pop();
                }
                else
                {
                    if (cur != nullptr)
                        cur->left = nxt;
                }
                
                q.push(nxt);
            }
        }
    }

    bool operator==(const TreeNode& r) const
    {
        auto result = val == r.val;
        result &= (left != nullptr) ? r.left != nullptr : r.left == nullptr;
        result &= (right != nullptr) ? r.right != nullptr : r.right == nullptr;
        if (result)
        {
            if (left != nullptr)
            {
                result &= *left == *r.left;
            }
            if (right != nullptr)
            {
                result &= *right == *r.right;
            }
        }
        return result;
    }
};

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6

// Input: [-10,9,20,null,null,15,7]

//       -10 (34)
//     /       \
//   9(9)       20 (35) 42
//          /       \
//         15(15)    7 (7)

// Output: 42

int max_ = INT_MIN;

int maxGain(TreeNode* root) {
    if (root == nullptr) return 0;
    auto ans = 0;

    auto l_max = max(maxGain(root->left), 0);
    auto r_max = max(maxGain(root->right), 0);

    max_ = max(max_, root->val + l_max + r_max);

    return root->val + max(l_max, r_max);
}

int maxPathSum(TreeNode* root) {
    maxGain(root);
    return max_;
}

int main()
{
    assert(maxPathSum(
        new TreeNode(vector<int>{1,2,3}))
        == 6);
    assert(maxPathSum(
        new TreeNode(vector<int>{-10,9,20,-1,-1,15,7}))
        == 42);
    return 0;
}