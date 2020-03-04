"""
https://leetcode.com/problems/fraction-to-recurring-decimal/
"""

class Solution:
    def fractionToDecimal_division(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return '0'
        if denominator == 0:
            raise Exception('invalid input')
        
        res = ''
        if (numerator < 0) ^ (denominator < 0):
            res += '-'
        
        n = abs(numerator)
        d = abs(denominator)
        res += str(n//d)
        r = n % d
        if r == 0:
            return res
        
        res += '.'
        m = {}
        while r:
            if r in m:
                res = res[:m[r]] + '(' + res[m[r]:]
                res += ')'
                break
            m[r] = len(res)
            r *= 10
            res += str(r//d)
            r %= d
        
        return res
        
        
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        return self.fractionToDecimal_division(numerator, denominator)
        