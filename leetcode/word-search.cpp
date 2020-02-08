#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/word-search/

// recursion backtrack
// time: o(n * 4^m) n:number of cell in board. m:length of matched word. 4:direction
// space: n(m) length of matched word
// 1. iterate all board to start
// 2. if not matches return false
// 3. if it is matched, mark it as visited and iterate adjacent till the all word matches

int offset[] = {0, 1, 0, -1, 0};
r(board, word, r, c)
    if (r < 0 || r + 1 > board.size() || c < 0 || c + 1 > board[0].size() || word[r][c] != word.substr(0,1)) return false;
    if (word == "") return true;
    
    auto temp = word[r][c];
    word[r][c] = "";
    for (int i = 0; i<4; ++i) {
        if (r(board, word.substr(1), r + offset[i], c + offset[i+1])) return true;
    }
    
    return false;

*/

class Solution {
public:
    int offset[5] = {0, 1, 0, -1, 0};
    bool recursion(vector<vector<char>>& board, string word, int r, int c) {
        if (r < 0 || r + 1 > board.size() || c < 0 || c + 1 > board[0].size() || board[r][c] != word.substr(0,1)[0]) return false;
        auto updatedWord = word.substr(1);
        if (updatedWord == "") return true;

        auto temp = board[r][c];
        board[r][c] = ' ';
        for (int i = 0; i<4; ++i) {
            if (recursion(board, updatedWord, r + offset[i], c + offset[i+1])) return true;
        }
        board[r][c] = temp;

        return false;
    }
    
    bool exist_recursion(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (recursion(board, word, i, j)) return true;
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
    assert(Solution().exist(input1, "SEE") == true);
    assert(Solution().exist(input1, "ABCB") == false);

    return 0;
}