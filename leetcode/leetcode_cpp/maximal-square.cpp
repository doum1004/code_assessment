/*
https://leetcode.com/problems/maximal-square

Solution1. recursion + memorization
time: o(nm)
space: o(nm)

Solution2. iteration + tabulation (2d)
time: o(nm)
space: o(nm)

Solution3. iteration + tabulation (1d)
time: o(nm)
space: o(2n)
*/

class Solution {
public:
    int recursion_mem(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i == matrix.size() || j == matrix[0].size()) return 0;
        if (matrix[i][j] == '0') return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int n1 = recursion_mem(matrix, i+1, j, dp);
        int n2 = recursion_mem(matrix, i, j+1, dp);
        int n3 = recursion_mem(matrix, i+1, j+1, dp);
        return dp[i][j] = 1 + min({n1, n2, n3});
    }

    int maximalSquare_1(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int res = 0;
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                res = max(res, recursion_mem(matrix, i, j, dp));
            }
        }
        return pow(res, 2);
    }
    
    int maximalSquare_2(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (i == m-1 || j == n-1 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return pow(res, 2);
    }
    
    int maximalSquare_3(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> pre(n, 0), cur(n, 0);
        int res = 0;
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (i == m-1 || j == n-1 || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                }
                else {
                    cur[j] = min({pre[j+1], pre[j], cur[j+1]}) + 1;
                }
                res = max(res, cur[j]);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pow(res, 2);
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        return maximalSquare_3(matrix);
    }
};