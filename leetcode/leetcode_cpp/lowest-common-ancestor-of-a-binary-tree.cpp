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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

 Solution1. Build ChildParent map (child: parent, level) and find common parent
 time: o(n) n + n + n
 space: o(n);

 Solution2-3. DFS return pointer if it hits p or q (or null)
 time: o(n)
 space: o(n) height
 */
class Solution {
public:
    void buildMap(TreeNode* node, int level, unordered_map<TreeNode*, pair<TreeNode*, int>>& m) {
        if (!node) return;
        
        if (node->left) m[node->left] = {node, level};
        if (node->right) m[node->right] = {node, level};
        buildMap(node->left, level+1, m);
        buildMap(node->right, level+2, m);
    }
    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, pair<TreeNode*, int>> m; // child: (parent, parent level)
        if (p == q) return p;
        if (p == root || q == root) return root;
        m[root] = {nullptr, -1};
        buildMap(root, 0, m);

        if (!m.count(p)) return nullptr;
        if (!m.count(q)) return nullptr;

        auto pLevel = m[p].second;
        auto qLevel = m[q].second;

        unordered_set<TreeNode*> v;
        auto cur = pLevel < qLevel ? p : q;
        while (cur) {
            v.insert(cur);
            cur = m[cur].first;
        }

        cur = pLevel < qLevel ? q : p;
        while (cur) {
            if (v.count(cur)) return cur;
            cur = m[cur].first;
        }
        return nullptr;
    }

    TreeNode* ans = nullptr;
    int dfs(TreeNode* node, TreeNode* a, TreeNode* b) {
        if (!node) return 0;
        int val = dfs(node->left, a, b);
        val += dfs(node->right, a, b);
        val += (node == a || node == b) ? 1 : 0;
        if (val == 2) {
            ans = node;
            return 0;
        }
        return val;
    }

    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    TreeNode* lowestCommonAncestor_3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto l = lowestCommonAncestor_3(root->left, p, q);
        auto r = lowestCommonAncestor_3(root->right, p, q);
        if (l != nullptr && r != nullptr) return root;
        return l ? l : r;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestor_3(root, p, q);
    }
};

int main()
{
    auto input1 = new TreeNode(3);
    input1->left = new TreeNode(5);
    input1->left->left = new TreeNode(6);
    input1->left->right = new TreeNode(2);
    input1->left->right->left = new TreeNode(7);
    input1->left->right->right = new TreeNode(4);
    input1->right = new TreeNode(1);
    input1->right->left = new TreeNode(0);
    input1->right->right = new TreeNode(8);
    assert(Solution().lowestCommonAncestor(input1, input1->left, input1->right)
        == input1);
    assert(Solution().lowestCommonAncestor(input1, input1->left, input1->left->right->right)
        == input1->left);
    return 0;
}