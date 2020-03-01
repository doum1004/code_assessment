#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/validate-binary-search-tree/

 2
1 3

 5
1  4
  3 6

// Recursion DFS (inorder)
// time: o(n)
// space: o(n)

isValidBST(parentNode, minNode, maxNode)
    if (parentNode == nullptr) return true;

    if (!isValidBst(parentNode->left, minNode, parentNode)) return false;
    if (minNode != nullptr && parentNode->val < minNode->val) return false;
    if (maxNode != nullptr && parentNode->val > maxNode->val) return false;
    if (!isValidBst(parentNode->right, parentNode, maxNode)) return false;

    return true

isValidBST(root, nullptr, nullptr)

// Iterative DFS inorder
// time: o(n)
// space: o(n) stack

minval = INT64_MIN;
while (!s.empty() && r != nullptr) {
    if (r != nullptr) {
        s.push(r);
        r = r->left;
    }
    else {
        r = s.top();
        s.pop();
        if (minval >= r->val) return false;
        minval = r->val;
        r = r->right;
    }
}


**/

class Solution {
public:
    bool isValidBST_recursive(TreeNode* parentNode, TreeNode* minNode, TreeNode* maxNode) {
        if (parentNode == nullptr) return true;
        
        if (!isValidBST_recursive(parentNode->left, minNode, parentNode)) return false;
        if (!isValidBST_recursive(parentNode->right, parentNode, maxNode)) return false;

        if (minNode != nullptr && parentNode->val <= minNode->val) return false;
        if (maxNode != nullptr && parentNode->val >= maxNode->val) return false;

        return true;
    }
    
    bool isValidBST_iterative(TreeNode* root) {
        if (root == nullptr) return true;
        
        stack<TreeNode*> s;
        auto minval = INT64_MIN;
        
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                if (minval >= root->val) return false;
                minval = root->val;
                root = root->right;
            }
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        //return isValidBST_recursive(root, nullptr, nullptr);
        return isValidBST_iterative(root);
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