#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/edit-distance/
edit distance
https://www.youtube.com/watch?v=We3YDTzNXEk
https://www.youtube.com/watch?v=MiqoA-yF-0M

// Solution1. edit distance
// time: o(n*m)
// space: o(n*m)
1. init board for dp
2. set i==0 || j==0 as i,j value
ex)
0 1 2 3 4
1 0 0 0 0
2 0 0 0 0
3. iterate from i(1), j(1) to end
4. board[i][j] = (word1[i+1] == word2[j+1]) ? board[i-1][j-1] : min(board[i-1][j-1], board[i-1][j], board[i][j-1])

replace insert
delete  ...

    h o r s e
  0 1 2 3 4 5
r 1 1 2 2 3 4
o 2 2 1 2 3 4
s 3 3 2 2 2 3 

e -> delete
s -> do nothing
r -> delete
o -> do nothing
h -> replace

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n_word1 = word1.size();
        int n_word2 = word2.size();
        
        // init board
        vector<vector<int>> board(n_word1+1, vector<int>(n_word2+1));
        for (int r=0; r<=n_word1; ++r) {
            board[r][0] = r;
        }
        for (int c=0; c<=n_word2; ++c) {
            board[0][c] = c;
        }
        
        for (int r=1; r<=n_word1; ++r) {
            for (int c=1; c<=n_word2; ++c) {
                if (word1[r-1] == word2[c-1]) board[r][c] = board[r-1][c-1];
                else board[r][c] = min(min(board[r-1][c-1], board[r-1][c]), board[r][c-1]) + 1;
            }
        }
        
        return board[n_word1][n_word2];
    }
};

int main()
{
    assert(Solution().minDistance("horse", "ros") == 3);
    assert(Solution().minDistance("intention", "execution") == 5);

    return 0;
}