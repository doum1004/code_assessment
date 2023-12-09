'''
https://leetcode.com/problems/generate-parentheses

Solution1. Recursion
time: o(n)
space: o(n) depth
1. In recursion (give count of open and close, accumulated string)
1.1. Add accumulated string into answer list
1.2. if open < n: add open and call recursion. pop open
1.3. if open > close and close < n: add close and call recursion. pop open
'''
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def buildParenthesis(open, close, s):
            if n == open and n == close:
                res.append(s)
                return
            if open != n:
                buildParenthesis(open+1, close, s+"(")
            if close != n and open > close:
                buildParenthesis(open, close+1, s+")")
        buildParenthesis(0, 0, "")
        return res
        