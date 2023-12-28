/*
https://leetcode.com/problems/n-queens-ii

Solution: Backtracking (DFS)
https://leetcode.com/problems/n-queens-ii/solutions/2111695/c-n-queens-variation/?envType=study-plan-v2&envId=top-interview-150
time: o(n!)
spalce: o(n^2)

Solution2. TODO
time: o(n!)
space: o(n)

*/
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> b(n, vector<bool>(n, false));
        return solve(b, 0);
    }

    int solve(vector<vector<bool>>& b, int row) {
        if (row >= b.size()) return 1;
        
        int cnt = 0;
        for (int col=0; col<b.size(); ++col) {
            if (isSafe(b, row, col)) {
                b[row][col] = true;
                cnt += solve(b, row+1);
                b[row][col] = false;
            }
        }
        return cnt;
    }

    bool isSafe(vector<vector<bool>>& b, int row, int col) {
        for (int i=0; i<=row; ++i) {
            if (b[i][col]) return false;
            if (row-i >= 0 && col-i >= 0 && b[row-i][col-i]) return false;
            if (row-i >= 0 && col+i < b.size() && b[row-i][col+i]) return false;
        }
        return true;
    }
};