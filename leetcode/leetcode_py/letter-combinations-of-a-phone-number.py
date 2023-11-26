'''
Soltuion1. Backtracking
time: o(4^N) each digit, the algorithm explores all possible combinations
space: o(4^N) depth of the recursion
'''

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        m = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}

        res = []
        def backtracking(i, s):
            if i >= len(digits):
                if s:
                    res.append(s)
                return
            for c in m[digits[i]]:
                backtracking(i+1, s + c)

        backtracking(0, "")
        return res
        