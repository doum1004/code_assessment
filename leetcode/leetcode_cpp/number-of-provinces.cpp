/*
https://leetcode.com/problems/number-of-provinces

1. DFS
time: o(n)
space: o(n)

2. UnionFind
https://www.youtube.com/watch?v=ayW5B2W9hfo
time: o(logn)
space: o(b)
*/
class Solution {
public:
    bool notVisited(vector<vector<int>>& isConnected, vector<int>& seen, int i) {
        if (seen[i]) return false;
        seen[i] = true;
        for (int j=0; j<isConnected[i].size(); ++j) {
            if (isConnected[i][j])
                notVisited(isConnected, seen, j);
        }
        return true;
    }
    
    int findCircleNum_1(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<int> seen(n, 0);
        for (int i=0; i<n; ++i) {
            if (notVisited(isConnected, seen, i))
                res += 1;
        }
        return res;
    }
    
    int find(int i, vector<int>& g) {
        if (g[i] == i) return i;
        return g[i] = find(g[i], g);
    }

    void union_g(int i, int j, vector<int>& g) {
        i = find(i, g);
        j = find(j, g);
        if (i != j)
            g[j] = i;
    }

    int findCircleNum_2(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> g(n);
        for (int i=0; i<n; ++i)
            g[i] = i;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (isConnected[i][j] == 1)
                    union_g(i, j, g);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (g[i] == i) res += 1;
        }
        return res;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        return findCircleNum_1(isConnected);
    }
};