/*
https://leetcode.com/problems/valid-sudoku

Solutions1. Brute force with hash map or array
time: o(n)
space: o(n) r + c + board

*/

class Solution {
public:
    bool isValidSudoku_1(vector<vector<char>>& board) {
        unordered_set<char> hor[9];
        unordered_set<char> ver[9];
        unordered_set<char> sqr[3][3];
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                auto c = board[i][j];
                if (c != '.') {
                    if (hor[j].count(c) || ver[i].count(c) || sqr[i/3][j/3].count(c)) return false;
                    hor[j].insert(c);
                    ver[i].insert(c);
                    sqr[i/3][j/3].insert(c);
                }
            }
        }
        return true;
    }
    bool isValidSudoku_2(vector<vector<char>>& board) {
        bool hor[9][9] = {0};
        bool ver[9][9] = {0};
        bool sqr[9][9] = {0};
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                auto c = board[i][j];
                if (c != '.') {
                    int num = c - '0' - 1;
                    int k = i/3*3 + j/3;
                    if (hor[j][num] || ver[i][num] || sqr[k][num]) return false;
                    hor[j][num] = true;
                    ver[i][num] = true;
                    sqr[k][num] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudoku_2(board);
    }
};
