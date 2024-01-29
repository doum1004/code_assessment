#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_map>

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
 https://leetcode.com/problems/path-sum-iii
 
 1. DFS
 time: o(n^2)
 space: o(n)

 2. DFS with map. store sum of all path of parent. And find parent sum equal to cursum - target
 time: o(n)
 space: o(n)
 */
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int& targetSum, long long cur) {
        if (!root) return;
        cur += root->val;
        if (cur == targetSum) res += 1;
        dfs(root->left, targetSum, cur);
        dfs(root->right, targetSum, cur);
    }

    int pathSum_1(TreeNode* root, int& targetSum) {
        if (!root) return 0;
        dfs(root, targetSum, 0);
        pathSum_1(root->left, targetSum);
        pathSum_1(root->right, targetSum);
        return res;
    }

    int dfs(TreeNode* root, int& targetSum, long long sum, unordered_map<long long, int>& m) {
        if (!root) return 0;
        sum += root->val;
        int cnt = (sum == targetSum) ? 1 : 0;
        if (m.count(sum - targetSum))
            cnt += m[sum - targetSum];
        m[sum] += 1;
        cnt += dfs(root->left, targetSum, sum, m);
        cnt += dfs(root->right, targetSum, sum, m);
        m[sum] -= 1;
        return cnt;
    }

    int pathSum_2(TreeNode* root, int& targetSum) {
        unordered_map<long long, int> m;
        return dfs(root, targetSum, 0, m);
    }

    int pathSum(TreeNode* root, int targetSum) {
        return pathSum_2(root, targetSum);
    }
};

int main()
{
    auto input1 = new TreeNode(10);
    input1->left = new TreeNode(5);
    input1->left->left = new TreeNode(3);
    input1->left->left->left = new TreeNode(3);
    input1->left->left->right = new TreeNode(-2);
    input1->left->right = new TreeNode(2);
    input1->left->right->right = new TreeNode(1);
    input1->right = new TreeNode(-3);
    input1->right->right = new TreeNode(11);

    assert(Solution().pathSum(input1, 8)
        == (3));
    return 0;
}