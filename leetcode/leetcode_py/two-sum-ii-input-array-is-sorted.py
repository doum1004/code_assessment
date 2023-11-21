'''
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

Solutions1. Extra space for finding answer. using map
time: o(n)
space: o(n)

Solutions2. two pointers
time: o(n)
space: o(1)
'''
class Solution:
    def twoSum_1(self, numbers: List[int], target: int) -> List[int]:
        m = {}
        for i, n in enumerate(numbers):
            if n in m:
                return [m[n] + 1, i + 1]
            m[target - n] = i
        return []
    
    def twoSum_2(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while l < r:
            sum = numbers[l] + numbers[r]
            if sum == target:
                return [l + 1, r + 1]
            if sum > target:
                r -= 1
            else:
                l += 1
        return []

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        return self.twoSum_2(numbers, target)
        