'''
https://leetcode.com/problems/combination-sum-iii

time: o(9^k)
space: o(k)
'''
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def addComb(k, n, begin, comb):
            if k == 0 or n <= 0:
                if k == 0 and n == 0:
                    res.append(comb)
                return

            for i in range(begin, 10):
                addComb(k-1, n-i, i+1, comb + [i])
        addComb(k, n, 1, [])
        return res
        