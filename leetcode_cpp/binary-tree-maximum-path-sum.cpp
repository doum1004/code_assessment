#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-maximum-path-sum/

DFS postorder
time: o(n)
space: o(n)
     1(6)
2(2)   3(3)  

        -10 (34)
9(9)            20(42, 35)
        15(15)      7(7)

**/

class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum_recursive(TreeNode* root) {
        if (root == nullptr) return 0;
        
        auto l = max(maxPathSum_recursive(root->left), 0);
        auto r = max(maxPathSum_recursive(root->right), 0);
        maxSum = max(maxSum, l+r+root->val);
        
        return root->val + max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
        maxPathSum_recursive(root);
        return maxSum;
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{1,2,3});
    assert(Solution().maxPathSum(input1)
        == (6));
    auto input2 = vectorToTree(vector<int>{-10,9,20,-777,-777,15,7});
    assert(Solution().maxPathSum(input2)
        == (42));

    return 0;
}