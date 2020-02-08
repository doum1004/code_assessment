#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    : val(x), left(NULL), right(NULL) {}
};

bool isEqual(TreeNode* l, TreeNode* r) {
    if (l != nullptr && r != nullptr) return (l->val == r->val && isEqual(l->left, r->left) && isEqual(l->right, r->right));
    return (l == nullptr && r == nullptr) ? true : false;
}

TreeNode* vectorToTree(vector<int> list) {
    TreeNode* tree = nullptr;
    
    queue<TreeNode*> q;
    bool flag = false;
    for (auto item : list) {
        auto n = (item != -777) ? new TreeNode(item) : nullptr;
        if (q.empty()) {
            tree = n;
        }
        else {
            auto p = q.front();
            if (!flag) {
                p->left = n;
                flag = true;
            }
            else {
                p->right = n;
                q.pop();
                flag = false;
            }
        }
        q.push(n);
    }

    return tree;
}