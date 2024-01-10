
'''
https://leetcode.com/problems/reverse-words-in-a-string

Solution1. iterate from begin to end
time: o(n).
space: o(n)

Solution2_1. reverse words with erase
time: o(n)
space: o(1)

1. erase spaces between words
2. reverse words. and add space
3. reverse all string

Solution2_2. reverse words with resize
time: o(n)
space: o(1)

1. skip empty space
2. reverse each word
3. resize string
'''


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

    def reverseWords_1(self, s: str) -> str:
        res = ''
        word = ''
        for i in range(len(s) + 1):
            if i == len(s) or s[i] == ' ':
                if word:
                    res = word + ' ' + res
                word = ''
            else:
                word += s[i]
        return res[:len(res)-1] if res else ''

    def reverseWords_2(self, s: str) -> str:
        s = list(s)
        s = s[::-1]
        l, r, n, lastIdx = 0, 0, len(s), 0
        while r < n:
            while r < n and s[r] == ' ':
                r += 1
            startIdx = l
            while r < n and s[r] != ' ':
                s[l] = s[r]
                l += 1
                r += 1
                lastIdx = l
            
            s = s[:startIdx] + s[startIdx:lastIdx][::-1] + s[lastIdx:]
            if l < n: s[l] = ' '
            l += 1
                
        return "".join(s[:lastIdx])

    def reverseWords(self, s: str) -> str:
        return self.reverseWords_2(s)
        