'''
https://leetcode.com/problems/counting-bits

1. Bit manipulation
time: o(n)
space: o(1) n:answer
res[i] = res[i >> 1] + (i & 1)
ex) 
0: 0
1: 0 + 1 = 1
2: 1(1) + 0 = 1
3: 1(1) + 1 = 2
4: 1(2) + 0 = 1
5: 1(2) + 1 = 2
6: 2(3) + 0 = 2
7: 2(3) + 1 = 3
8: 1(4) + 0 = 1
9: 1(4) + 1 = 2
'''
class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0] * (n+1)
        for i in range(1, n+1):
            res[i] = res[i >> 1] + (i & 1)
        return res
        