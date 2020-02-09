#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
// Solution1. DSF preorder and DP (memoryzation)
// time: o(m*n)
// space: o(m+n) recursion
1. init board row, col (-1)
2. visit all path in DSF preorder. If cur node is final, return 1 otherwise return 0
3. store the number of path for reuse later


//Solution2. Iteration DP
//time: o(m*n)
//space: o(m*n)

dp table m*n
1 1 1
1 1 1
1 1 1

1 1 1
1 2 3
1 3 6

output = path[m-1][n-1]

//Solution2_2. Iteration DP
//time: o(m*n)
//space: o(2m)

use two m vector
1 1 1
1 1 1
1 1 1

1 1 1 pre
1 2 3 cur
1 1 1

1 1 1
1 2 3 pre
1 3 6 cur

1 1 1
1 2 3
1 3 6 pre


//Solution2_3. Iteration DP
//time: o(m*n)
//space: o(m)

use two m vector
1 1 1
1 1 1
1 1 1

1 1 1 
1 2 3 cur
1 1 1

1 1 1
1 2 3 
1 3 6 cur (cur[j] += cur[j-1])

*/

class Solution {
public:
    int recursion(vector<vector<int>> &board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return 0;
        if (r + 1 == board.size() && c + 1 == board[0].size()) return 1;
    
        if (board[r][c] >= 0) return board[r][c];
        auto bottom = recursion(board, r + 1, c);
        auto right = recursion(board, r, c+1);
        board[r][c] = bottom + right;
        return board[r][c];
    }
    
    int uniquePaths_recursion(int m, int n) {
        vector<vector<int>> board(n, vector<int>(m, -1));
        return recursion(board, 0, 0);
    }
    
    int uniquePaths_iteration1(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    int uniquePaths_iteration2(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                cur[c] = pre[c] + cur[c-1];
            }
            swap(pre, cur);
        }
        return pre[n-1];
    }
    
    int uniquePaths_iteration3(int m, int n) {
        vector<int> cur(n, 1);
        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                cur[c] += cur[c-1];
            }
        }
        return cur[n-1];
    }
    
    int uniquePaths(int m, int n) {
        //return uniquePaths_recursion(m,n);
        //return uniquePaths_iteration1(m,n);
        //return uniquePaths_iteration2(m,n);
        return uniquePaths_iteration3(m,n);
    }
};

int main()
{
    assert(Solution().uniquePaths(3,2) == 3);

    return 0;
}