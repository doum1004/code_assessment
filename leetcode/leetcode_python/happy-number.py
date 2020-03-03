"""
https://leetcode.com/problems/happy-number/

"""

class Solution:
    def nextNum(self, n):
        s = 0
        while n:
            digit = n % 10
            s += digit * digit
            n = n // 10
        return s
    
    def isHappy_set(self, n: int) -> bool:
        if n == 1:
            return True
        
        h = {}
        while (True):
            s = self.nextNum(n)
            if s == 1:
                return True
            if s in h:
                return False
            n = s
            h[s] = 1
            
        return False
    
    def isHappy_twopointers(self, n: int) -> bool:
        if n == 1:
            return True
        
        slow,fast = n,n
        flag = False
        while (True):
            fast = self.nextNum(fast)
            if flag:
                slow = self.nextNum(slow)
            flag = not flag
            
            if fast == 1 or slow == 1:
                return True
            if fast == slow:
                return False
            
        return False
        
    def isHappy(self, n: int) -> bool:
        #return self.isHappy_set(n)
        return self.isHappy_twopointers(n)
        
        