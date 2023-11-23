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
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

Solution1. divide and conquer(recursion)
time: o(n^2) visit node(n) * find inroder pivot(n)
space: o(n)

Solution2. divide and conquer + map (find pivot index quick)
time: o(n)
space: o(n) recursion + map

*/


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_2(preorder, inorder);
    }

    TreeNode* buildTree_1(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return build(preorder, inorder, idx, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int pivot = left;
        int val = preorder[idx];
        while (inorder[pivot] != val) pivot++; // improve this with map

        idx++;
        auto node = new TreeNode(val);
        node->left = build(preorder, inorder, idx, left, pivot-1);
        node->right = build(preorder, inorder, idx, pivot+1, right);
        return node;
    }

    map<int,int> mp;    
    TreeNode* buildTree_2(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); ++i)
            mp[inorder[i]] = i;
        int idx = 0;
        return build_2(preorder, inorder, idx, 0, inorder.size() - 1);
    }

    TreeNode* build_2(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int val = preorder[idx];
        int pivot = mp[val];
        
        idx++;
        auto node = new TreeNode(val);
        node->left = build_2(preorder, inorder, idx, left, pivot-1);
        node->right = build_2(preorder, inorder, idx, pivot+1, right);
        return node;
    }
};