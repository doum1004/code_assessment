#include <iostream>
#include <cassert>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/count-univalue-subtrees/

//solution1. dfs recursion (inorder)
//time: o(n)
//space: o(n). recursion(depth)

 */
class Solution {
public:
    bool dfs(TreeNode* node, int& res) {
        if (node == nullptr) return false;
        
        auto isUni = true;
        if (node->left) isUni &= dfs(node->left,res) && node->left->val == node->val;
        if (node->right) isUni &= dfs(node->right,res) && node->right->val == node->val;
        
        if (isUni) res++;
        return isUni;
    }
    
    int countUnivalSubtrees_dfs(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        return countUnivalSubtrees_dfs(root);
    }
};

int main()
{
    auto input1 = vectorToTree({5,1,5,5,5,-777,5});
    assert(Solution().countUnivalSubtrees(input1) == (4));

    return 0;
}
