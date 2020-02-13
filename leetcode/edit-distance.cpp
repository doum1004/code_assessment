#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/edit-distance/

// solution1. dp for edit distance
1. init board with addtional space(1)
2. iterate board.
3. in iteration, if i==0, set j. if j==0, set i.
4. in iteration, if word[i-1] == word[j-1] take dp[i-1][j-1]. otherwise take min amost top, left, top left.

------------
replace add
delete   .
-----------

   '' h o r s e
'' 0  1 2 3 4 5   
r  1  1 2 2 3 4
o  2  2 1 2 3 4 
s  3  3 2 2 2 3 

horse -> ros. 3 operations.
e -> delete
s -> .
r -> delete
o -> .
h -> replace(r)


*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size() + 1, vector<int>(word1.size() + 1, 0));
        
        int row_size = dp.size();
        int col_size = dp[0].size();
        for (int i=0; i<row_size; ++i) {
            for (int j=0; j<col_size; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                }
                else if (j == 0) {
                    dp[i][j] = i;
                }
                else {
                    if (word2[i-1] == word1[j-1]) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[row_size-1][col_size-1];
    }
};

int main()
{
    assert(Solution().minDistance("horse", "ros") == 3);
    assert(Solution().minDistance("intention", "execution") == 5);

    return 0;
}