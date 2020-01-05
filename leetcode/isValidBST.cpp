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
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x, ListNode *next = nullptr)
    : val(x)
    , next (next)
    {

    }

    bool operator==(const ListNode& r) const
    {
        auto result = val == r.val;
        if (next != nullptr && r.next != nullptr)
        {
            result &= *next == *r.next;
        }
        else
        {
            result &= (next == nullptr && r.next == nullptr);
        }
        return result;
    }
};

//       5
//   3       7
// 1   4   6   8

//       5
//   3       7
// 1   2   9   8

bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (!root) return true;

    auto val = root->val;
    if (min != nullptr && val <= min->val) return false;
    if (max != nullptr && val >= max->val) return false;

    if (!isValidBST(root->left, min, root)) return false;
    if (!isValidBST(root->right, root, max)) return false;

    return true;
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, nullptr, nullptr);
}


// bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
//     if(!root) return true;
//     if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
//         return false;
//     return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
// }


// bool isValidBST(TreeNode* root) {
//     return isValidBST(root, NULL, NULL);
// }

int main()
{
    assert(isValidBST(
        new TreeNode(vector<int>{2,1,3}))
        == true);
    assert(isValidBST(
        new TreeNode(vector<int>{5,1,4,-1,-1,3,6}))
        == false);
    assert(isValidBST(
        new TreeNode(vector<int>{2147483647}))
        == true);
    assert(isValidBST(
        new TreeNode(vector<int>{-2147483648, -1, 2147483647}))
        == true);
    return 0;
}