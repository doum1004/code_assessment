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
 /*
 https://leetcode.com/problems/binary-search-tree-iterator
 
 Solution1. partial preorder with queue
 time
 - constructor: o(n)
 - next: o(1)
 - hasNext: o(1)
space: o(n)

 Solution2. partial inorder with stack
 time
 - constructor: o(h)
 - next: o(1)
 - hasNext: o(1)
 space: o(h)
 */
class BSTIterator1 {
public:
    BSTIterator1(TreeNode* root) {
        dfs(root);
    }
    
    void dfs(TreeNode* node) {
        if (!node) return;
        
        dfs(node->left);
        q.push(node);
        dfs(node->right);
    }

    int next() {
        auto t = q.front();
        q.pop();
        return t->val;
    }
    
    bool hasNext() {
        return q.size();
    }

    queue<TreeNode*> q;
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* node) {
        if (!node) return;
        
        while (node) {
          s.push(node);
          node = node->left;
        }
    }

    int next() {
        auto n = s.top(); s.pop();
        partialInorder(n->right);
        return n->val;
    }
    
    bool hasNext() {
        return s.size();
    }

    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */