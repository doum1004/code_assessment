"""
https://leetcode.com/problems/happy-number/

"""

class Solution:
    def nextNum(self, n):
        sum = 0
        while n:
            d = n % 10
            sum += d ** 2
            n //= 10
        return sum
        
    def isHappy_hash(self, n: int) -> bool:
        h = {}
        while n != 1:
            if n in h:
                return False
            h[n] = True
            n = self.nextNum(n)
            
        return True
        
    def isHappy_fastslow(self, n: int) -> bool:
        flag = False
        slow, fast = n, n
        while fast != 1:
            fast = self.nextNum(fast)
            if flag:
                slow = self.nextNum(slow)
            if slow == fast:
                return False
            flag = not flag
        
        return True
            
    
    def isHappy(self, n: int) -> bool:
        #return self.isHappy_hash(n)
        return self.isHappy_fastslow(n)