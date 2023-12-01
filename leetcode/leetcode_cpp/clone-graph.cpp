/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
https://leetcode.com/problems/clone-graph

Solution1. DFS
time: o(n)
space: o(n)

Solution2. BFS
time: o(n)
space: o(n)
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& hm) {
        if (!node) return nullptr;
        if (hm.count(node)) return hm[node];
        
        hm[node] = new Node(node->val);
        int nCount = node->neighbors.size();
        for (int i=0; i<nCount; ++i) {
            auto n = node->neighbors[i];
            hm[node]->neighbors.push_back(dfs(n, hm));
        }
        return hm[node];
    }

    Node* cloneGraph_1(Node* node) {
        unordered_map<Node*, Node*> hm;
        return dfs(node, hm);        
    }

    Node* cloneGraph_2(Node* node) {
        if (!node) return nullptr;
        queue<pair<Node*, Node*>> q;
        q.push({nullptr, node});

        unordered_map<Node*, Node*> hm;
        Node* root = nullptr;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i=0; i<qSize; ++i) {
                auto nodePair = q.front(); q.pop();
                auto parent = nodePair.first;
                auto child = nodePair.second;
                if (!child) continue;
                if (!hm.count(child))
                {
                    auto clonedChild = new Node(child->val);
                    hm[child] = clonedChild;

                    if (parent)
                        parent->neighbors.push_back(clonedChild);
                    else
                        root = clonedChild;
                    
                    for (auto neighbor : child->neighbors) {
                        q.push({clonedChild, neighbor});
                    }
                }
                else {
                    parent->neighbors.push_back(hm[child]);
                }
            }
        }
        return root;
    }

    Node* cloneGraph(Node* node) {
        return cloneGraph_2(node);        
    }
};