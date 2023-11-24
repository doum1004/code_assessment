/*
https://leetcode.com/problems/surrounded-regions

Solution1. DFS. Mark Visit and check it is surrounded well
time: o(n) n + n
space: o(n) n + n

1. iterate board
2. In loop, skip if node is not 'O' ('x' or 'v')
3. In dfs, return false if it exceeds boudnary. return true if 'x' or 'y'. mark 'V' and visit all adjacent nodes.
4. if dfs pass. trun 'v' to 'x'
5. loop again convert 'v' to 'o'

Solution2. DFS. In place. Mark all edge connections '#' and convert 'O' to 'X' '#' to 'O'
time: o(n) n + n
space: o(n) n

1. iterate row edges and call bsf to mark mark '#'
2. same for col edges
3. iterate all board, convert 'o' to 'x' and convert '#' to 'o'

*/
class Solution {
public:
    bool dfs_1(vector<vector<char>>& board, int row, int col, vector<pair<int,int>>& v) {
        int n1 = board.size();
        int n2 = board[0].size();
        if (row < 0 || col < 0 || row >= n1 || col >= n2) return false;
        if (board[row][col] == 'X' || board[row][col] == 'V') return true;

        board[row][col] = 'V';
        v.push_back({row, col});
        auto result1 = dfs_1(board, row-1, col, v);
        auto result2 = dfs_1(board, row+1, col, v);
        auto result3 = dfs_1(board, row, col-1, v);
        auto result4 = dfs_1(board, row, col+1, v);
        return result1 && result2 && result3 && result4;
    }
    void solve_1(vector<vector<char>>& board) {
        int n1 = board.size();
        if (n1 == 0) return;
        int n2 = board[0].size();
        if (n2 == 0) return;

        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                if (board[i][j] != 'O') continue;

                vector<pair<int,int>> v;
                auto result = dfs_1(board, i, j, v);
                if (result) {
                    for (auto values : v) {
                        board[values.first][values.second] = 'X';
                    }
                }
            }
        }
        
        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                if (board[i][j] == 'V')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs_2(vector<vector<char>>& board, int row, int col) {
        int n1 = board.size();
        int n2 = board[0].size();
        if (row < 0 || col < 0 || row >= n1 || col >= n2 || board[row][col] != 'O') return;
        board[row][col] = '#';
        dfs_2(board, row+1, col);
        dfs_2(board, row-1, col);
        dfs_2(board, row, col+1);
        dfs_2(board, row, col-1);
    }

    void solve_2(vector<vector<char>>& board) {
        int n1 = board.size();
        if (n1 == 0) return;
        int n2 = board[0].size();
        if (n2 == 0) return;

        for (int i=0; i<n1; ++i) {
            if (board[i][0] == 'O')
                dfs_2(board, i, 0);
            if (board[i][n2-1] == 'O')
                dfs_2(board, i, n2-1);
        }
        for (int j=0; j<n2; ++j) {
            if (board[0][j] == 'O')
                dfs_2(board, 0, j);
            if (board[n1-1][j] == 'O')
                dfs_2(board, n1-1, j);
        }
        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        return solve_2(board);
    }
};