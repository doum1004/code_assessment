'''
https://leetcode.com/problems/maximum-subarray

Solution1. DP
time: o(n)
space: o(n)

Solution2. dp in space
time: o(n)
space: o(1)

Solution3. dp in space. no extra value
time: o(n)
space: o(1)

Solution4. divide and conquer (find the max sum of each and merge)
time: o(n)
space: o(n)
'''
class Solution:
    def maxSubArray_dp(self, nums: List[int]) -> int:
        maxSum = nums[0]
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i-1] + nums[i])
            maxSum = max(maxSum, nums[i])
        return maxSum


    def maxSubArray_divide_conquer(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]

        def dc(nums) -> int:
            if len(nums) == 1:
                return nums[0]

            m = len(nums) // 2
            lmax = dc(nums[:m])
            rmax = dc(nums[m:])
            
            lsum = float(-inf)
            sum = 0
            for i in range(m-1, -1, -1):
                sum += nums[i]
                lsum = max(sum, lsum)
            rsum = float(-inf)
            sum = 0
            for i in range(m, len(nums)):
                sum += nums[i]
                rsum = max(sum, rsum)
            return max(max(lmax, rmax), lsum + rsum)

        return dc(nums)

    def maxSubArray(self, nums: List[int]) -> int:
        return self.maxSubArray_divide_conquer(nums)
        