/*
https://leetcode.com/problems/same-tree

Sol1. DFS
time: o(n)
space: o(n)

Sol2. BFS with stack or queue
time: o(n)
space: o(n)

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree_dfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSameTree_bfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (q1.size() && q2.size()) {
            int q1Size = q1.size();
            int q2Size = q2.size();
            if (q1Size != q2Size)
            {
                printf("Failed 1");
                return false;
            }
            
            for (int i=0; i<q1Size; ++i) {
                auto node1 = q1.front(); q1.pop();
                auto node2 = q2.front(); q2.pop();
                if (node1->val != node2->val) {
                    printf("Failed 2");
                    return false;
                }

                if (!node1->left != !node2->left) return false;
                if (!node1->right != !node2->right) return false;

                if (node1->left) q1.push(node1->left);
                if (node1->right) q1.push(node1->right);
                
                if (node2->left) q2.push(node2->left);
                if (node2->right) q2.push(node2->right);
            }
        }
                    printf("Failed 3");
        return q1.size() == q2.size();
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTree_bfs(p, q);
    }
};