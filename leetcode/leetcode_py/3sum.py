'''
https://leetcode.com/problems/3sum

Solution1. Sliding window (two pointers)
time: o(n^2) nlogn + n^2(i*(l,r))
spcae: o(1) answer(n)

1. sort to avoid duplication
2. iterate nums and try to find target(-nums[i]) from two pointers in nums[l] and nums[r]. l++ r--
3. Add it in res if find, and try to move till non duplications (l,r)
4. move i to skip duplication
'''

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3: return []

        nums.sort()
        res = []
        for i in range(n-2):
            if i > 0 and nums[i] == nums[i-1]: continue

            target = -nums[i]
            l = i+1
            r = n-1
            while l < r:
                sum = nums[l] + nums[r]
                if target < sum:
                    r -= 1
                elif target > sum:
                    l += 1
                else:
                    res.append([nums[i],nums[l],nums[r]])
                    numL = nums[l]
                    numR = nums[r]
                    while l < r and nums[l] == numL: l += 1
                    while l < r and nums[r] == numR: r -= 1
        return res
    
print(Solution().threeSum([-1,0,1,2,-1,-4]))