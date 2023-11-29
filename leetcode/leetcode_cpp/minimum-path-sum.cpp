/*
https://leetcode.com/problems/minimum-path-sum

1. DP Recursion Memorization
time: o(mn)
space: o(mn)

2. DP topdown with in space
time: o(mn)
space: o(1)

*/
class Solution {
public:
    
    int recursion(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& m) {
        if (r >= grid.size() || c >= grid[r].size()) return -1;
        if (m[r][c] != 0) return m[r][c];
        
        auto v = grid[r][c];
        auto v1 = recursion(grid, r+1, c, m);
        auto v2 = recursion(grid, r, c+1, m);    

        if (v1 != -1 && v2 != -1) v += min(v1, v2);
        else if (v1 == -1 && v2 == -1) v += 0;
        else if (v1 == -1) v += v2;
        else if (v2 == -1) v += v1;

        m[r][c] = v;
        return m[r][c];
    }

    int minPathSum_1(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int n2 = grid[0].size();
        vector<vector<int>> m(n, vector<int>(n2, 0));
        recursion(grid, 0, 0, m);
        return m[0][0];
    }

    int minPathSum_2(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        for (int i=n-1; i>=0; --i) {
            for (int j=m-1; j>=0; --j) {
                if (i == n-1 && j != m-1) grid[i][j] += grid[i][j+1];
                else if (i != n-1 && j == m-1) grid[i][j] += grid[i+1][j];
                else if (i != n-1 && j != m-1) grid[i][j] += min(grid[i][j+1], grid[i+1][j]);
            }
        }
        return grid[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum_2(grid);
    }
};
