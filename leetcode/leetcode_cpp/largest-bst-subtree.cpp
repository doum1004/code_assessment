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
    void BSF(TreeNode* root, int& min_v, int& max_v, int& count) {
        if (root == nullptr) {
            min_v = INT_MAX;
            max_v = INT_MIN;
            count = 0;
            return;
        }
        
        int min_l, max_l, count_l;
        int min_r, max_r, count_r;
        BSF(root->left, min_l, max_l, count_l);
        BSF(root->right, min_r, max_r, count_r);
        
        if (max_l < root->val && min_r > root->val) {
            min_v = min(min_l, root->val);
            max_v = max(max_r, root->val);
            count = count_l + count_r + 1;
        }
        else {
            min_v = INT_MIN;
            max_v = INT_MAX;
            count = max(count_l, count_r);
        }
    }
    
    int largestBSTSubtree(TreeNode* root) {
        int min_v, max_v, count;
        BSF(root, min_v, max_v, count);
        return count;
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