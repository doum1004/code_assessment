'''
https://leetcode.com/problems/max-number-of-k-sum-pairs

Solution1. Sort and two pointers
time: o(nlogn) nlogn + n
space: o(1)

Solution2. Map
time: o(n)
space: o(n)
'''
class Solution:
    def maxOperations_1(self, nums: List[int], k: int) -> int:
        nums.sort()
        l, r = 0, len(nums)-1
        res = 0
        while l < r:
            sum = nums[l] + nums[r]
            if sum == k:
                res += 1
                l += 1
                r -= 1
            elif sum < k:
                l += 1
            else:
                r -= 1
        return res

    def maxOperations_2(self, nums: List[int], k: int) -> int:
        m = defaultdict(int)
        res = 0
        for num in nums:
            target = k - num
            if m[target]:
                res += 1
                m[target] -= 1
            else:
                m[num] += 1
        return res
        
    def maxOperations(self, nums: List[int], k: int) -> int:
        return self.maxOperations_2(nums, k)
        