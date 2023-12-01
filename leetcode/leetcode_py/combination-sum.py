'''
https://leetcode.com/problems/combination-sum

Solution1. Backtracking

[2 2 3 7]
0
2: 0 + 2
4: 2, 2 + 2
6: 2, 2, 2 + (pass)
4: 2, 2 + 3
7: 2,2,3 (add)
'''
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def backtracking(sum, start, res):
            if sum == target:
                ans.append(res[:])
                return
            for i in range(start, len(candidates)):
                num = candidates[i]
                if sum + num <= target:
                    res.append(num)
                    backtracking(sum + num, i, res)
                    res.pop()
        backtracking(0, 0, [])
        return ans
        