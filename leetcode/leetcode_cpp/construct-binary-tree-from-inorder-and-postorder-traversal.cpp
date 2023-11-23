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
 
/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

Solution1. Divide and conquer (recursion). Find root from postorder and build tree from inorder
time: o(n^2)
space: o(n)

Solution2. Solution1 + map to store inorder index
time: o(n)
space: o(n)

*/

class Solution {
public:
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        for (int i=0; i<inorder.size(); ++i)
            m[inorder[i]] = i;
        return build(inorder, postorder, idx, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &idx, int l, int r) {
        if (l > r) return nullptr;
        auto value = postorder[idx];
        auto i_inorder = m[value];
        //while (value != inorder[i_inorder]) i_inorder++;
        
        idx--;
        auto node = new TreeNode(value);
        node->right = build(inorder, postorder, idx, i_inorder + 1, r);
        node->left = build(inorder, postorder, idx, l, i_inorder - 1);
        return node;
    }
};