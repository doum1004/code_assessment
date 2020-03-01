#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
    
/**
https://leetcode.com/problems/word-search/

// backtracking (which mark the current path of exploration) recursion DSF preorder
// time: o(n*4^m) : iterate all board * 4(directions) ^ m(matched words)
// space: o(m) : which only recursion call when it matches

1. iterate all board to call 'bool recursion(board, word, i, j)'
2. in recursion check board[i][j] == ' ' || board[i][j] == word.substr(0,1) return false;
2.1 nweword = word.substr(1). if newword == '' return true
2.2 make board[i][j] = ' ';
2.3 check all directions with new word in recursion call. and return if it return true
2.4 if nothing, make roll back board[i][j]
2.5 and return false;

// ... complecated in iteration DSF especially backtracking I think
// But let's try later... when you have a time

*/

class Solution {
public:
    int offset[5] = {0, 1, 0, -1, 0};
    
    bool exist_recursion(vector<vector<char>>& board, string &word, int s, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[s]) return false;
        
        if (s == word.size() - 1) return true;
        
        auto t = board[i][j];
        board[i][j] = ' ';
        for (int k=0; k<4; ++k) {
            if (exist_recursion(board, word, s+1, i+offset[k], j+offset[k+1])) return true;
        }
        board[i][j] = t;
        
        return false;
    }
    
    bool exist_recursion(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (exist_recursion(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        return exist_recursion(board, word);
    }
};

int main()
{
    auto input1 = vector<vector<char>> {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    assert(Solution().exist(input1, "ABCCED") == true);
    auto input2 = vector<vector<char>> {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    assert(Solution().exist(input2, "SEE") == true);
    auto input3 = vector<vector<char>> {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    assert(Solution().exist(input3, "ABCB") == false);

    return 0;
}