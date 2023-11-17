/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

Solution1. BST recursion
find middle and put it on root of others (preorder)

def bst(l, r, nums):
    if (..) return none
    m = (l+r)/2
    node = node(nums[m])
    node.left = bst(l, m-1)
    node.right = bst(m + 1, r)
    return node
bst ...

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bst(vector<int>& nums, int l, int r) {
        if (r < l || l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = bst(nums, l, m - 1);
        node->right = bst(nums, m + 1, r);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }
};