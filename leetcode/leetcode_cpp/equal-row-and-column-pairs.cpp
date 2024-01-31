/*
https://leetcode.com/problems/equal-row-and-column-pairs

1. string lists (row, col) and map (col)
time: o(n^2) n^2 + n + n
space: o(n) 2n + n

2. map with vector
time: o(n^2) n + n(n*logn)
space: o(n) n
*/
class Solution {
public:
    int equalPairs_1(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<string> m1(n);
        vector<string> m2(n);
        // o(n^2)
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                auto s = to_string(grid[i][j]) + " ";
                m1[i] += s;
                m2[j] += s;
                //s1[i] += grid[i][j] + " ";
                //s2[j] += grid[i][j] + " ";
            }
        }
        unordered_map<string, int> m3;
        // o(n)
        for (auto value : m2) {
            m3[value] += 1;
        }
        
        int res = 0;
        // o(n)
        for (auto value : m1) {
            if (m3.count(value))
                res += m3[value];
        }
        return res;
    }

    int equalPairs_2(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int n = grid.size();
        // n
        for (int i=0; i<n; ++i) m[grid[i]] += 1;
        int res = 0;
        // n^2
        for (int j=0; j<n; ++j) {
            vector<int> col(n);
            for (int i=0; i<n; ++i) {
                col[i] = grid[i][j];
            }
            // 
            if (m.count(col)) res += m[col];
        }
        return res;
    }

    int equalPairs(vector<vector<int>>& grid) {
        return equalPairs_2(grid);
    }
};