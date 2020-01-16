#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

//     1(6)
//2(2)    3(3)

//        -10 (34)
//  9(9)            20(42, 35)
//           15(15)      7(7)

// DFS post order
// Recursive
// time: o(n)
// space: o(n)

// ans_max = INT_MIN;
// int sum(node)
//   if (node == nullptr) return 0;
//
//   l = sum(node->left)
//   r = sum(node->right)
//   ans_max = max(ans_max, l + r + node->val)
//   return node->val + max(l, r)
// sum(root)
// return ans;

class Solution {
private:
    int ans = INT_MIN;

public:
    int getMax(TreeNode* root) {
        if (root == nullptr) return 0;
        
        auto l = max(getMax(root->left), 0);
        auto r = max(getMax(root->right), 0);
        ans = max(ans, l + r + root->val);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        getMax(root);
        return ans;
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