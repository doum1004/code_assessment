/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

1. DFS (add count it passes exist connection)
- Make bi-dirational (correct: +, added: -)
- DFS visit node to count all positive adj node. Skip visited node not to visit again
time: o(n)
space: o(n)
*/
class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& g, vector<bool>& v, int i) {
        v[i] = true;
        int res = 0;
        for (auto next : g[i]) {
            if (v[abs(next)]) continue;
            if (next > 0) res += 1;     
            res += dfs(g, v, abs(next));
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> g;
        for (auto& c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(-c[0]);
        }
        
        vector<bool> v(n, false);
        return dfs(g, v, 0);
    }
};