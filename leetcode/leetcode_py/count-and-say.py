"""
https://leetcode.com/problems/count-and-say/
"""

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        elif n == 2:
            return "11"
        
        res = ''
        result = self.countAndSay(n-1)
        pre = ' '
        count = 0
        for c in result:
            if pre == ' ':
                count = 1
            elif pre == c:
                count += 1
            else:
                res += str(count) + pre
                count = 1
            pre = c
        res += str(count) + pre
        
        return res
        