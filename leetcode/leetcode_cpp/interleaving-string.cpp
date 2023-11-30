/*
https://leetcode.com/problems/interleaving-string

solution1. dp memorization
time: o(m+n) before 2^(m+2)
space: o(m+n)

solution2. dp tabulation (TODO)

*/
class Solution {
public:
    bool recursive(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp) {
        if (i == s1.size() && j == s2.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        if (!ans && i<s1.size() && s1[i] == s3[i+j])
            ans = recursive(s1, s2, s3, i+1, j, dp);
        if (!ans && j<s2.size() && s2[j] == s3[i+j])
            ans = recursive(s1, s2, s3, i, j+1, dp);
        dp[i][j] = ans;
        return ans;
    }

    bool isInterleave_1(string& s1, string& s2, string& s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return recursive(s1, s2, s3, 0, 0, dp);
    }

    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave_1(s1, s2, s3);
    }
};