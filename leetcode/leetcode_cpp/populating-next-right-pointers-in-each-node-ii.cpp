/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
Solution1. BSF
time: o(n)
space: o(n)

Solution2. DSF
time: o(n)
space: o(n)

*/
class Solution {
public:
    void dfs(Node* node, int level, unordered_map<int, Node*>& s) {
        if (!node) return;
        if (s.count(level)) {
            s[level]->next = node;
        }
        node->next = nullptr;
        s[level] = node;
        dfs(node->left, level+1, s);
        dfs(node->right, level+1, s);
    }
    Node* connect_1(Node* root) {
        unordered_map<int, Node*> s;
        dfs(root, 0, s);
        return root;
    }
    Node* connect_2(Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            Node* previous = nullptr;
            for (int i=0; i<qSize; ++i) {
                auto node = q.front(); q.pop();
                if (!node) continue;

                if (previous)
                    previous->next = node;
                previous = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);                
            }
        }
        return root;
    }
    Node* connect(Node* root) {
        return connect_2(root);
    }
};