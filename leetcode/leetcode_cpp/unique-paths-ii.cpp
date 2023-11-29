#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/unique-paths-ii/

// solution1. recursion with memorization
// time: o(n)
// space: o(n) recursion
1. iterate board to set 0 as -1 and set 1 as 0
2. call int recursion(board, 0, 0)
3. check range validation
4. check dp(if it hits >= 0) then return
5. if it hits end return 1
6. check bottom, right in recursion and save it
7. return total

// solution2. iteation with dp
// time: o(n)
// space: o(n) for unsigned int
1. init dp
2. iterate board
2.1 if node gets 1 then save as 0
2.2 if i==0 && j==0 up to board
2.3 if i==0 || j==0 up to previous dp node
2.4 otherwise dp[][] = dp[-1][] + dp[][-1]

*/

class Solution {
public:
    int uniquePathsWithObstacles_recursion(vector<vector<int>>& obstacleGrid, int m, int n) {
        if (m < 0 || n < 0 || m >= obstacleGrid.size() || n >= obstacleGrid[0].size()) return 0;
        if (obstacleGrid[m][n] > -1) return obstacleGrid[m][n];
        if (m == obstacleGrid.size() - 1 && n == obstacleGrid[0].size() - 1) return 1;
        
        auto adjacent1 = uniquePathsWithObstacles_recursion(obstacleGrid, m+1, n);
        auto adjacent2 = uniquePathsWithObstacles_recursion(obstacleGrid, m, n+1);
        obstacleGrid[m][n] = adjacent1+adjacent2;
        return obstacleGrid[m][n];
    }
    
    int uniquePathsWithObstacles_recursion(vector<vector<int>>& obstacleGrid) {
        for (int i=0; i<obstacleGrid.size(); ++i) {
            for (int j=0; j<obstacleGrid[0].size(); ++j) {
                obstacleGrid[i][j] = obstacleGrid[i][j] == 0 ? -1 : 0;
            }
        }
        return uniquePathsWithObstacles_recursion(obstacleGrid, 0, 0);
    }
    
    int uniquePathsWithObstacles_iteration(vector<vector<int>>& obstacleGrid) {
        int size1 = obstacleGrid.size();
        int size2 = obstacleGrid[0].size();
        for (int i=0; i<size1; ++i) {
            for (int j=0; j<size2; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                }
                else if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) {
                        obstacleGrid[i][j] = 1;
                    }
                    else if (i==0) {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    }
                    else if (j==0) {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    }
                }
                else {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        
        return obstacleGrid[size1-1][size2-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //return uniquePathsWithObstacles_recursion(obstacleGrid);
        return uniquePathsWithObstacles_iteration(obstacleGrid);
    }
};

int main()
{
    vector<vector<int>> input1 {{0,0,0}, {0,1,0}, {0,0,0}};
    assert(Solution().uniquePathsWithObstacles(input1) == 2);

    return 0;
}