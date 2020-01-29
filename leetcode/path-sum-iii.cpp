#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_map>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/path-sum-iii/

// Solution1. Recursion DSF (preorder)
// time: o(n^2)
// space: o(n)
10
15 5
18 8 3 (o)
21 11 6 3
16 9 4 -2
17 7
18 8 1 (o)

int ans = 0;
r (node, sum, vector<int> sums)
    if (node == nullptr) return;
    sums.push_back(0);
    for (int i=0; i<sums.size(); ++i)
        sums[i] += node->val
        if (sums[i] == sum)
            ans++;
    r(node->left, sum, sums);
    r(node->right, sum, sums);
    
r(root, sum, vector<int>())

// Solution2: recursion DSF preorder with dp(hash). store sum of all path of parent. And find parent sum equal to cursum - target
// time: o(n)
// space: o(n)

10 -> [10: 1]
5 -> [10: 1, 15: 1]
3 -> [10: 1, 15: 1, 18: 1] 18-8 = 10. cnt = 1, rcnt = 1. total 2
3 -> [10, 1, 15: 1, 18: 1, 21: 1]
-2 -> [10, 1, 15: 1, 18: 1, 21: 0, 16: 1]
2 -> [10, 1, 15: 1, 18: 1, 21: 0, 16: 0, 19: 1]
1 -> [10, 1, 15: 1, 18: 1, 21: 0, 16: 0, 19: 1, 18: 1] 18-8 = 10. cnt = 1


*/
class Solution {
public:
    int pathSum(TreeNode* node, int sum, vector<int> sums) {
        if (node == nullptr) return 0;
        auto cnt = 0;
        sums.push_back(0);
        for (auto &n : sums) {
            n += node->val;
            if (n == sum) cnt++;
        }
        int lcnt = pathSum(node->left, sum, sums);
        int rcnt = pathSum(node->right, sum, sums);
        
        return cnt + lcnt + rcnt;
    }
    
    int pathSum_recursion1(TreeNode* root, int sum) {
        return pathSum(root, sum, vector<int>());
    }
    
    int pathSum_recursion2(TreeNode *root, int sum) {
        unordered_map<int, int> hash;
        return path(root, 0, sum, hash);
    }
    
    int path(TreeNode *node, int pre, int target, unordered_map<int, int>& hash) {
        if (node == nullptr) return 0;
        
        auto cursum = pre + node->val;
        auto curcnt = hash.count(cursum-target) ? hash[cursum-target] : 0;
        if (cursum == target) curcnt++;
        hash[cursum]++;
        
        auto lcnt = path(node->left, cursum, target, hash);
        auto rcnt = path(node->right, cursum, target, hash);
        
        hash[cursum]--;
        return curcnt + lcnt + rcnt;
    }
    
    int pathSum(TreeNode* root, int sum) {
        //return pathSum_recursion1(root, sum);
        return pathSum_recursion2(root, sum);
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