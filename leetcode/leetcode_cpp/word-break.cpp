#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../utils.h"

using namespace std;

/*
https://leetcode.com/problems/word-break

1. dp memorization (top down)
time: o(N^3) recursion(N^2) * substr(N)
space: o(N^2)

2. dp tabulation (bottom up)
time: o(N^3) recursion(N^2) * substr(N)
space: o(n) n + n

3. Trie
time: o(n^2). n^2(dp) + t(trie)
space: o(n). n(dp) + t(trie)

*/
class Solution {
public:
    bool recursion(const string& s, const unordered_set<string>& hs, vector<int>& dp, int start) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];
        for (int i=start; i<s.size(); ++i) {
            auto ss = s.substr(start, i+1-start);
            if (hs.count(ss) && recursion(s, hs, dp, i+1)) {
                return dp[start] = true;
            }                
        }
        return dp[start] = false;
    }

    bool wordBreak_1(string s, vector<string>& wordDict) {
        unordered_set<string> hs(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return recursion(s, hs, dp, 0);
    }
    bool wordBreak_2(string s, vector<string>& wordDict) {
        unordered_set<string> hs(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i=n-1; i>=0; --i) {
            for (int j=i+1; j<=n; ++j) {                
                if (!dp[j]) continue;
                auto ss = s.substr(i, j-i);
                if (hs.count(ss)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreak_2(s, wordDict);
    }
};

int main()
{
    auto input1_1 = vector<string> {"leet", "code"};
    assert(Solution().wordBreak(
        "leetcode", input1_1
    ) == (true));
    return 0;
}
