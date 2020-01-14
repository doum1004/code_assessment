#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/design-tic-tac-toe/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    : n_(n)
    , rows_(n)
    , cols_(n)
    , diag_(0)
    , anti_diag_(0) {
        
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
        auto add = (player == 1) ? 1 : -1;
        rows_[row] += add;
        cols_[col] += add;
        diag_ += row == col ? add : 0;
        anti_diag_ += row == n_ - col - 1 ? add : 0;
        if (abs(rows_[row]) == n_ || abs(cols_[col]) == n_ || abs(diag_) == n_ || abs(anti_diag_) == n_)
            return player;

        return 0;
    }

private:
    vector<int> rows_;
    vector<int> cols_;
    int diag_;
    int anti_diag_;
    int n_;
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