#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/unique-paths-ii/

//Solution1. Recursion DSF preorder with DP
//time: o(m*n)
//space: o(m+n) recursion

1. visit node by DSF preorder
2. skip path of obstacles (1)
2. store count of path for DP (negative)


//Solution2. Itreation with DP
//time: o(m*n)
//space: o(1)

*/

class Solution {
public:
    int uniquePathsWithObstacles_recursion(vector<vector<int>>& obstacleGrid, int r, int c) {
        if (r < 0 || c < 0 || r >= obstacleGrid.size() || c >= obstacleGrid[0].size()) return 0;
        if (obstacleGrid[r][c] != 0) return (obstacleGrid[r][c] > 0) ? 0 : abs(obstacleGrid[r][c]);
        if (r + 1 == obstacleGrid.size() && c + 1 == obstacleGrid[0].size()) return 1;
        
        auto bottom = uniquePathsWithObstacles_recursion(obstacleGrid, r + 1, c);
        auto right = uniquePathsWithObstacles_recursion(obstacleGrid, r, c+1);
        obstacleGrid[r][c] = (bottom + right == 0) ? 1 : (bottom + right) * -1;
        return bottom + right;
    }
    
    int uniquePathsWithObstacles_iteration(vector<vector<int>>& obstacleGrid) {
        int n_row = obstacleGrid.size();
        int n_col = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(n_row, vector<unsigned int>(n_col, 0));
            
        for (int i=0; i<n_row; ++i) {
            for (int j=0; j<n_col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if (i == 0) dp[i][j] = dp[i][j-1];
                    else if (j == 0) dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n_row-1][n_col-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //return uniquePathsWithObstacles_recursion(obstacleGrid, 0, 0);
        return uniquePathsWithObstacles_iteration(obstacleGrid);
    }
};

int main()
{
    vector<vector<int>> input1 {{0,0,0}, {0,1,0}, {0,0,0}};
    assert(Solution().uniquePathsWithObstacles(input1) == 2);

    return 0;
}