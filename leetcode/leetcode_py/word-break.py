'''
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
'''
class Solution:
    def wordBreak_1(self, s: str, wordDict: List[str]) -> bool:
        hs = set(wordDict)
        dp = {}
        def recursion(start):
            if start == len(s): return True
            if start in dp: return dp[start]

            for i in range(start, len(s)):
                ss = s[start:i+1]
                print(ss)
                if ss in hs and recursion(i+1):
                    dp[start] = True
                    return dp[start]
            dp[start] = False
            return dp[start]
        return recursion(0)
        
    def wordBreak_2(self, s: str, wordDict: List[str]) -> bool:
        hs = set(wordDict)
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True
        for i in range(n-1, -1, -1):
            for j in range(i+1, n+1):
                if not dp[j]: continue
                ss = s[i:j]
                if ss in hs:
                    dp[i] = True
                    break
        return dp[0]

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.wordBreak_2(s, wordDict)
        