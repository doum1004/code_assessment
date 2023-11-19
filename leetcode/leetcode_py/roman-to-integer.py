"""
https://leetcode.com/problems/roman-to-integer/
"""

class Solution:
    def romanToInt_1(self, s: str) -> int:
        nums = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ]
        symboles = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" ]
        
        res = 0
        for i in range(len(symboles)):
            l = len(symboles[i])
            while symboles[i] in s[:l]:
                res += nums[i]
                s = s[l:]
        return res
    
    def romanToInt_2(self, s: str) -> int:
        sToi = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        
        s = s.replace('IV', 'IIII').replace('IX', 'VIIII')
        s = s.replace('XL', 'XXXX').replace('XC', 'LXXXX')
        s = s.replace('CD', 'CCCC').replace('CM', 'DCCCC')
        
        res = 0
        for c in s:
            res += sToi[c]
        return res
        
    def romanToInt_3(self, s: str) -> int:
        m = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = 0
        for i in range(len(s)):
            if i + 1 < len(s) and m[s[i]] < m[s[i+1]]:
                res -= m[s[i]]
            else:
                res += m[s[i]]
            
        return res

    def romanToInt(self, s: str) -> int:
        #return self.romanToInt_1(s)
        return self.romanToInt_3(s)