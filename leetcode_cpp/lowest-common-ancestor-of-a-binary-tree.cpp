#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// DFS post order
// time: o(n)
// space: o(n)

    5(0,2)
6(1)   2(1)
    7(0) 4(0)
p=6, q=2
 
  5(1,2)
6   2(0,1)
 7(0) 4(1)
p = 5, q = 4

 */
class Solution {
public:
    TreeNode* output = nullptr;
    int lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == NULL) return 0;

        int left = lca(node->left, p, q);
        int right = lca(node->right, p, q);
        int valid = (node == p || node == q) ? 1 : 0;
        if (left + right + valid == 2) {
            output = node;
        }

        return (left + right + valid > 0) ? 1 : 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return output;
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