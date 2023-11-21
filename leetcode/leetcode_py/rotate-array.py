'''
https://leetcode.com/problems/rotate-array

Soltuion1. Brute force
time: o(n*k)
space: o(1)

Solution2. Vector
time: o(n)
space: o(n)

Solution3. Reverse. Math
time: o(n)
space: o(1)
'''
class Solution:
    def rotate_2(self, nums: List[int], k: int) -> None:
        numsSize = len(nums)
        if numsSize < 2:
            return
        k %= numsSize
        res = [0] * numsSize
        for i in range(numsSize):
            n = i + k
            if n >= numsSize:
                n -= numsSize
            res[n] = nums[i]
        for i in range(numsSize):
            nums[i] = res[i]
                    
    def rotate_3(self, nums: List[int], k: int) -> None:
        numsSize = len(nums)
        if numsSize < 2:
            return
        k %= numsSize

        def reverse(l, r):
            while (l < r):
                temp = nums[l]
                nums[l] = nums[r]
                nums[r] = temp
                l += 1
                r -= 1
        reverse(0, numsSize - k - 1)
        reverse(numsSize - k, numsSize - 1)
        reverse(0, numsSize - 1)
        
    def rotate(self, nums: List[int], k: int) -> None:
        self.rotate_2(nums, k)
        
        