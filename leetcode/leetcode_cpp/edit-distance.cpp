#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/edit-distance

Solution1. dp for edit distance (2 dimensions)
https://www.youtube.com/watch?v=We3YDTzNXEk
time: o(mn)
space: o(mn)
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

Solution2. dp with 1 dimension
time: o(mn)
space: o(n)

*/

class Solution {
public:
    int minDistance_1(string word1, string word2) {
        if (!word1.size() || !word2.size()) return max(word1.size(), word2.size());
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));
        
        for (int i=0; i<dp.size(); ++i)
            dp[i][0] = i;

        for (int j=0; j<dp[0].size(); ++j)
            dp[0][j] = j;

        for (int i=1; i<dp.size(); ++i) {
            for (int j=1; j<dp[0].size(); ++j) {
                if (word2[i-1] == word1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }

    int minDistance_2(string word1, string word2) {
        if (!word1.size() || !word2.size()) return max(word1.size(), word2.size());
        vector<int> dp(word1.size()+1, 0);
        
        for (int i=0; i<dp.size(); ++i)
            dp[i] = i;

        for (int i=1; i<word2.size()+1; ++i) {
            int pre = 0;
            dp[0] = 0;
            for (int j=1; j<word1.size()+1; ++j) {
                int temp = dp[j];
                if (word2[i-1] == word1[j-1])
                    dp[j] = pre;
                else
                    dp[j] = min({dp[j-1], dp[j], pre}) + 1;
                pre = temp;
            }
        }
        return dp[dp.size()-1];
    }
    
    int minDistance(string word1, string word2) {
        return minDistance_2(word1, word2);
    }
};

int main()
{
    assert(Solution().minDistance("horse", "ros") == 3);
    assert(Solution().minDistance("intention", "execution") == 5);

    return 0;
}