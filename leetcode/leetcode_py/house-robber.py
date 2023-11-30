'''
https://leetcode.com/problems/house-robber

Solution1. DP top down Recursion with Memorization in place
time: o(n)
space: o(n) recursion + hashmap (memorization)

Solution2. DP bottom down with Tabulation (in place)
time: o(n)
space: o(1)
'''
class Solution:
    def rob_1(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        if n == 1: return nums[0]

        hm = {}
        def recursion(i):
            if i >= n: return 0
            if i in hm: return hm[i]
            hm[i] = nums[i] + max(recursion(i+2), recursion(i+3))
            return hm[i]      
        recursion(0)
        recursion(1)
        return max(hm[0], hm[1])

    def rob_2(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        if n == 1: return nums[0]
        for i in range(n-3,-1,-1):
            if i == n-3:
                nums[i] += nums[i+2]
            else:
                nums[i] += max(nums[i+2], nums[i+3])

        return max(nums[0], nums[1])
        
    def rob(self, nums: List[int]) -> int:
        return self.rob_2(nums)
        