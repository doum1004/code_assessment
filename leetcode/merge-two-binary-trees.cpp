#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/merge-two-binary-trees/
 
//Soltuion1. recursive DSF preorder (merge into node1)
//time: o(n)
//space: o(n) recursion
merge_recursive(node1, node2)
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;
    
    node1->val += node2->val;
    node1->left = merge_recursive(node1->left, node2->left);
    node1->right = merge_recursive(node2->right, node2->right);
    return node1;

//Soltuion2. iteration BSF (merge into node1)
//time: o(n)
//space: o(n) queue
1. add t1, t2 in queue
2. iterate to pop node1 node2
3. merge val in node1
4. push both left if both are not empty
5. if one of them empty set on node1
6. same for right


merge_recursive(node1, node2)
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;
    
    node1->val += node2->val;
    node1->left = merge_recursive(node1->left, node2->left);
    node1->right = merge_recursive(node2->right, node2->right);
    return node1;
    
*/
class Solution {
public:
    TreeNode* mergeTrees_recursion(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;

        t1->val += t2->val;
        
        t1->left = mergeTrees_recursion(t1->left, t2->left);
        t1->right = mergeTrees_recursion(t1->right, t2->right);
        
        return t1;
    }
    
    TreeNode* mergeTrees_iteration(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        
        queue<TreeNode*> q;
        q.push(t1);
        q.push(t2);
        
        while (!q.empty()) {
            auto n1 = q.front();
            q.pop();
            auto n2 = q.front();
            q.pop();
            cout << n1->val << "," << n2->val << endl;
            n1->val += n2->val;
            
            if (n1->left && n2->left) {
                q.push(n1->left);
                q.push(n2->left);
            }
            else if (n1->left || n2->left) {
                n1->left = (n1->left) ? n1->left : n2->left;
            }
            
            if (n1->right && n2->right) {
                q.push(n1->right);
                q.push(n2->right);
            }
            else if (n1->right || n2->right) {
                n1->right = (n1->right) ? n1->right : n2->right;
            }
        }
        
        return t1;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //return mergeTrees_recursion(t1, t2);
        return mergeTrees_iteration(t1, t2);
    }
};

int main()
{
    auto input1_1 = new TreeNode(1);
    input1_1->left = new TreeNode(3);
    input1_1->right = new TreeNode(2);
    input1_1->left->left = new TreeNode(5);
    auto input1_2 = new TreeNode(2);
    input1_2->left = new TreeNode(1);
    input1_2->right = new TreeNode(3);
    input1_2->left->right = new TreeNode(4);
    input1_2->right->right = new TreeNode(7);
    auto ans = Solution().mergeTrees(
        input1_1, input1_2);
    assert(ans->val == 3);
    assert(ans->left->right->val == 4);
    return 0;
}