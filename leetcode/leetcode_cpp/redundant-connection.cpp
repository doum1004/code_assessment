/**

Solution1. DFS
time: o(n^2)
space: o(n) recursion, map

Solution2. union-find (disjoint set)
https://www.youtube.com/watch?v=ID00PMy0-vE
https://www.youtube.com/watch?v=wU6udHRIkcc
time: o(n)
space: o(n)


*/

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& g, unordered_set<int>& seen, int u, int v) {
        if (!seen.count(u)) {
            seen.insert(u);
            if (u == v) return true;
            for (auto &n:g[u]) if (dfs(g,seen,n,v)) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection_dfs(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        for (auto &e:edges) {
            auto u=e[0],v=e[1];
            unordered_set<int> seen;
            if (g.count(u) && g.count(v) && dfs(g,seen,u,v)) return {u,v};
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return {};
    }
    
    vector<int> findRedundantConnection_unionfind(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1, 0);
        for (auto &e:edges) {
            auto u=e[0],v=e[1];
            while (parent[u]) u = parent[u];
            while (parent[v]) v = parent[v];
            if (u == v) return e;
            parent[u] = v;
        }
        return {};
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //return findRedundantConnection_dfs(edges);
        return findRedundantConnection_unionfind(edges);
    }
};
