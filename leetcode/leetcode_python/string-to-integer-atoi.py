"""
https://leetcode.com/problems/string-to-integer-atoi/

#solution. string iteration
#time: o(n)
#space: o(1)

"""

class Solution:
    def myAtoi(self, str: str) -> int:
        n = len(str)
        if (n < 1):
            return 0
        
        MAX_INT = 2**31-1
        MIN_INT = -2**31
        
        expectNum = False
        num = 0
        sign = 1
        
        for c in str:
            if c.isdigit():
                expectNum = True
                d = ord(c) - ord('0')
                if sign == 1 and (num > MAX_INT//10 or (num == MAX_INT//10 and d > 7)):
                    return MAX_INT
                if sign == -1 and (num > MAX_INT//10 or (num == MAX_INT//10 and d > 8)):
                    return MIN_INT
                num = num * 10 + d
            else:
                if expectNum:
                    break
                
                if c.isspace():
                    continue
                elif c == '-' or c == '+':
                    expectNum = True
                    if c == '-':
                        sign = -1
                else:
                    break
            
                
        return int(num) * sign
        