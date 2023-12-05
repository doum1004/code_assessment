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
        
    def reverseWords_1(self, s: str) -> str:
        res, word = '', ''
        for i, c in enumerate(s):
            if c != ' ':
                word += c           
            elif word:
                if res: res = word + " " + res
                else: res = word
                word = ''     
        if word:            
            if res: res = word + " " + res
            else: res = word

        return res

    def reverseWords_3(self, s: str) -> str:
        s = s[::-1]
        print(s)
        n = len(s)
        i, l, r = 0, 0, 0
        while i < n:
            while i < n and s[i] != ' ':
                s = s[:r] + s[i] + s[r+1:]
                r += 1
                i += 1
            
            if l < r:
                s = s[:l] + s[l:r][::-1] + ' ' + s[r+1:]
                r += 1
                l = r
            i += 1
        
        while r > 0 and s[r-1] == ' ': r -= 1
        return s[:r]

    def reverseWords(self, s: str) -> str:
        #return self.reverseWords_builtin(s)
        #return self.reverseWords_builtin2(s)
        return self.reverseWords_iterate(s)