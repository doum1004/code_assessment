#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/game-of-life/

//Solution1. mn space
//time: o(m*n)
//space: o(m*n)
1. do calculation on copied one

//Solution2. no space
//time: o(m*n)
//space: o(1)
1. get result of board[r][c]
2. if result is diffrent than previous: in case of dead, set(2). in case of live, set(-1)
3. in get deadOrLive sholud consider abs
4. convert 2, -1 to dead, live

//Solution for infinite board. Design Interview!!
in case of infinite, 1. computationally impossible. 2. not be possible to store. 3. data wasting

Scalability aspect of the problem.
case 1, gigantic matrix with few live cells. Entire board is no necessary.
-> save location of lives

Case 2.if board is too big, input is in file.
->Read three lines. pre, cur, next.

*/

class Solution {
public:
    vector<pair<int,int>> offsets = {{1,0}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,1}, {1,-1}};
    bool dealOrLive(vector<vector<int>>& board, int r, int c) {
        int n_r = board.size();
        int n_c = board[0].size();
        
        int cur = abs(board[r][c]);
        int count_live = 0;
        
        for (auto &offset:offsets) {
            auto row = r + offset.first;
            auto col = c + offset.second;
            
            if (row < 0 || col < 0 || row >= n_r || col >= n_c) continue;
            count_live += abs(board[row][col]) == 1 ? 1 : 0;
        }
        
        //cout << r << "," << c << ". " << cur << " :" << count_live << endl;
        if (cur == 1) return (count_live == 2 || count_live == 3);
        return (count_live == 3);
    }
    
    void gameOfLife_mn(vector<vector<int>>& board) {
        if (board.size() < 1 || board[0].size() < 1) return;
        
        int n_r = board.size();
        int n_c = board[0].size();
        vector<vector<int>> b(n_r, vector<int>(n_c));
        for (int r=0; r<n_r; ++r) {
            for (int c=0; c<n_c; ++c) {
                b[r][c] = dealOrLive(board,r,c);
                //cout << r << "," << c << endl;
            }
        }
        board = b;
    }
    
    void gameOfLife_InPlace(vector<vector<int>>& board, int r, int c) {
        auto old = board[r][c];
        auto result = dealOrLive(board,r,c);
        if (!old && result)
            board[r][c] = 2;
        else if (old && !result)
            board[r][c] = -1;
        else
            board[r][c] = (result) ? 1 : 0;
    }
    
    void gameOfLife_InPlace(vector<vector<int>>& board) {
        if (board.size() < 1 || board[0].size() < 1) return;
        
        int n_r = board.size();
        int n_c = board[0].size();

        
        for (int r=0; r<n_r; ++r) {
            for (int c=0; c<n_c; ++c) {
                gameOfLife_InPlace(board,r,c);
            }
        }
        
        for (int r=0; r<n_r; ++r) {
            for (int c=0; c<n_c; ++c) {
                if (board[r][c] == 2)
                    board[r][c] = 1;
                else if (board[r][c] == -1)
                    board[r][c] = 0;
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        //return gameOfLife_mn(board);
        return gameOfLife_InPlace(board);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    auto output1 = vector<vector<int>> {{0,0,0}, {1,0,1}, {0,1,1}, {0,1,0}};
    Solution().gameOfLife(input1);
    assert(input1 == output1);

    return 0;
}