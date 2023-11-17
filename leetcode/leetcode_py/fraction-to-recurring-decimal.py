"""
https://leetcode.com/problems/fraction-to-recurring-decimal/
"""

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        if numerator == denominator: return "1"
        
        res = ''
        if (numerator < 0) ^ (denominator < 0):
            res += '-'
        
        n = abs(numerator)
        d = abs(denominator)
        res += str(n // d)
        if n % d == 0:
            return res
        
        h = {}
        
        res += "."
        n %= d
        while n:
            n *= 10
            if n in h:
                i = h[n]
                res = res[:i] + "(" + res[i:] + ")"
                break
            h[n] = len(res)
            res += str(n//d)
            n %= d
        
        return res