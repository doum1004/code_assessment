from typing import List

"""
https://leetcode.com/problems/multiply-strings/
"""

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1,n2 = len(num1),len(num2)
        s = [0 for i in range(n1*n2+1)]
        
        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                result = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                p = n1 - i - 1 + n2 - j - 1
                s[p] += result
                if s[p] > 9:
                    s[p+1] += s[p] // 10
                    s[p] %= 10
                    
        res = ''
        b = False
        for c in s[::-1]:
            if not b and c == 0: continue
            b = True
            res += str(c)
        return '0' if not res else res
        