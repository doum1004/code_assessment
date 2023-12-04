'''
https://leetcode.com/problems/jump-game-ii

Solution1. Bottom Up Tabulation.
time: o(n^2)
space: o(n)

     2   3  1   1   4
dp=[-1][-1][-1][-1][0]

Solution2. Linear. Greedy
time: o(n)
space: o(1)
'''
class Solution:
    def jump_1(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        dp[n-1] = 0

        for i in range(n-2, -1, -1):
            if nums[i] == 0:
                continue
            reach = min(n-1, i+nums[i])
            for j in range(i+1, reach+1):
                if dp[j] == -1: continue
                if dp[i] == -1:
                    dp[i] = dp[j] + 1
                else:
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[0]

    def jump_2(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return -1
        
        jump, maxReach, reach = 0, 0, 0
        for i in range(n-1):
            maxReach = max(maxReach, i+nums[i])
            if i == reach:
                jump += 1
                reach = maxReach
        return jump

    def jump(self, nums: List[int]) -> int:
        return self.jump_2(nums)
        