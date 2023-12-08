/*
https://leetcode.com/problems/course-schedule-ii

Solution1. DFS (hashmap for graph and cache for visit and inner visit)
time: o(n) graph, recursion
space: o(n) graph, visited, recursion
*/
class Solution {
public:
    bool hasCycle(unordered_map<int, vector<int>>& g, unordered_set<int>& v, unordered_set<int>& innerV, int node, vector<int>& res) {
        if (innerV.count(node)) return true;
        if (v.count(node)) return false;
        v.insert(node);
        innerV.insert(node);
        for (auto& adj : g[node]) {
            if (hasCycle(g, v, innerV, adj, res)) return true;
        }
        innerV.erase(node);
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> g;
        for (auto& p:prerequisites)
            g[p[0]].push_back(p[1]);

        unordered_set<int> v;
        vector<int> res;
        for (auto& p:prerequisites) {
            unordered_set<int> innerV;
            if (hasCycle(g, v, innerV, p[0], res)) return {};
        }

        for (int i=0; i<numCourses && res.size() != numCourses; ++i) {
            if (!v.count(i))
                res.push_back(i);
        }

        return res;
    }
};