'''
https://leetcode.com/problems/product-of-array-except-self

Solution1. store left/right product
time: o(n) : n + n + n
space: o(n) : n + n (no for ans)
// 1  2  3 4
// 1  1  2 3 lp
// 24 12 4 1 rp
//
// [1] 2 3 4 sum[0] = lp[0] * rp[0]
// 1 [2] 3 4 sum[1] = lp[1] * rp[2]
// 1 2 [3] 4
// 1 2 3 [4]
// iterate 0 to n-1 to store left side product result
// iterate n-1 to 0 to sotre right side product result

solution2. combine lp and rp to ans
time: o(n)
space: o(1)
// same for lp for ans. and product ans to make it answer from right side.
// r = 1
// i=n-1 to 0
//  ans[i] = ans[i] * r
//  r *= ans[i]
'''
class Solution:
    def productExceptSelf_1(self, nums: List[int]) -> List[int]:
        n = len(nums)
        lp = [1] * n
        rp = [1] * n
        for i in range(1, n):
            lp[i] = lp[i-1] * nums[i-1]
            
        ans = [0] * n
        for i in range(n-1, -1, -1):
            if i < n-1:
                rp[i] = rp[i+1] * nums[i+1]
            ans[i] = lp[i] * rp[i]
        return ans
    def productExceptSelf_2(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [1] * n
        for i in range(1, n):
            ans[i] = ans[i-1] * nums[i-1]

        rp = 1
        for i in range(n-2, -1, -1):
            rp *= nums[i+1]
            ans[i] *= rp
        return ans

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return self.productExceptSelf_2(nums)

        