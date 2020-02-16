#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../utils.h"

using namespace std;

/**
https://leetcode.com/problems/design-tic-tac-toe/submissions/

winning conditions
- win matches all in horizontal
- win matches all in vertical
- win matches all in diag
- win matches all in anti diag

player X: 1
player Y: -1

if one of sum equals to n. win player

// Time: o(n) : n(number of moves)
// space: o(n*n) or (n+n) in case of no board

1. create a board n*n vector<vector<int>> board(n, vector<int>(n, 0))
2. and plus create other winning condition to calculate early as possible (rows, cols, diag, anti)
3. in move, mark value 1 or -1. and add val in all variables. and check winning condition

*/


class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    : n_(n)
    , board_(n, vector<int>(n, 0))
    , rows_(n)
    , cols_(n) {
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (board_[row][col] != 0) return 0;
        
        int add = (player == 1) ? 1 : -1;
        board_[row][col] = add;
        
        rows_[row] += add;
        cols_[col] += add;
        if (row == col) diag_ += add;
        if (row+col+1 == n_) anti_diag_ += add;
        
        if (abs(rows_[row]) == n_ || abs(cols_[col]) == n_ || abs(diag_) == n_ || abs(anti_diag_) == n_) return player;
        
        return 0;
    }
private:
    int n_{};
    vector<vector<int>> board_;
    
    // sum
    vector<int> rows_;
    vector<int> cols_;
    int diag_{};
    int anti_diag_{};
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main()
{
    //Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

    auto toe = new TicTacToe(3);

    assert(toe->move(0, 0, 1) == 0); //-> Returns 0 (no one wins)
    // |X| | |
    // | | | |    // Player 1 makes a move at (0, 0).
    // | | | |

    assert(toe->move(0, 2, 2) == 0); //-> Returns 0 (no one wins)
    // |X| |O|
    // | | | |    // Player 2 makes a move at (0, 2).
    // | | | |

    assert(toe->move(2, 2, 1) == 0); //-> Returns 0 (no one wins)
    // |X| |O|
    // | | | |    // Player 1 makes a move at (2, 2).
    // | | |X|

    assert(toe->move(1, 1, 2) == 0); //-> Returns 0 (no one wins)
    // |X| |O|
    // | |O| |    // Player 2 makes a move at (1, 1).
    // | | |X|

    assert(toe->move(2, 0, 1) == 0); //-> Returns 0 (no one wins)
    // |X| |O|
    // | |O| |    // Player 1 makes a move at (2, 0).
    // |X| |X|

    assert(toe->move(1, 0, 2) == 0); //-> Returns 0 (no one wins)
    // |X| |O|
    // |O|O| |    // Player 2 makes a move at (1, 0).
    // |X| |X|

    assert(toe->move(2, 1, 1) == 1); //-> Returns 1 (player 1 wins)
    // |X| |O|
    // |O|O| |    // Player 1 makes a move at (2, 1).
    // |X|X|X|
    delete(toe);
    
    return 0;
}