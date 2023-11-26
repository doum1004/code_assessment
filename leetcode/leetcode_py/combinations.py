'''
https://leetcode.com/problems/combinations

Solution. Backtracking
time: n! / (k! * (n - k)!). The number of combinations is given by this formula: C(n, k)
space: o(k)
'''
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        comb = []
        def backtracking(start):
            if len(comb) == k:
                ans.append(comb[:])
                return
            for i in range(start, n + 1):
                comb.append(i)
                backtracking(i + 1)
                comb.pop()   

        backtracking(1)
        return ans
                
        