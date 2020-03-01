#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/unique-paths/

// Solution1. recursion DSF preorder with memorization
// time: o(m*n) : visiting node(m*n)
// space: o(m*n) : m*n(board) + m*n(recursion)

1. create a board (m*n) vector<vector<int>> init(-1)
2. recursion call. int recursion(board, 0, 0)
3. in recursion, check input validation. invalid: return 0
4. check it is in dp and return dp value or if it reaches end and return 1
5. check bottom, right path and get result
6. and save it in bp
7. return total count of left, right


// Solution2. iteration DP (full board)
// time: o(m*n)
// space: o(m*n)
1. create a full board (init 1)
2. iterate all after first row and col
3. update board. board[i][j] = board[i-1][j] + board[i][j-1]
1 1 1 1
1 2 3 4           
1 3 6 10

// Soluiton3. iteration dp two vector
// time: o(m*n)
// space: o(2*n)
1. create two vectors with init(1)
2. iterate after first row and col, cur[i] = cur[i-1] + pre[i]
3. swap cur and pre

1 1 1 1 pre
1 2 3 4 cur
. . . .

1 1 1 1 
1 2 3 4 pre
1 3 6 10 cur

1 1 1 1 
1 2 3 4 cur
1 3 6 10 pre

// Soluiton4. iteration dp one vector
// time: o(m*n)
// space: o(n)
1. create a vector init (0)
2. iterate from second row and col
3. cur[i] += cur[i-1]

1 1 1 1 cur
. . . .
. . . .

1 1 1 1 
1 2 3 4 cur
. . . .

1 1 1 1 
1 2 3 4 
1 3 6 10 cur

*/


class Solution {
public:
    int uniquePaths_recursion(vector<vector<int>> &board, int m, int n) {
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size()) return 0;
        if (board[m][n] > -1) return board[m][n];
        if (m == board.size()-1 && n == board[0].size()-1) return 1;
        
        auto bottom = uniquePaths_recursion(board, m, n+1);
        auto right = uniquePaths_recursion(board, m+1, n);
        board[m][n] = bottom+right;
        
        return bottom + right;
    }
    
    int uniquePaths_recursion(int m, int n) {
        vector<vector<int>> board(m, vector<int>(n, -1));
        return uniquePaths_recursion(board, 0, 0);
    }
    
    int uniquePaths_iteration_dp_fullvector(int m, int n) {
        vector<vector<int>> board(m, vector<int>(n, 1));
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }
        
        return board[m-1][n-1];
    }
    
    int uniquePaths_iteration_dp_twovector(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                cur[j] = cur[j-1] + pre[j];
            }
            swap(cur, pre);
        }
        
        return pre[n-1];
    }
    
    int uniquePaths_iteration_dp_onevector(int m, int n) {
        vector<int> cur(n, 1);
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                cur[j] += cur[j-1];
            }
        }
        return cur[n-1];
    }
    
    int uniquePaths(int m, int n) {
        //return uniquePaths_recursion(m, n);
        //return uniquePaths_iteration_dp_fullvector(m, n);
        //return uniquePaths_iteration_dp_twovector(m, n);
        return uniquePaths_iteration_dp_onevector(m, n);
    }
};

int main()
{
    assert(Solution().uniquePaths(3,2) == 3);

    return 0;
}