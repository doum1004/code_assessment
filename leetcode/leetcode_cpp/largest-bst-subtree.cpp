#include <iostream>
#include <cassert>

#include <vector>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/largest-bst-subtree/

// Solution1. DSF (postorder)
// time: o(n)
// space: o(n) recursion

1. DSF postorder from root
2. In BSF recursion
2.1. if node is empty return { intmax, intmin, 0 } // min, max, count (which means it is acceptable but no count)
2.2. visit left, right
2.3. if node.val > left max && node.val < right min, return min(l.min,val), max(r.max,val), count+1
2.4. else return {MAX, MIN, max(l[2],r[2])} // return will be used for answer


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nbSubBSF(TreeNode* node) {
        if (!node) return {INT_MAX,INT_MIN,0};
        
        auto l = nbSubBSF(node->left);
        auto r = nbSubBSF(node->right);
        auto v = node->val;
        if (l[1] < v && r[0] > v) {
            return {min(v,l[0]), max(v,r[1]), l[2]+r[2]+1};
        }
        return {INT_MIN,INT_MAX,max(l[2],r[2])};
    }
    
    int largestBSTSubtree_DSF(TreeNode* root) {
        return nbSubBSF(root)[2];
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtree_DSF(root);
    }
};

int main()
{
    auto input1 = new TreeNode(10);
    input1->left = new TreeNode(5);
    input1->right = new TreeNode(15);
    input1->left->left = new TreeNode(1);
    input1->left->right = new TreeNode(8);
    input1->right->right = new TreeNode(7);

    assert(Solution().largestBSTSubtree(input1)
        == (3));
    return 0;
}