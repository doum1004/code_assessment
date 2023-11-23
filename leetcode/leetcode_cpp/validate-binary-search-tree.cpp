#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

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
https://leetcode.com/problems/validate-binary-search-tree

 Solution1. DSF inorder (passing min, max nodes)
 time: o(n)
 space: o(n)

 1. build dfs to compare min, max node on current node
 - inorder traversal
 - compare min max nodes
 - iterate left(min, node), right(node, max)


 Solution2. BSF
 time: o(n)
 spcae: o(n)

 */
class Solution {
public:
    bool dfs(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;        
        if (minNode && node->val <= minNode->val) return false;
        if (maxNode && node->val >= maxNode->val) return false;
        return dfs(node->left, minNode, node) && dfs(node->right, node, maxNode);
    }

    bool isValidBST_1(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    
    bool isValidBST_2(TreeNode* root) {
        if (!root) return true;
        queue<vector<TreeNode*>> q;
        q.push({root, nullptr, nullptr});
        while (!q.empty()) {
            int n = q.size();
            for (int i=0; i<n; ++i) {
                auto values = q.front();
                q.pop();
                auto node = values[0];
                auto minNode = values[1];
                auto maxNode = values[2];
                if (minNode && minNode->val >= node->val) return false;
                if (maxNode && maxNode->val <= node->val) return false;
                if (node->left) q.push({node->left, minNode, node});
                if (node->right) q.push({node->right, node, maxNode});
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST_2(root);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{2,1,3});
    assert(Solution().isValidBST(input1)
        == true);

    // assert(isValidBST(
    //     new TreeNode(vector<int>{2,1,3}))
    //     == true);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{5,1,4,-1,-1,3,6}))
    //     == false);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{2147483647}))
    //     == true);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{-2147483648, -1, 2147483647}))
    //     == true);
    return 0;
}