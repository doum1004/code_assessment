'''
https://leetcode.com/problems/minimum-size-subarray-sum

Solutions1. slinding window
time: o(n)
space: o(1)

Solutions2. binary search
time: o(nlogn)
space: o(1)

2 3 1 2 4 3 (7)

0 2 5 6 8 12 15

1 4 4 (4)

9 1 2 3 4 5 (10)

0 10 11 13 16 20 25

'''
class Solution:
    def minSubArrayLen_1(self, target: int, nums: List[int]) -> int:
        l = 0
        r = 0
        sum = 0
        res = float(inf)
        while (r<len(nums)):
            sum += nums[r]
            while sum >= target:
                res = min(res, r-l+1)
                sum -= nums[l]
                l += 1
            r += 1
        return 0 if res == float(inf) else res
        
    def minSubArrayLen_2(self, target: int, nums: List[int]) -> int:
        def upper_bound(arr, value):
            l = 0
            r = len(arr)
            while l < r:
                m = l + (r - l) // 2
                if arr[m] <= value:
                    l = m + 1
                else:
                    r = m
            return r
            
        n = len(nums)
        sums = [0] * (n + 1)
        for i in range(1, n+1):
            sums[i] = sums[i-1] + nums[i-1]

        res = float(inf)
        for r in range(n, 0, -1):
            if sums[r] < target:
                break
            l = upper_bound(sums, sums[r] - target)
            res = min(res, r - l + 1)
            
        return 0 if res == float(inf) else res
        
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        return self.minSubArrayLen_2(target, nums)
        
        