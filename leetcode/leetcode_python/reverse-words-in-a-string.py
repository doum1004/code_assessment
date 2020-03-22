"""
https://leetcode.com/problems/reverse-words-in-a-string/
"""

class Solution:
    def reverseWords_builtin1(self, s: str) -> str:
        res = ''
        for item in s.split():
            res = item + ' ' + res
        return res[:-1]
    
    def reverseWords_builtin2(self, s: str) -> str:
        return " ".join(s.strip().split()[::-1])
    
    def reverseWords_iterate(self, s: str) -> str:
        res, substr = '', ''
        for c in s:
            if c.isspace():
                if substr: res = substr + ' '+ res
                substr = ''
            else:
                substr += c
        if substr: res = substr + ' '+ res
        if res: res = res[:-1]
        return res
        
    def reverseWords(self, s: str) -> str:
        #return self.reverseWords_builtin(s)
        #return self.reverseWords_builtin2(s)
        return self.reverseWords_iterate(s)