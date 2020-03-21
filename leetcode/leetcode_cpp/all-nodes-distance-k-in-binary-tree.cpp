#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

//Solution1. Search from root. DSF in recursion. Get target dist and path. And iterate tree to get dist from target to cur.
//time: o(n). 2n
//space: o(n). 2n + hashset(paths, but this is pointers)

1. find target (DSF inorder). store path and distance
2. Visit node (DSF inorder)
2.1 if a node is not contained, dist += 1
2.2 if a node is contained, dist -= 1

ex) target 4 dist=3
          2
     1        3 
   4   8       5
  7      11
 6
9

1. 4 (distance:2. path:2,1,4)
2. dfs
2.1. visit 2(distance:2)
2.2. visit 1(distnace:1)
2.3. visit 4(distance:0)
2.4. visit 7(distnace:1)
2.5. visit 6(distnace:2)
2.6. visit 9(distnace:3) match
2.7. visit 8(distance:2)
2.8. visit 11(dinstnace:3) match
...
2.8. visit 3(distance:3) match

//Solution2. Search From target. DSF to store all parent node info. And From target to BFS search
// time: o(n). DSF(n, store parentinfo) + BSF(n, find target K)
// space: o(n). DSF recursion

1. DSF to store all parent node on map
2. BSF from target (queue<node, dist>)
2.1 add target in queue (target, 0)
2.2 iterate queue
2.2.1 mark visited.
2.2.3 add in queue(node->left or right, parent, dist + 1)

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
    int distanceK_searchFromRoot_find_target_dist_and_path(TreeNode* node, TreeNode* target, unordered_set<TreeNode*>& path) {
        if (node == nullptr) return 0;
        
        path.insert(node);
        if (node == target) {
            return 1;
        }
        if (auto dist = distanceK_searchFromRoot_find_target_dist_and_path(node->left, target, path)) {
            return dist + 1;
        }
        if (auto dist = distanceK_searchFromRoot_find_target_dist_and_path(node->right, target, path)) {
            return dist + 1;
        }
        path.erase(node);
        return 0;
    }
    
    void distanceK_searchFromRoot_find_Kdist(TreeNode* node, unordered_set<TreeNode*>& path, int dist, int K, vector<int>& matchedPaths) {
        if (node == nullptr) return;
        if (path.count(node)) {
            dist--;
        }
        else {
            dist++;
        }
        
        if (K == dist) {
            matchedPaths.push_back(node->val);
        }
        
        distanceK_searchFromRoot_find_Kdist(node->left, path, dist, K, matchedPaths);
        distanceK_searchFromRoot_find_Kdist(node->right, path, dist, K, matchedPaths);
    }
    
    vector<int> distanceK_searchFromRoot(TreeNode* root, TreeNode* target, int K) {
        unordered_set<TreeNode*> pathToTarget;
        auto distToTarget = distanceK_searchFromRoot_find_target_dist_and_path(root, target, pathToTarget) - 1;
        
        vector<int> res;
        distanceK_searchFromRoot_find_Kdist(root, pathToTarget, distToTarget + 1, K, res);
        return res;
    }
    
    void buildParent(TreeNode* parent, TreeNode* node, unordered_map<TreeNode*,TreeNode*>& p) {
        if (node == nullptr) return;
        p[node] = parent;
        
        buildParent(node, node->left, p);
        buildParent(node, node->right, p);
    }
    
    void dsf(TreeNode* node, unordered_map<TreeNode*,TreeNode*>& p, int distance, int target, vector<int>& res, unordered_set<TreeNode*>& v) {
        if (node == nullptr || v.count(node)) return;
        v.insert(node);
        if (target == distance) {
            res.push_back(node->val);
            return;
        }
        
        dsf(node->left, p, distance+1, target, res, v);
        dsf(node->right, p, distance+1, target, res, v);
        dsf(p[node], p, distance+1, target, res, v);
    }
    
    vector<int> distanceK_DSF(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,TreeNode*> p;
        buildParent(nullptr, root, p);
        
        vector<int> res;
        unordered_set<TreeNode*> v;
        dsf(target, p, 0, K, res, v);
        return res;
    }
    
    vector<int> distanceK_BSF(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,TreeNode*> p;
        buildParent(nullptr, root, p);
        
        vector<int> res;
        unordered_set<TreeNode*> v;
        queue<pair<TreeNode*, int>> q;
        q.push({target,0});
        
        while (!q.empty()) {
            auto node = q.front().first;
            auto distance = q.front().second;
            q.pop();
            
            if (!node || v.count(node)) continue;
            v.insert(node);
            if (distance == K) {
                res.push_back(node->val);
                continue;
            }
            
            q.push({node->left, distance+1});
            q.push({node->right, distance+1});
            q.push({p[node], distance+1});
        }
        
        return res;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //return distanceK_searchFromRoot(root, target, K);
        //return distanceK_DSF(root, target, K);
        return distanceK_BSF(root, target, K);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int> {3,5,1,6,2,0,8,-777,-777,7,4});
    auto output = vector<int> {7,4,1};
    assert(Solution().distanceK(input1, input1->left, 2)
        == output);

    return 0;
}