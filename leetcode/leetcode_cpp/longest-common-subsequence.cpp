/*
https://leetcode.com/problems/longest-common-subsequence

1. Recursion greedy with memorization
time: o(mn)
space: o(mn)

2. Iteration with tabulation (bottom-up)
time : o(mn)
space: o(mn)
*/
class Solution {
public:
    int dfs(string& text1, string& text2, vector<vector<int>>& dp, int i, int j) {
        if (i == text1.size() || j == text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if (text1[i] == text2[j]) {
            res = 1 + dfs(text1, text2, dp, i+1, j+1);
        }
        else {
            res = max(dfs(text1, text2, dp, i+1, j), dfs(text1, text2, dp, i, j+1));
        }
        return dp[i][j] = res;;
    }

    int longestCommonSubsequence_1(string& text1, string& text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, dp, 0, 0);
    }
    
    int longestCommonSubsequence_2(string& text1, string& text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i=text1.size()-1; i>=0; --i) {
            for (int j=text2.size()-1; j>=0; --j) {
                dp[i][j] = text1[i] == text2[j] ? 1 + dp[i+1][j+1] : max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return longestCommonSubsequence_2(text1, text2);
    }
};