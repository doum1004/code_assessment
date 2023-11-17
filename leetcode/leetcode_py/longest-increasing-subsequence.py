from typing import List

"""
https://leetcode.com/problems/word-ladder-ii/
"""

class Solution:
    def lengthOfLIS_recursion(self, nums: List[int]) -> int:
        t = [[-1 for i in range(len(nums))] for i in range(len(nums) + 1)]
        def recursion(pre,cur):
            if (cur == len(nums)): return 0
            if t[pre+1][cur] > -1:
                return t[pre+1][cur]
            
            count_a, count_b = 0, 0
            if (pre == -1 or nums[pre] < nums[cur]):
                count_a = 1 + recursion(cur, cur+1)
            count_b = recursion(pre, cur+1)
            t[pre+1][cur] = max(count_a, count_b)
            return t[pre+1][cur]
        return recursion(-1,0)
        
    def lengthOfLIS_dp(self, nums: List[int]) -> int:
        dp = [1 for i in range(len(nums))]
        res = 0
        for i in range(len(nums)-1,-1,-1):
            dp[i] = 1
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], 1+dp[j])
            res = max(res, dp[i])
        return res
    
    def lengthOfLIS_dp_nlogn(self, nums: List[int]) -> int:
        dp = []
        for i in range(len(nums)):
            if len(dp) > 0 and dp[-1] >= nums[i]:
                it = bisect.bisect_left(dp, nums[i])
                dp[it] = nums[i]
            else:
                dp.append(nums[i])
            
        return len(dp)
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        #return self.lengthOfLIS_recursion(nums)
        #return self.lengthOfLIS_dp(nums)
        return self.lengthOfLIS_dp_nlogn(nums)