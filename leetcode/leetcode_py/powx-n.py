'''
https://leetcode.com/problems/powx-n

Solution1. Recursion. o(n)/o(n)
Solution2. Iteration. o(n)/o(1)
Soluiton3. Recursion. Every 2 in n. o(logn) / o(logn)
Soluiton4. Iteration. Every 2 in n. o(logn) / o(1)
'''
class Solution:
    def myPow_1(self, x: float, n: int) -> float:
        if n == 0: return 1
        def recursive(x, n):
            if x == 0:
                return 1
            return x * recursive(x, n-1)
        negative = n < 0
        n = abs(n)
        res = recursive(x, n)
        if negative:
            res = 1 / res
        return res
            
    def myPow_2(self, x: float, n: int) -> float:
        if n == 0: return 1
        res = 1
        negative = n < 0
        n = abs(n)
        while n:
            res *= x
            n -= 1
        if negative:
            res = 1 / res
        return res

    def myPow_3(self, x: float, n: int) -> float:
        if n == 0: return 1
        negative = n < 0
        if negative:
            n = abs(n)
            x = 1 / x
            
        if n % 2 == 0:
            return self.myPow_3(x * x, n // 2)
        else:
            return x * self.myPow_3(x, n - 1)

    def myPow_4(self, x: float, n: int) -> float:
        negative = n < 0
        n = abs(n)

        res = 1
        while n > 0:
            if n % 2 == 0:
                x *= x
                n //= 2
            else:
                res *= x
                n -= 1

        if negative:
            res = 1 / res
        return res
        

    def myPow(self, x: float, n: int) -> float:
        return self.myPow_4(x, n)
        