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

TreeNode* vectorToTree(vector<int> list) {
    TreeNode* tree = nullptr;
    
    queue<TreeNode*> q;
    for (auto item : list) {
        auto n = new TreeNode(item);
        if (q.empty()) {
            tree = n;
        }
        else {
            auto p = q.front();
            if (p->left == nullptr) {
                p->left = n;
            }
            else {
                p->right = n;
                q.pop();
            }
        }
        q.push(n);
    }

    return tree;
}