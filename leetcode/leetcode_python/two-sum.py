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
        h = {}
        for i in range(len(nums)):
            complement = target-nums[i]
            if complement in h:
                return h[complement], i
            h[nums[i]] = i
        
        return -1
        
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return self.twoSum_hash(nums, target)
        