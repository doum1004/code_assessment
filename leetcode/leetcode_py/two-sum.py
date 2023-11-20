from typing import List

"""
https://leetcode.com/problems/two-sum/

Solution1 brute force solution in two loop

Solution2 hash to store value and find the solution in hash (target-nums[i])
time: o(n)
space: o(n)


"""
class Solution:
    def twoSum_hash(self, nums: List[int], target: int) -> List[int]:
        ans = {}
        for i, n in enumerate(nums):
            if n in ans:
                return [ans[n], i]
            ans[target - n] = i
        return -1
        
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return self.twoSum_hash(nums, target)
        